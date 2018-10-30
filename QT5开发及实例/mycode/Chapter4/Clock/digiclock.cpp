#include "digiclock.h"
#include <QTimer>
#include <QTime>
#include <QPalette>
#include <QString>

DigiClock::DigiClock(QWidget *parent)
    :QLCDNumber(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::blue);
    setPalette(p);

    // 设置窗体的标识，此处设置窗体为一个没有面板边框和标题栏的窗体
    setWindowFlags(Qt::FramelessWindowHint);
    // 设置窗体的透明度为0.5,即半透明
    setWindowOpacity(0.5);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, showTime);
    timer->start(1000);     // 以1000毫秒为周期启动定时器
    showTime();             // 初始时间显示
    resize(150, 60);
    showColon = true;
}

void DigiClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if (showColon)
    {
        text[2] = ':';
        showColon = false;
    }
    else
    {
        text[2] = ' ';
        showColon = true;
    }
    display(text);
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // dragPosition保存鼠标当前点的位置相对于窗体左上角的偏移值
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    // 按下鼠标右键，退出窗体
    if (event->button() == Qt::RightButton)
        close();
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        // 由于move函数的参数指的是窗体左上角的位置，所有要使用鼠标当前点的位置减去
        // 相对于窗体左上角的偏移值dragPosition
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
