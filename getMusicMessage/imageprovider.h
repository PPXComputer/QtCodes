#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H
#include <QDebug>
#include <QDir>
#include <QQuickImageProvider>
#include <QString>
class ImageProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    // 默认
    explicit ImageProvider(QObject *parent = nullptr,
                           ImageType type = QQuickImageProvider::Pixmap,
                           Flags flags = Flags())
        : QObject(parent), QQuickImageProvider(type, flags)
    {}
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        // 这里获得是 qrc下的内容
        if (isSuccess) {
            isSuccess = false;
            qDebug() << "使用了读取后的图像";
            return this->img;
        } else {
            return defaultPiutrce; // 不按照使用标准来进行判定
        }
    }

    QPixmap getImg() const { return img; }

    void setImg(QPixmap value)
    {
        qDebug() << "设置封面成功";
        img = std::move(value);
        emit iamgeResourceChanged();
    }
signals:
    void iamgeResourceChanged();

private:
    QPixmap img;
    QPixmap defaultPiutrce{"qrc:/picture/Face.png"};
    bool isSuccess = false;
};

#endif
