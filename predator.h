#ifndef PREDATOR_H
#define PREDATOR_H

#include <QObject>
#include <QPainter>
#include "globalconst.h"
#include "animal.h"

class Predator : public Animal
{
public:
    Predator(int coord_x, int coord_y);
    void Tick(QPainter *qp) override;
};

#endif // PREDATOR_H
