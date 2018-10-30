#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>
class Dialog;

class TimeServer : public QTcpServer
{
    Q_OBJECT
public:
    TimeServer(QObject *parent = 0);
protected:
    // 这个函数在TCP服务器端有新的连接时被调用
    void incomingConnection(int socketDescriptor);
private:
    Dialog *dlg;
};

#endif // TIMESERVER_H
