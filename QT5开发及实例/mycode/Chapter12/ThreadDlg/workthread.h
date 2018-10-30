#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>

class WorkThread : public QThread
{
public:
    WorkThread();
protected:
    void run();     // 重写run()
};

#endif // WORKTHREAD_H
