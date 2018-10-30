#include "udpserver.h"
#include <QtNetwork/QHostAddress>

UdpServer::UdpServer(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setWindowTitle(tr("UDP Server"));

    TimerLabel = new QLabel(tr("计时器:"), this);
    TextLineEdit = new QLineEdit(this);
    StartBtn = new QPushButton(tr("开始"), this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);

    connect(StartBtn, &QPushButton::clicked, this, StartBtnClicked);
    port = 5555;
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);
    // 定时发送广播信息
    connect(timer, &QTimer::timeout, this, timeout);
}

void UdpServer::StartBtnClicked()
{
    if (!isStarted)
    {
        StartBtn->setText(tr("停止"));
        timer->start(1000);
        isStarted = true;
    }
    else
    {
        StartBtn->setText(tr("开始"));
        isStarted = false;
        timer->stop();
    }
}

// 此函数完成了向端口发送广播信息的功能
void UdpServer::timeout()
{
    QString msg = TextLineEdit->text();
    int length = 0;
    if ("" == msg)
        return;

    // 指定向广播地址发送
    length = udpSocket->writeDatagram(msg.toLatin1(),
                                      msg.length(),
                                      QHostAddress::Broadcast,
                                      port);
    if (length != msg.length())
        return ;
}

UdpServer::~UdpServer()
{

}
