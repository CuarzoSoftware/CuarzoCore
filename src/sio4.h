#ifndef SiO4_H
#define SiO4_H

#include "includes.h"
#include "socket.h"

class SiO4 : public QLabel
{
    Q_OBJECT

public:
    SiO4();
    ~SiO4();
    QTcpServer *server = new QTcpServer(this);
    QList<Socket*> sockets;
    void startUI();

public slots:
    void resolutionChanged();
    void newConnection();
    void newMessage(QString,QString);
};

#endif // SiO4_H
