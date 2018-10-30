#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QtNetwork>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpClientSocket(QObject *parent = 0);
signals:
    void updateClients(QString, int);   // 通知服务器向聊天室内的所有成员广播信息
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // TCPCLIENTSOCKET_H
