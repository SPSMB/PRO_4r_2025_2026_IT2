#ifndef LETADLO_H
#define LETADLO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>

class Letadlo : public QGraphicsItem
{
private:
    QRectF l_ohraniceni;
    QPolygon l_obrys;
    QColor l_barvaPozadi;
    QColor l_barvaObrysu;

public:
    Letadlo();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;
    int width();
    int height();
    void setColor(QColor c);
};

#endif // LETADLO_H
