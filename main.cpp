#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtQml>

#include "zoo.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Zoo>("zoo", 1, 0, "Zoo");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* window = engine.rootObjects().first();
    QObject* object = window->findChild<QObject*>("suka");

    return app.exec();
}
