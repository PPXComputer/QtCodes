#include "mysql.h"

MySql::MySql(QObject *parent) : QObject(parent)
{

    connectDatabase();
}

bool MySql::connectDatabase()
{
    database=QSqlDatabase::addDatabase ("QSQLITE");
    database.setDatabaseName ("music.db");
    if(database.open ()){
        //设置主键自增 插入 null值则可以 使用
        query = std::move(QSqlQuery(database));
        qDebug() << "数据库是否开始" << database.isOpen();

        return true;
    }
    else
    {
        auto dirvers=QSqlDatabase::drivers();
        qDebug()<<dirvers;
        return false;
    }
}

bool MySql::insertMusic(QString &author, QString &album, QString &duration, QString &filePath)
{

          query.prepare("INSERT INTO musicResource (musicName,author,album,duration,filePath) "
                        "VALUES (?, ?, ?,?)");
          query.addBindValue(author);
          query.addBindValue(album);
          query.addBindValue(duration);
          query.addBindValue(filePath);
        return printError(query);
}

bool MySql::removeMusic(QString &filepath)
{
    if(filepath.isEmpty())return true;
    query.prepare(QString("delete from musicResource where filePath='%1'").arg(filepath));
    return printError(query);
}

bool MySql::insertTourList(QString &className, QString &dataArray, QString image)
{
    query.prepare("insert into tourList (className)");
}
