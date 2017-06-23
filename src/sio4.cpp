#include "sio4.h"

//Constructor

SiO4::SiO4()
{
    //Inicia el servidor local
    QLocalServer::removeServer("CuarzoServer");
    server->listen("CuarzoServer");
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    //Usar pantalla completa
    connect(QApplication::desktop(),SIGNAL(resized(int)),this,SLOT(resolutionChanged()));
    resolutionChanged();

    //Escala correctamente el wallpaper
    setScaledContents(true);

    //Asigna la imagen del wallpaper
    //Donde "wallpaper" es la variable definida en "Includes"
    setPixmap(QPixmap(wallpaper));

    //Muestra el fondo en pantalla ( Podriamos añadir una animación más adelante )
    show();

    //Inicia los componentes
    startUI();
}

//Inicia los demás componentes gráficos

void SiO4::startUI()
{
    //Inicia Compton ( Display Manager )
    //Donde "compositor" es la variable declarada en "Includes"
    QProcess::startDetached(compositor);

    //Inicia Crystals ( Window Manager )
    //Donde "crystals" es la variable declarada en "Includes".
    crystalsProcess->setProgram(crystals);
    crystalsProcess->start();

    //Inicia terminal ( Testeo )
    QProcess::startDetached("gnome-terminal");
}

//Reajusta la resolucion de la pantalla
void SiO4::resolutionChanged()
{
    QRect size = QApplication::desktop()->geometry();
    setGeometry(size);
    foreach (QLocalSocket *client, sockets)
    {
       sendMessage(client,"CHANGERESOLUTION",QString::number(size.width()) + "," + QString::number(size.height()));
    }
}

//Una nueva app se conecto
void SiO4::newConnection()
{
    QLocalSocket *socket = server->nextPendingConnection();

    //Lee los mensajes del cliente
    connect(socket,&QLocalSocket::readyRead,this,[socket,this](){

        //Obtiene el mensaje

        QString fullMessage = QString::fromUtf8(socket->readAll());
        QString key = fullMessage.mid(0,16);

        //Filtra el mensaje

        if(key != "CUARZOSOFTWARE16")
            return;

        //Limpia los mensajes

        QString name = fullMessage.mid(16,32).replace("%","");
        QString data = fullMessage.mid(48,128).replace("%","");

        //Reinicia Crystals

        if(name == "RELAUNCHCRYSTALS")
        {
            crystalsProcess->close();
            crystalsProcess->start();
        }

    });

    sockets.append(socket);
}


//Envia un mensaje

void SiO4::sendMessage(QLocalSocket *socket,QString name, QString data)
{
    // ESTRUCTURA DEL MENSAJE ( NO USAR % )
    // 16 bytes -> Llave Secreta
    // 32 bytes -> Nombre del Mensaje
    // 128 bytes -> Informacion

    while(name.length()<32)
        name.append("%");

    while(data.length()<128)
        data.append("%");

    QString message = "CUARZOSOFTWARE16" + name + data;
    socket->write(message.toUtf8());
}


//Destructor

SiO4::~SiO4()
{

}
