#ifndef GLOBALTABLE_H
#define GLOBALTABLE_H
#include "functionmodel.h"
#include "membermodel.h"
#include <QtCore>
#include <QtGui>
#include <QtSql>
// 负责 在创建新文件的 时候  创建 base.db文件 和 进行数据库连接的操作
// setDataBase 创建的 新的 过程 应该是新的线程去做的事情
// 此连接的名字为 localPath
// needToFleshLines(QStrinList  对应的就是 类 和 想对应的 参数)
// 格式为  类,
// 此文件应该是于 画面交互的过程 args 和 type 与其中的 类  是否对应
class GlobalTable : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
public:
    explicit GlobalTable(QObject *parent = nullptr);
    GlobalTable(const GlobalTable &) = delete;
    GlobalTable &opeartor(const GlobalTable &) = delete;
    ~GlobalTable() = default;
    QString getFilePath() const;
    void setFilePath(QString value);

signals:
    void dataBaseConnected();
    // 需要一个目录
    void needNewPath();

    void filePathChanged(const QString &path);
    //    void needToFleshLines(QString keyValue);

    // 用于 表格model交互的信号
    void classItemCreated(const QString &className);
    void classItemDestroy(const QString &className);

public slots:
    void printError() { qDebug() << "需要一个新的路径"; }
    Q_INVOKABLE bool addNewClass(const QString &);
    Q_INVOKABLE bool deleteExitClass(const QString &);
    Q_INVOKABLE MemberModel &getMemberModel()
    {
        assert(member == nullptr);
        return *member;
    }
    Q_INVOKABLE FunctionModel &getFunctionModel()
    {
        assert(function == nullptr);
        return *function;
    }

private:
    QThread *newThread = nullptr;
    QString filePath;
    QSqlDatabase database;
    MemberModel *member = nullptr;
    FunctionModel *function = nullptr;
    //在每个新文件中使用 dabas.db创建 当前的文件的 所有的数据
    void initFileSystem();
    void connectTheDataBase();
};

#endif // GLOBALTABLE_H
