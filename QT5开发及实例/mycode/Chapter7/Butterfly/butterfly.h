#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include <QRectF>
#include <QStyleOptionGraphicsItem>
#include <QPixmap>

class Butterfly : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent *);
    // 为图元限定区域范围，所有继承自QGraphicsItem的自定义图元都必须实现此函数
    QRectF boundingRect() const;
signals:

public slots:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    bool up;
    QPixmap pix_up;     // 用于表示两幅蝴蝶的图片
    QPixmap pix_down;
    qreal angle;
};

#endif // BUTTERFLY_H
