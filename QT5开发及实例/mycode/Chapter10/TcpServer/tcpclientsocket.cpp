#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *)
{
    connect(this, readyRead, this, dataReceived);
    connect(this, disconnected, this, slotDisconnected);
}

void TcpClientSocket::dataReceived()
{
    while (bytesAvailable() > 0)
    {
        int length = bytesAvailable();
        char buf[1024] = { 0 };
        read(buf, length);
        QString msg = buf;
        emit updateClients(msg, length);
    }
}

void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
