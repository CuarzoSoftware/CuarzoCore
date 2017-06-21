#ifndef SOCKET_H
#define SOCKET_H

#include "includes.h"

class Socket : public QTcpSocket
{
    Q_OBJECT
public:
    Socket();

public slots:
    void messageEvent();
    void sendMessage(QString name, QString data);

signals:
    void newMessage(QString name, QString data);
};

#endif // SOCKET_H
