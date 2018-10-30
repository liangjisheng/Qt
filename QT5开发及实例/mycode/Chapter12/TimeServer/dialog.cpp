#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "timeserver.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("多线程时间服务器"));

    Label1 = new QLabel(tr("服务器端口: "));
    Label2 = new QLabel;

    quitBtn = new QPushButton(tr("退出"));
    QHBoxLayout *BtnLayout = new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(quitBtn);
    BtnLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(Label1);
    mainLayout->addWidget(Label2);
    mainLayout->addLayout(BtnLayout);

    connect(quitBtn, &QPushButton::clicked, this, close);

    // 启动服务器端的网络监听
    count = 0;
    timeServer = new TimeServer(this);
    if (!timeServer->listen())
    {
        QMessageBox::critical(this, tr("多线程时间服务器"),
                              tr("无法启动服务器: %1").arg(timeServer->errorString()));
        close();
        return;
    }

    Label1->setText(tr("服务器端口: %1").arg(timeServer->serverPort()));
}

void Dialog::slotShow()
{
    // 槽函数虽然被多个线程激活，但调用入口只有主线程的事件循环这一个。
    // 多个线程的激活信号最终会在主线程的事件循环中排队调用此槽函数，
    // 从而保证了count变量的互斥访问，因此槽函数slotShow是一个天然的临界区
    Label2->setText(tr("第%1次请求完毕.").arg(++count));
}

Dialog::~Dialog()
{

}
