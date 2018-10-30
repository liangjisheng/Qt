#include "server.h"

Server::Server(QObject *parent, int port)
    :QTcpServer(parent)
{
    // 在指定端口对任意地址进行监听
    listen(QHostAddress::Any, port);
}

// 当出现一个新连接时，QTcpServer触发incomingConnection，
// 参数socketDescriptor指定了连接的Socket描述符
void Server::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);
    connect(tcpClientSocket, &TcpClientSocket::updateClients,
            this, updateClients);
    connect(tcpClientSocket, &TcpClientSocket::disconnected,
            this, slotDisconnected);

    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    tcpClientSocketList.append(tcpClientSocket);;
}

// 将任意客户端发来的信息进行广播，保证聊天室的所有人均能看到其他人的发言
void Server::updateClients(QString msg, int length)
{
    emit updateServer(msg, length);
    for (int i = 0; i < tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if (item->write(msg.toLatin1(), length) != length)
            continue;
    }
}

// 从tcpClientSocketList列表中将断开连接的TcpClientSocket对象删除的功能
void Server::slotDisconnected(int descriptor)
{
    for (int i = 0; i < tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if (item->socketDescriptor() == descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return ;
        }
    }
}
