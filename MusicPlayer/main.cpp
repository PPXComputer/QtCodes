#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    // 第一 : 添加信号槽的响应  这里使用的进行注册了 qml类型
    //    qmlRegisterType<MyClass>("file ", "版本1", "版本2", "ClassName"); 大写
    // 然后在 qml中         import file 版本1.版本2 小写
    // 就可以使用            className.signal 或者是 className.slots

    // 第二 :枚举则使用 Q_ENUMS(EnumsName)

    // 第三 : 访问类的属性
    // 使用 Q_PROPERTY 将 有关数据的操作的函数名字 填入
    // NOTIFY 的部分  在qml中使用 onSomeOneChanged:
    // Q_IVOKABLE 可以将普通函数进行 注册 来进行使用

    // 第四 : 设置 qml的 上下文属性
    //setContextProperty("useName","ClassName")
    // 相当于直接创建了个 useName 对象 可以使用其注册的属性 和 枚举类型
    // useName.slots useName.signal

    // 使用 c++访问 qml的数据
    //1 使用注册 类型来进行使用
    //    qmlRegisterType<Gemini>("Union.Lotto.Gemini", 1, 0, "Gemini");
    //  在 qml中 直接 使用
    // Gemini{
    //       }
    //    QQmlEngine engine;
    //    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:///main.qml")));

    //    2.设置上下文属性 也可以
    //    engine.rootContext()->setContextProperty("aGemini", &aGemini);
    //  aGemini.data


//  在c++代码中   使用 qml的数据
//    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:///main.qml")));
//    QObject *object = component.create();
//    qDebug() << "width value is" << object->property("width").toInt();
//    object->setProperty("width", 500);  设置属性的数据
//    qDebug() << "height value is" << QQmlProperty::read(object, "height").toInt();
//    QQmlProperty::write(object, "height", 500);
// 需要是 对于子类的qml objectName 属性设置为rect
//    QObject *rect = object->findChild<QObject*>("rect");
//    if(rect) {
//        rect->setProperty("color", "black");
//    }


    // 使用qml的信号 和 槽   注意参数 的 转换
    //QMetaObject::invokeMethod()
    // 比如 qml中 信号为 signal qmlSignal(string name)
    // //    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:///main.qml")));
    //    QObject *object = component.create(); 使用 此 object进行 连接就是了



// qml中 槽 函数 为 function qmlFunction()
//    QVariant returnedValue;
//    QVariant message ;
//    QMetaObject::invokeMethod(object, "qmlFunction", 此处的 object 与上处相同
//                              Q_RETURN_ARG(QVariant, returnedValue),
//                              Q_ARG(QVariant, message));
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);}, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
