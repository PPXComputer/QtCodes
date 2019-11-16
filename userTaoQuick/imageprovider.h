#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>
class ImageProvider : public QObject, QQuickImageProvider
{
    Q_OBJECT
public:
    explicit ImageProvider(QString filePath,
                           QObject *parent = nullptr,
                           ImageType type = QQuickImageProvider::Pixmap,
                           Flags flags = Flags());

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(id);
        Q_UNUSED(size);
        Q_UNUSED(requestedSize);
        // 这里获得是 qrc下的内容
        if (isSuccess) {
            isSuccess = false;
            qDebug() << "使用了读取后的图像";
            return this->img.toImage();
        } else {
            qDebug() << "default image show";
            return defaultPiutrce.toImage(); // 不按照使用标准来进行判定
        }
    }
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(id);
        Q_UNUSED(size);
        Q_UNUSED(requestedSize);
        // 这里获得是 qrc下的内容
        if (isSuccess) {
            isSuccess = false;
            qDebug() << "使用了读取后的图像";
            return this->img;
        } else {
            qDebug() << "default image show";
            return defaultPiutrce; // 不按照使用标准来进行判定
        }
    }

    QPixmap getImg() const { return img; }

    void setImg(QPixmap value)
    {
        img = std::move(value);
        qDebug() << "设置封面成功";
        isSuccess = true;
        emit iamgeResourceChanged();
    }

private:
    QPixmap img;
    QPixmap defaultPiutrce{"qrc:/picture/Face.png"};
    QString url;
    bool isSuccess = false;

public:
    struct Information
    {
        QString musicName;
        QString author;
        QString album;
        QString duration;
        QString filePath;
    };
    using InfoMusicType = Information;

    QString CoveImage = "image://CodeImg/image.png"; // 最初的文件路径
signals:
    void urlChanged(QUrl);
    void iamgeResourceChanged();
    //  读取信息资源的时候　将　音乐的信息转出到数据库中使用
    // 成功时将触发此信号
    void getInformation(const InfoMusicType data);
public slots:
    Q_INVOKABLE void setUrl(QString filePath);
    void getMessage(); //  emit getInformation when success

private:
    inline std::string getResourceFromQrc(const QString &qrcFile)
    {
        QUrl dir{qrcFile};
        QDir assist;
        return assist.absoluteFilePath(dir.fileName()).toStdString();
    }
    inline std::string getResourceFromFileSystem(const QString &url)
    {
        return url.toString().toStdString();
    }
};

#endif // IMAGEPROVIDER_H
