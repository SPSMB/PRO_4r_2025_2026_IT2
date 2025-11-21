#include "letadlo.h"

Letadlo::Letadlo() {
    l_ohraniceni = QRectF(0,0,200,150);
}

QRectF Letadlo::boundingRect() const
{
    // nejtesnejsi opsany obdelnik nasemu letadlu
    return l_ohraniceni;
}

void Letadlo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon letadlo;
    letadlo.append(QPoint(0,0));
    letadlo.append(QPoint(200,150));
    letadlo.append(QPoint(200,100));
    painter->setBrush(QBrush(QColor(125,125,0)));
    painter->drawPolygon(letadlo);
}

int Letadlo::width()
{
    return l_ohraniceni.width();
}

int Letadlo::height()
{
    return l_ohraniceni.height();
}
