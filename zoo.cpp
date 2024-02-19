#include "zoo.h"

Zoo::Zoo()
{
    QDateTime cd = QDateTime::currentDateTime();
    qsrand(cd.toTime_t());

    //animals = new Animal*[ANI_COUNT];

    for(int i = 0; i < ANI_COUNT; i++)
    {
        if(qrand() % 2 == 0)
            animals.append(new Predator(getRandomX(), getRandomY()));
            //animals[i] = new Predator(getRandomX(), getRandomY());
        else
            animals.append(new Vegan(getRandomX(), getRandomY()));
            //animals[i] = new Vegan(getRandomX(), getRandomY());

        animals[i]->rad_age = qrand() % ((77 + 1) - 5) + 5;
    }

    qtim = new QTimer();
    qtim->setInterval(100);
    connect(qtim, SIGNAL(timeout()), this, SLOT(newGen()));
    qtim->start();
}

/*Zoo::~Zoo()
{
    delete animals;
}*/

void Zoo::paint(QPainter* painter)
{
    ageControl();
    huntControl();

    for(int i = 0; i < ANI_COUNT; i++)
    {
        animals[i]->Tick(painter);
    }

    for(int i = 0; i < log.length(); i++)
    {
        painter->drawText(10, 20 + i * 12, log[i]);
    }
}

int Zoo::getRandomX()
{
    return qrand() % ((W + 1) - 0) + 0;
}

int Zoo::getRandomY()
{
    return qrand() % ((H + 1) - 0) + 0;
}

void Zoo::toLog(QString info)
{
    if (log.size() == 5)
        log.removeFirst();
     log.append(info);
}

void Zoo::newGen()
{
    update();
    qtim->start();
}

void Zoo::ageControl()
{
    for(int i = 0; i < ANI_COUNT; i++)
    {
        if (animals[i]->rad_age > 77)
        {
            toLog(animals[i]->color == QColor(255, 0, 0) ? "Predator died" : "Vegan died");
            delete animals[i];
            animals[i] = bornNew();
        }
    }
}

void Zoo::huntControl()
{
    for(int i = 0; i < ANI_COUNT; i++)
    {
        for(int j = 0; j < ANI_COUNT; j++)
        {
            if (i != j)
            {
                double dist = qSqrt(qPow(animals[i]->x - animals[j]->x, 2) + qPow(animals[i]->y - animals[j]->y, 2));
                double dist_max = animals[i]->rad_age + animals[j]->rad_age;
                if (dist < dist_max)
                {
                    // оба хищника, один меньше
                    if (animals[i]->rad_age > animals[j]->rad_age
                            && animals[i]->color == QColor(255,0,0)
                            && animals[j]->color == QColor(255,0,0))
                    {
                        toLog("Predator killed, age: " + QString::number(animals[j]->rad_age));
                        delete animals[j];
                        animals[j] = bornNew();
                    }
                    // хищник и веган
                    if (animals[i]->color == QColor(255,0,0)
                            && animals[i]->color != animals[j]->color)
                    {
                        toLog("Vegan killed, age: " + QString::number(animals[j]->rad_age));
                        delete animals[j];
                        animals[j] = bornNew();

                    }
                }
            }
        }
    }
}

Animal* Zoo::bornNew()
{
    if(qrand() % 2 == 0)
        return new Predator(getRandomX(), getRandomY());
    else
        return new Vegan(getRandomX(), getRandomY());
}
