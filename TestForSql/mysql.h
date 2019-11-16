#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include <QString>
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
// 这个作为全局存在的sql远行数据库
// 数据库中有张总表格 id   filePath
//在新建一个表格中存在一个 fileName表示新建文件的名字  这里的filePath是指文件路径
class MySql : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ getFilePath WRITE setFilePath NOTIFY filePathChanged)
public:
    explicit MySql(QObject *parent = nullptr);
    bool connection();
    MySql(const MySql&)=delete ;
    ~MySql()=default;
signals:
    void filePathChanged(QString &name);

    // 重复名字时触发该信号
    void fileNeedToChanged(QString& name);
public slots:
    Q_INVOKABLE QString getFilePath() { return this->filePath; }
    Q_INVOKABLE QString getFileName()
    {
        if (filePath.isEmpty())
            return QString{""};
        auto list = filePath.split("\\");
        return list.back();
    }
    Q_INVOKABLE void setFilePath(QString name)
    {
        // 将 路径的名字 转换为 当前所需要的文件名字
        if ((!filePath.isEmpty()) && name != getFilePath()) {
            int j = 0;
            int size = filePath.size();
            for (int i = 0; i < size; ++i) {
                if (filePath[i] == "\\") {
                    j = i;
                }
            }
            filePath.replace(j, size - j + 1, name);
            emit filePathChanged(filePath);
        }
    }
    //在当前目录名字 重复的时候 进行使用槽函数
    Q_INVOKABLE void startNewFile(QString &path);

private:
    QSqlDatabase database;
    QSqlQuery query;
    QString filePath = "temp";
};

#endif // MYSQL_H
