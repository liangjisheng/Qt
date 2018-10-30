#include "udpclient.h"
#include <QMessageBox>
#include <QtNetwork/QHostAddress>

UdpClient::UdpClient(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setWindowTitle(tr("UDP Client"));

    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"), this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);

    connect(CloseBtn, &QPushButton::clicked, this, CloseBtnClicked);
    port = 5555;
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, &QUdpSocket::readyRead, this, dataReceived);

    bool result = udpSocket->bind(port);
    if (!result)
    {
        QMessageBox::information(this, tr("error"), tr("udp socket create error!"));
        return;
    }
}

void UdpClient::CloseBtnClicked()
{
    close();
}

void UdpClient::dataReceived()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString msg = datagram.data();
        ReceiveTextEdit->insertPlainText(msg);
    }
}

UdpClient::~UdpClient()
{

}
