#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QUrl>
#include <QDir>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cpp/mycontext.h"
#include "cpp/utile.h"
#include "cpp/MM.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    MyContext mycontext;
    QQmlContext* ctx= engine.rootContext();
    ctx -> setContextProperty("myContext", &mycontext);

    qDebug() << "avant return app.exec dans le main.";
    engine.load("qml/main.qml");

    return app.exec();
}
