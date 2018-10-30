#include "shapewidget.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix;
    // 第三个参数表示读取读片的方式，此时设置为避免图片抖动方式
    pix.load("16.png", 0, Qt::AvoidDither | Qt::ThresholdDither | Qt::ThresholdAlphaDither);
    // 调整窗体大小为图片大小
    resize(pix.size());
    // 为窗体增加一个遮罩，遮住所选区域以外的部分使之看起来是透明的，
    // 参数可以是QBitmap或QRegion对象，此png图片的透明部分实际上是一个遮罩
    setMask(QBitmap(pix.mask()));
}

void ShapeWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if (event->button() == Qt::RightButton)
        close();
}

void ShapeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void ShapeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("16.png"));
}

ShapeWidget::~ShapeWidget()
{

}
