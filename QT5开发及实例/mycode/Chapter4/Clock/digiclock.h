#ifndef DIGICLOCK_H
#define DIGICLOCK_H

// 该类中重定义了鼠标按下事件和鼠标移动事件以使电子时钟可随意拖拽，
// 同时还定义了相关的槽函数和私有变量

#include <QLCDNumber>
#include <QMouseEvent>
#include <QPoint>

class DigiClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigiClock(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
public slots:
    void showTime();        // 显示当前时间
private:
    QPoint dragPosition;    // 保存鼠标点相对于电子时钟窗体左上角的偏移值
    bool showColon;         // 用户保存显示时间时是否显示:,控制两个点的闪显功能
};

#endif // DIGICLOCK_H
