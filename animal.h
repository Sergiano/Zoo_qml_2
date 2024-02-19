#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QPainter>
#include "globalconst.h"

class Animal : public QObject
{
public:
    Animal();

    int x;
    int y;
    int move_x;
    int move_y;
    double veloc;
    int rad_age;
    QColor color;

    virtual void Tick(QPainter *qp);

protected:
    void move();
};

#endif // ANIMAL_H
