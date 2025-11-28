#include "letadlo.h"

Letadlo::Letadlo() {
    l_ohraniceni = QRectF(0,0,200,150);
    l_obrys.append(QPoint(0,0));
    l_obrys.append(QPoint(200,150));
    l_obrys.append(QPoint(200,100));
    l_barvaPozadi = QColor(125,125,0);
    l_barvaObrysu = QColor(255,255,255);
}

QRectF Letadlo::boundingRect() const
{
    // nejtesnejsi opsany obdelnik nasemu letadlu
    return l_ohraniceni;
}

void Letadlo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(l_barvaPozadi));
    painter->setPen(QPen(l_barvaObrysu, 2));   // tloušťka 2 px
    painter->drawPolygon(l_obrys);
}

QPainterPath Letadlo::shape() const
{
    QPainterPath kolizni_obrys;
    kolizni_obrys.addPolygon(l_obrys);
    return kolizni_obrys;
}

int Letadlo::width()
{
    return l_ohraniceni.width();
}

int Letadlo::height()
{
    return l_ohraniceni.height();
}

void Letadlo::setColor(QColor c)
{
    l_barvaPozadi = c;
    update();
}
