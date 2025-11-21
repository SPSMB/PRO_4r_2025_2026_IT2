#ifndef LETADLO_H
#define LETADLO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>

class Letadlo : public QGraphicsItem
{
private:
    QRectF l_ohraniceni;

public:
    Letadlo();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int width();
    int height();
};

#endif // LETADLO_H
