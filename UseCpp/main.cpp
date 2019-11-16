#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QDebug>
#include<QQmlContext>
#include<QStandardPaths>
#include<QStringList>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QUrl appPath{QString("%1").arg(app.applicationDirPath ())};
    QUrl moviespath;
    const QStringList moviesLoaction
            =QStandardPaths::standardLocations (QStandardPaths::MoviesLocation);
    qDebug()<<"当前目录为"<<appPath;
    if(moviesLoaction.isEmpty ()){
        mo
    }
    QQmlApplicationEngine engine;
    engine.rootContext ()->setContextProperty ("appPath",appPath);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
