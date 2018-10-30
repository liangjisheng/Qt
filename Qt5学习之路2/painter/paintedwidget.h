#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>
#include <QPaintEvent>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    PaintedWidget(QWidget* parent = 0);
protected:
    void paintEvent(QPaintEvent *);
};

#endif // PAINTEDWIDGET_H
