#include "imageprovider.h"
#include "infomusic.h"
#include <musicmeata.h>
/*
#include <QDebug>
#include <QDir>
#include <QImage>
#include <QPixmap>
*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

// 源代码是由 C 编写的
extern "C" {
#include "libavcodec/avcodec.h"
#include "libavdevice/avdevice.h"
#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libswresample/swresample.h"
}
class ColorImageProvider;
class ShowImage;
std::string getResourceFromQrc(const QString &qrcFile);
double duration(const char *filename);
std::string getResourceFromFileSystem(const QUrl &url);
std::string getResourceFromFileSystem(const QString &url);
void test();
void getMusicMessage();
// 同时使用资源文件的素材 或者 使用文件系统的文件 主要是因为多语言文字的作用
std::string getResourceFromQrc(const QString &qrcFile)
{
    QUrl dir{qrcFile};
    QDir assist;
    return assist.absoluteFilePath(dir.fileName()).toStdString();
}
std::string getResourceFromFileSystem(const QUrl &url)
{
    return url.toString().toStdString();
}
std::string getResourceFromFileSystem(const QString &url)
{
    return url.toStdString();
}
void test()
{
    AVFormatContext *fmt_ctx = nullptr;
    // AVDictionaryEntry *tag = nullptr;
    auto qrc = getResourceFromQrc("Yulia - 여름날의 소풍.mp3");
    if ((avformat_open_input(&fmt_ctx, qrc.c_str(), nullptr, nullptr))) {
        qDebug() << "Fail to open file1";
    }
    auto file = getResourceFromFileSystem(
        QUrl{"/home/ppx/音乐/CloudMusic/Yulia/Twinkle Of The Night "
             "Sky"});
    if ((avformat_open_input(&fmt_ctx, file.c_str(), nullptr, nullptr))) {
        qDebug() << "Fail to open file2";
    }
}

void getMusicMessage()
{
    AVFormatContext *fmt_ctx = nullptr;
    AVDictionaryEntry *tag = nullptr;
    int ret = 0;
    QDir music{""};
    auto musicPath = music.absoluteFilePath("Yulia - 여름날의 소풍.mp3");
    qDebug() << musicPath.toStdString().c_str();
    //  qthelp://org.qt-project.qtcore.5131/qtcore/qstring.html
    if ((ret = avformat_open_input(&fmt_ctx, musicPath.toStdString().c_str(), nullptr, nullptr))) {
        qDebug() << "Fail to open file";
    }

    avformat_find_stream_info(fmt_ctx, nullptr);

    //    double duration = (double) ;

    //   avformat_close_input(&fmt_ctx);
    //avformat_free_context(fmt_ctx);

    // 读取为秒 //将此数据传到 数据库中去
    qDebug() << "时长为" << static_cast<double>(fmt_ctx->duration / AV_TIME_BASE);
    QMap<QString, QString> maps;
    //读取metadata中所有的tag
    while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) {
        // qDebug() << QString("Tag:%1 , Value: %2").arg(tag->key).arg(tag->value);
        // qDebug() << "时长为:" << fmt_ctx->duration;
        maps.insert(tag->key, tag->value);
    }
    for (auto &&sd : maps.keys()) {
        qDebug() << "歌曲属性为" << sd << "值为" << maps[sd];
    }
    if (fmt_ctx->iformat->read_header(fmt_ctx) < 0) {
        printf("No header format");
        return;
    }

    for (size_t i = 0; i < fmt_ctx->nb_streams; i++) {
        if (fmt_ctx->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
            AVPacket pkt = fmt_ctx->streams[i]->attached_pic;
            //使用QImage读取完整图片数据（注意，图片数据是为解析的文件数据，需要用QImage::fromdata来解析读取）
            QImage img = QImage::fromData(reinterpret_cast<uchar *>(pkt.data), pkt.size);
            qDebug() << "是否为空" << img.isNull(); // 不为空 ... 我擦
            auto sd = QPixmap::fromImage(std::move(img)); // 获得图像
            //  show->setImage(img); // 这里将调用 给qml使用
            break;
        }
    }
}

const QString picture()
{
    QImage myImage;
    // Some init code to setup the image (e.g. loading a PGN/JPEG, etc.)
    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    myImage.save(&buffer, "JPEG");
    QString image("qrc:/music/选区_006.png");
    image.append(QString::fromLatin1(bArray.toBase64().data()));

    return image;
}

int main(int argc, char *argv[])
{
    //av_register_all();
    //输出版本号
    unsigned version = avcodec_version();
    qDebug() << "version is:" << version;
    //test();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //getMusicMessage();
    //    ShowImage *CodeImage = new ShowImage(&engine);
    //    getMusicMessage(); // 在使用中设置 图片
    // 设置上下文属性将 得到的资源进行使用
    //engine.rootContext()->setContextProperty("CodeImage", CodeImage);
    //    engine.addImageProvider(QLatin1String("CodeImg"), CodeImage->m_pImgProvider);
    //    // 将数据加入到使用的colors中
    //    engine.addImageProvider(QLatin1String("colors"), new ColorImageProvider);
    MusicMeata meata{};
    auto provider = meata.getProvider();
    auto infomusic = meata.getMusicData();
    // auto sd = infomusic->getResouce();

    // 这里没有触发吗?
    engine.addImageProvider(QLatin1String("CodeImg"), provider);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    //设置当前的音乐解析对象
    engine.rootContext()->setContextProperty("provider", provider);
    engine.rootContext()->setContextProperty("CoveImage", infomusic->CoveImage);
    //    engine.rootContext()->setContextProperty("infomusic", infomusic);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);
    // CodeImage->setImage(QImage{QString{"qrc:/music/选区_006.png"}});
    infomusic->getMessage(); // emit imageSource
    return app.exec();
}
