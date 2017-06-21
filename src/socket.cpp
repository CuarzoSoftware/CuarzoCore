#include "socket.h"

Socket::Socket()
{
    connect(this,SIGNAL(readyRead()),this,SLOT(messageEvent()));
}

void Socket::messageEvent()
{

    QString fullMessage = QString::fromUtf8(readAll());
    QString key = fullMessage.mid(0,16);
    if(key != "CUARZOSOFTWARE16")
        return;


    QString name = fullMessage.mid(16,32).replace("%","");
    QString data = fullMessage.mid(48,128).replace("%","");

    newMessage(name,data);

}

void Socket::sendMessage(QString name, QString data)
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
    write(message.toUtf8());
}
