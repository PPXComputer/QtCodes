#include<QGuiApplication>
#include<QQmlApplicationEngine>
#include<QQmlContext>
#include"mysql.h"
#include"mymodel.h"
class MySql;
class MyModel;
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    // 主文件中只有一个 链接使用数据库
    qmlRegisterType<MySql>("MyPackge",1,0,"MySql");
    qmlRegisterType<MyModel>("MyPackge",1,0,"MyModel");
   // qmlRegisterType<MyMediaList>("MyPackge",1,0,"MyMediaList");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
