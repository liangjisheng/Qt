#include "mouseevent.h"

MouseEvent::MouseEvent(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("鼠标事件"));

    statusLabel = new QLabel;
    statusLabel->setText(tr("当前位置:"));
    statusLabel->setFixedWidth(100);

    MousePosLabel = new QLabel;
    MousePosLabel->setText(tr(""));
    MousePosLabel->setFixedWidth(100);

    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(MousePosLabel);

    setMouseTracking(true);
    resize(400, 200);
}

void MouseEvent::mousePressEvent(QMouseEvent *e)
{
    // x(),y()可以获得鼠标相对于接收事件的窗体位置
    // globalX(),globalY()可以获得鼠标相对窗口系统的位置
    QString str = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";

    // QMouseEvent的button()可以获得发生鼠标事件按键属性(左键，右键，中键)
    if (e->button() == Qt::LeftButton)
        statusBar()->showMessage(tr("左键: ") + str);
    else if (e->button() == Qt::RightButton)
        statusBar()->showMessage(tr("右键: ") + str);
    else if (e->button() == Qt::MidButton)
        statusBar()->showMessage(tr("中键: ") + str);
}

void MouseEvent::mouseMoveEvent(QMouseEvent *e)
{
    QString str = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
    MousePosLabel->setText(str);
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *e)
{
    QString str = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
    statusBar()->showMessage(tr("释放在: ") + str, 3000);
}

// 没有自定义实现，但仍要写出来
void MouseEvent::mouseDoubleClickEvent(QMouseEvent *e)
{

}

MouseEvent::~MouseEvent()
{

}
