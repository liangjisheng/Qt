#include "threaddlg.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

ThreadDlg::ThreadDlg(QWidget *parent)
    : QDialog(parent)
{
    startBtn = new QPushButton(tr("开始"));
    stopBtn = new QPushButton(tr("停止"));
    quitBtn = new QPushButton(tr("退出"));
    threadNumLabel = new QLabel(tr("线程数: "));
    threadNumLineEdit = new QLineEdit;
    threadNumLineEdit->setText(QString::number(1));

    QHBoxLayout *upLayout = new QHBoxLayout;
    upLayout->addWidget(threadNumLabel);
    upLayout->addWidget(threadNumLineEdit);

    QHBoxLayout *downLayout = new QHBoxLayout;
    downLayout->addWidget(startBtn);
    downLayout->addWidget(stopBtn);
    downLayout->addWidget(quitBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(upLayout);
    mainLayout->addLayout(downLayout);

    connect(startBtn, &QPushButton::clicked, this, slotStart);
    connect(stopBtn, &QPushButton::clicked, this, slotStop);
    connect(quitBtn, &QPushButton::clicked, this, close);
}

void ThreadDlg::slotStart()
{
    thread_num = threadNumLineEdit->text().toInt();
    workThread = new WorkThread*[thread_num];

    // 使用2个for循环是为了使创建的线程尽可能的同时开始执行
    for (int i = 0; i < thread_num; i++)
        workThread[i] = new WorkThread();
    for (int i = 0; i < thread_num; i++)
        workThread[i]->start();     // start()会调用run(), 使得线程开始真正运行

    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);
}

void ThreadDlg::slotStop()
{
    for (int i = 0; i < thread_num; i++)
    {
        // 调用父类的terminate(),但是这个函数并不会立即终止这个线程，该线程
        // 何时终止取决于操作系统的调度策略。
        workThread[i]->terminate();
        // 紧接着调用wait()，使得线程阻塞等待知道退出或超时
        workThread[i]->wait();
    }

    startBtn->setEnabled(true);
    stopBtn->setEnabled(false);

    for (int i = 0; i < thread_num; i++)
        delete workThread[i];
    delete []workThread;
    workThread = NULL;
}

ThreadDlg::~ThreadDlg()
{

}
