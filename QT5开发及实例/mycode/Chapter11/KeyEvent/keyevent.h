#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QWidget>
#include <QKeyEvent>
#include <QPaintEvent>

class KeyEvent : public QWidget
{
    Q_OBJECT

public:
    KeyEvent(QWidget *parent = 0);
    ~KeyEvent();

    void drawPix();
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);
private:
    QPixmap *pix;       // 作为一个绘图设备，使用双缓冲机制实现图形的绘制
    QImage image;       // 界面中间的小图标
    int startX, startY; // 图标左上顶点的位置
    int width, height;  // 界面的宽度和高度
    int step;           // 网格的大小，即移动的步进值
};

#endif // KEYEVENT_H
