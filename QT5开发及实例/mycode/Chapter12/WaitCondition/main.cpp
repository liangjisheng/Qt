#include <QCoreApplication>
// QWaitCondition类，允许线程在一定条件下唤醒其他线程
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <stdio.h>

const int DataSize = 1000;
const int BufferSize = 80;
int buffer[BufferSize];

QWaitCondition bufferEmpty;
QWaitCondition bufferFull;

QMutex mutex;
int numUsedBytes = 0;   // 表示已经用了多少字节
// 启动两个消费者线程，这两个线程读取同一个缓冲区，为了不重复读取，设置全局变量rIndex
// 用于指示当前所读缓冲区位置
int rIndex = 0;

class Producer : public QThread
{
public:
    Producer() {}
    void run();
};

void Producer::run()
{
    for (int i = 0; i < DataSize; i++)
    {
        mutex.lock();

        // 如果缓冲区被填满，则等待缓冲区有空位,(bufferEmpyt)条件成立.
        // wait()函数将互斥量解锁并在此等待
        if (numUsedBytes == BufferSize)
            bufferEmpty.wait(&mutex);

        buffer[i % BufferSize] = numUsedBytes;
        ++numUsedBytes;

        // 唤醒等待"缓冲区有可用数据"(bufferEmpty变量)条件为true的线程
        bufferFull.wakeAll();

        mutex.unlock();
    }
}

class Consumer : public QThread
{
public:
    Consumer() {}
    void run();
};

void Consumer::run()
{
    forever
    {
        mutex.lock();
        if (0 == numUsedBytes)
            bufferFull.wait(&mutex);

        printf("%ul::[%d] = %d\n", currentThreadId(), rIndex, buffer[rIndex]);
        rIndex = (++rIndex) % BufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumerA;
    Consumer consumerB;

    producer.start();
    consumerA.start();
    consumerB.start();

    producer.wait();
    consumerA.wait();
    consumerB.wait();

    return a.exec();
}
