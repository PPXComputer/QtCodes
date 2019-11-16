#ifndef FOREACHFILE_H
#define FOREACHFILE_H
#include <QDir>
#include <QObject>
#include <qdebug.h>
#include <qfile.h>
#include <qurl.h>
// 每个新建的工作区 即 每个文件都应该存在 ForEachFile
// 保管着 文件夹内容的生成和存储
// 即 一个 相关的 未命名文件的创建 和 存储 在这个文件 存储的 所有类的信息 base.db的创建
// 拥有改变文件 路径 和保存文件的操作  默认为当前目录下 给 改变
class ForEachFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ getFilePath WRITE setFilePath NOTIFY filePathChanged)
public:
    explicit ForEachFile(QObject *parent = nullptr);
    ForEachFile(const ForEachFile &) = default;
    QString getFilePath() { return this->filePath; }
    void setFilePath(QString path);
    ~ForEachFile() = default;
signals:
    void filePathChanged(QString &path);
    void filePathError();
    void createCompleted();
public slots:
    void createFile();
    //    void changePath();
private:
    QString filePath = QDir::currentPath();
};

#endif // FOREACHFILE_H
