#include "workthread.h"
#include <QtDebug>

WorkThread::WorkThread()
{

}

void WorkThread::run()
{
    // 为了显示效果明显，将一个数字重复打印8次
    while (true)
    {
        // Qt提供的qDebug()输出是一个原子操作，意思是在输出某个i的时候
        // 其他的线程在输出i的时候不会抢占控制台，而printf()或者cout
        // 在多线程输出时抢占控制台
        for (int i = 0; i < 10; i++)
        {
            qDebug() << i << i << i << i << i << i << i << i;
            sleep(1);
        }
    }
}
