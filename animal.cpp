#include "animal.h"

Animal::Animal()
{
    rad_age = 5;
    move_x = qrand() % 2 == 0 ? -3 : 3;
    move_y = qrand() % 2 == 0 ? -3 : 3;;
}

void Animal::Tick(QPainter *qp)
{
    qp->setBrush(QBrush(rad_age < 74 ? color : QColor(47,47,47), Qt::SolidPattern));
    qp->drawEllipse(QRect(x - rad_age, y - rad_age, rad_age * 2, rad_age * 2));
    //QString info = QString(color == QColor(255,0,0) ? "Predator " : "Vegan ") + QString::number(rad_age);
    //qp->drawText(x, y, info);
    move();
    rad_age += 1;
}

void Animal::move()
{
    x += move_x * veloc;
    y += move_y * veloc;

    if (x <= rad_age || x >= W - rad_age)
    {
        move_x = -move_x;
        x += move_x;
    }
    if (y <= rad_age || y >= H - rad_age)
    {
        move_y = -move_y;
        y += move_y;
    }
}


