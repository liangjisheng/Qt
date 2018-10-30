#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <stdio.h>

const int DataSize = 1000;
const int BufferSize = 80;
int buffer[BufferSize];

QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes(0);

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
        // acquire(int n = 1);获取n个资源，当没有足够的资源时，调用者将被阻塞直到有足够的可用资源
        freeBytes.acquire();
        buffer[i % BufferSize] = (i % BufferSize);
        // release(int n = 1); 将可用资源加1，表示消费者此时可以读取这个刚刚填写的单元了
        usedBytes.release();
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
    for (int i = 0; i < DataSize; i++)
    {
        usedBytes.acquire();

        fprintf(stderr, "%d ", buffer[i % BufferSize]);
        if (i % 16 == 0 && i != 0)
            fprintf(stderr, "\n");

        freeBytes.release();
    }
    fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;

    producer.start();
    consumer.start();

    producer.wait();
    consumer.wait();

    return a.exec();
}
