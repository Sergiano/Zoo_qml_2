#ifndef ZOO_H
#define ZOO_H

#include <QObject>
#include <QtCore>
#include <QTimer>
#include <QDateTime>
#include <QPainter>
#include <QVector>
//#include <QQmlContext>
//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QQuickPaintedItem>
#include <QPainter>

#include "globalconst.h"
#include "animal.h"
#include "predator.h"
#include "vegan.h"

class Zoo : public QQuickPaintedItem
{

Q_OBJECT

public:
    Zoo();
    //~Zoo();

    QTimer *qtim;
    //Animal **animals;
    QVector<Animal*> animals;
    QList<QString> log;

    void paint(QPainter* painter);

private:
    int getRandomX();
    int getRandomY();
    void toLog(QString info);
    void ageControl();
    void huntControl();
    Animal* bornNew();

private slots:
    void newGen();

};

#endif // ZOO_H
