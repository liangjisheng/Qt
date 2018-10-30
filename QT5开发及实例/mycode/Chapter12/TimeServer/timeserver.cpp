#include "timeserver.h"
#include "timethread.h"
#include "dialog.h"

TimeServer::TimeServer(QObject *parent)
    :QTcpServer(parent)
{
    dlg = (Dialog*)parent;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
    TimeThread *thread = new TimeThread(socketDescriptor);

    // 这个信号是夸线程的，使用了排队连接方式，用于显示请求计数
    connect(thread, &TimeThread::finished, dlg, &Dialog::slotShow);
    // 这个信号是在同一个线程中的，使用了直接连接方式，可以省略最后一个参数而
    // 使用Qt的自动连接选择方式
    // 由于工作线程中存在网络事件，所以不能被外界线程销毁，这里使用了延迟销毁函数deleteLater()
    // 保证由工作线程自身销毁
    connect(thread, &TimeThread::finished, thread, deleteLater, Qt::DirectConnection);

    thread->start();
}
