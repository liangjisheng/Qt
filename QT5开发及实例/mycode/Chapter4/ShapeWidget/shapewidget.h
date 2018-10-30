#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>

class ShapeWidget : public QWidget
{
    Q_OBJECT

public:
    ShapeWidget(QWidget *parent = 0);
    ~ShapeWidget();
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
private:
    QPoint dragPosition;    // 鼠标单击点相对于窗体左上角的偏移
};

#endif // SHAPEWIDGET_H
