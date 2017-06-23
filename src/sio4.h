#ifndef SiO4_H
#define SiO4_H

#include "includes.h"

class SiO4 : public QLabel
{
    Q_OBJECT

public:
    SiO4();
    ~SiO4();
    QLocalServer *server = new QLocalServer(this);
    QList<QLocalSocket*> sockets;
    QProcess *crystalsProcess = new QProcess(this);
    void startUI();

public slots:
    void resolutionChanged();
    void newConnection();
    void sendMessage(QLocalSocket *socket,QString name, QString data);
};

#endif // SiO4_H
