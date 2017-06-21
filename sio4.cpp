#include "sio4.h"

//Constructor

SiO4::SiO4()
{
    //Inicia el servidor local
    server->listen(QHostAddress("127.0.0.1"), 1996);
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
    QProcess::startDetached(crystals);
    //QProcess::startDetached(QApplication::applicationDirPath() + "/../Crystals/Crystals");
}

//Reajusta la resolucion de la pantalla
void SiO4::resolutionChanged()
{
    QRect size = QApplication::desktop()->geometry();
    setGeometry(size);
    foreach (Socket *client, sockets)
    {
       client->sendMessage("CHANGERESOLUTION",QString::number(size.width()) + "," + QString::number(size.height()));
    }
}

//Una nueva app se conecto
void SiO4::newConnection()
{
    Socket *socket = (Socket*)server->nextPendingConnection();
    connect(socket,SIGNAL(newMessage(QString,QString)),this,SLOT(newMessage(QString,QString)));
    sockets.append(socket);
}

//Nuevo mensaje de alguna app
void SiO4::newMessage(QString name, QString data)
{
    if(name == "RELAUNCHCRYSTALS")

        QProcess::startDetached(QApplication::applicationDirPath() + "/../Crystals/Crystals");

}

//Destructor

SiO4::~SiO4()
{

}
