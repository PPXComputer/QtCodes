#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlComponent>
#include<useslot.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //连接c++的方式
    QQmlEngine eng;
    QQmlComponent component{&eng,QUrl(QStringLiteral("qrc:/main.qml"))};
    auto obj=component.create();
    UseSlot test;
    QObject::connect(obj,SIGNAL(useButton()),&test,SLOT(mySlots()));

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    return app.exec();
}
