#include "globaltable.h"

GlobalTable::GlobalTable(QObject *parent)
    : QObject(parent)
{
    newThread = new QThread{this};
    connect(newThread, &QThread::destroyed, newThread, &QThread::deleteLater);
    connect(this,
            &GlobalTable::filePathChanged,
            this,
            &GlobalTable::initFileSystem,
            Qt::QueuedConnection);
    connect(this, &GlobalTable::needNewPath, this, &GlobalTable::printError, Qt::QueuedConnection);
    connect(this,
            &GlobalTable::classItemCreated,
            this,
            &GlobalTable::addNewClass,
            Qt::QueuedConnection);
    connect(this,
            &GlobalTable::classItemDestroy,
            this,
            &GlobalTable::deleteExitClass,
            Qt::QueuedConnection);
    moveToThread(newThread);
    newThread->start();
}

QString GlobalTable::getFilePath() const
{
    return filePath;
}

void GlobalTable::setFilePath(QString value)
{
    if (filePath != value) {
        filePath = std::move(value);

        emit filePathChanged(filePath);
    }
}

bool GlobalTable::deleteExitClass(const QString &className)
{
    assert(!database.isOpen());
    if (database.tables().contains(className)) {
        QSqlQuery query{database};
        if (query.exec(QString("delete * from Global where className= '%1'").arg(className))) {
            emit classItemDestroy(className);
            return true;
        }
        return false;
    }
    return true;
}
bool GlobalTable::addNewClass(const QString &className)
{
    assert(!database.isOpen());
    if (database.tables().contains(className)) {
        qDebug() << "all ready exit" << className;
        return false;
    }
    QSqlQuery query{database};
    if (query.exec(
            QString("insert into Global (id, className) values ( null , '%1 ')").arg(className))) {
        emit classItemCreated(className);
        return true;
    }
    return false;
}

void GlobalTable::initFileSystem()
{
    QDir newFile{};
    newFile.setPath(filePath);
    if (newFile.exists()) {
        emit needNewPath();
        return;
    }
    if (newFile.mkdir(filePath)) {
        qDebug() << "创建目录失败 需要重新输入目录";
        emit needNewPath();
        return;
    }
    database = QSqlDatabase::addDatabase(QString("SQLITE"), "localPath");
    database.setDatabaseName(filePath + "base.db");
    assert(!database.open());
    QSqlQuery query{QSqlDatabase::database("localPath")};
    // 设置主键自增
    if (query.exec(
            "create table Global ( id  integer(4) primary key , className varchar not null)")) {
        qDebug() << "全局表格创建完毕";
        emit dataBaseConnected();
    } else {
        qDebug() << query.lastError();
        return;
    }

    //        static_assert(this->database.isOpen(), "没有打开数据库");
}
