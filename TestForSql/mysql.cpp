#include "mysql.h"

MySql::MySql(QObject *parent) : QObject(parent)
{
    if (connection()) {
        qDebug() << "数据库创建成功" + database.databaseName();
        query.exec(QString("select * from globalTable where filePath=%1 ").arg(filePath));
        if (!query.next()) {
            qDebug() << "创建一个新的表格" << filePath;
            query.exec(QString("insert into globalTable  values ( null, %1)").arg(filePath));
        } else {
            emit fileNeedToChanged(this->filePath);
        }
    }
}

bool MySql::connection()
{
    database=QSqlDatabase::addDatabase ("QSQLITE");
    database.setDatabaseName ("global.db");
    if(database.open ()){
        //设置主键自增 插入 null值则可以 使用
        query = std::move(QSqlQuery(database));
        query.exec(
            "create table globalTable (id int INTEGER PRIMARY KEY  , filePath varchar not null)");
        qDebug() << "数据库是否开始" << database.isOpen();
        return true;
    } else
        return false;
}

void MySql::startNewFile(QString &path)
{
    if (database.isOpen()) {
        query.exec(QString("select id from globalTable where filePath %1").arg(filePath));

        if (!query.isNull("id")) {
            query.exec(QString("insert into globalTable values ( null ,%1)").arg(path));
        }
    } else {
        qDebug() << "数据库并未开启无法创建新的文件路径";
    }
}
