#ifndef STARTITEM_H
#define STARTITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class StartItem : public QGraphicsItem
{
public:
    StartItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap pix;
};

#endif // STARTITEM_H
