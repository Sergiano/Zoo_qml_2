#include "predator.h"

Predator::Predator(int coord_x, int coord_y)
{
    x = coord_x;
    y = coord_y;
    color = QColor(255,0,0);
    veloc = 1.8;
}

void Predator::Tick(QPainter *qp)
{
    qp->setBrush(QBrush(rad_age < 74 ? color : QColor(47,47,47), Qt::SolidPattern));
    qp->drawEllipse(QRect(x - rad_age, y - rad_age, rad_age * 2, rad_age * 2));
    qp->drawText(x, y, "Predator " + QString::number(rad_age));
    move();
    rad_age += 1;
}
