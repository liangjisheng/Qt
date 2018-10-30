#include "timethread.h"
#include <QDateTime>
#include <QByteArray>
#include <QDataStream>

TimeThread::TimeThread(int socketDescriptor, QObject *parent)
    :QThread(parent)
{
    this->socketDescriptor = socketDescriptor;
}

void TimeThread::run()
{
    QTcpSocket tcpSocket;
    if (!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        emit error(tcpSocket.error());
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);

    // 转换成unix时间，以秒计算
    uint time2u = QDateTime::currentDateTime().toTime_t();
    out << time2u;

    // 将获得的当前时间传回客户端
    tcpSocket.write(block);
    // 断开连接
    tcpSocket.disconnectFromHost();
    // 等待返回
    tcpSocket.waitForDisconnected();
}
