#include "mysql.h"

MySql::MySql(QObject *parent)
    : QObject(parent)
{
    if (connectDataBase())
    {
        qDebug() << "数据库运行中";

    }
    else
    {
        qDebug() << "数据运行失败";
    }

}

bool MySql::connectDataBase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(fileName + ".db");
    if (database.open())
    {

        if (database.tables().contains(className + "_fun")
            && database.tables().contains(className + "_mem"))
        {

            qDebug() << "打开现有数据库成功";
            isOpen = true;
            return true;
        }
        else
        {
            query.
                exec(QString("create table %1_fun "
                             "( Name char(30) primary key,Return char (30) , Args char(50) ,Access int")
                         .arg(className));
            query.
                exec(QString("create table %1_mem "
                             "( Name char(30) primary key,Type char (30)),Access int").arg(className));
            qDebug() << "创建该类的表格" << className + "_fun" << "和" << "   _mem";
            isOpen = true;
            return true;
        }
    }
    else
    {
        isOpen = false;
        qDebug() << "数据库打开失败";
        return false;

    }
}


bool MySql::insertMember(QString & name, QString & type, int access)
{
    if (isExitTable(className + "_fun"))
    {
        if (query.exec(
                QString{ "insert into %1_fun ( Name , Type ,Access)  values ( '%2' , '%3' , %4)" }
                    .arg(className).arg(name).arg(type).arg(access)))
        {
            emit MemberChanged();
            return true;
        }
        return false;
    }
    else return false;
}

bool MySql::removeMember(QString & name)
{
    if (isExitTable(className + "_mem")) {
        if (query.exec(
                QString{ " delete from %1_mem  where Name = '%2' " }.arg(className).arg(name))) {
            emit FunctionChanged();
            return true;
        }
        return false;
    }
    return false;
}

bool MySql::removeFunction(QString & name)
{
    if (isExitTable(className + "_fun"))
    {
        if (query.exec(

                QString{ " delete from %1_fun where Name = '%2'" }.arg(className).arg(name)))
        {
            emit FunctionChanged();
            return true;
        }
        return false;
    }
    return false;
}

bool MySql::insertFunction(QString & name, QString & returnValue, QString & args, int access)
{
    if (isExitTable(className + "_fun"))
    {
        if (query.exec(
                QString{ "insert into %1_fun ( Name , Return , Args ,Access) \
                    values ( '%2' , '%3' , %4)" }
                    .arg(className).arg(name).arg(returnValue).arg(args).arg(access)))
        {
            emit FunctionChanged();
            return true;
        }
        return false;
    }
    else return false;
}

QStringList MySql::refleshFunction()
{
    if (!query.exec("select * from " + className + "_fun"))
    {
        qDebug() << "查询错误的表格 _fun";
        return QStringList{};
    }
    QStringList list;
    auto record = query.record();
    int name = record.indexOf("Name"); // number 是Name的索引
    int retur = record.indexOf("Return");
    int args = record.indexOf("Args");
    int access = record.indexOf("Access");

    while (query.next())
    {
        list += query.value(name).toString();
        list += query.value(retur).toString();
        list += query.value(args).toString();
        list += query.value(access).toString();
    }
    return list;
}
QStringList MySql::refleshMember() {
    if (!query.exec("select * from " + className + "_mem")) {
        qDebug() << "查询错误的表格 _mem_";
        return QStringList{};
    }
    QStringList list;
    auto record = query.record();
    int name = record.indexOf("Name");
    int Type = record.indexOf("Type");
    int access = record.indexOf("Access");
    while (query.next())
    {
        list += query.value(name).toString();
        list += query.value(Type).toString();
        list += query.value(access).toString();
    }
    return list;
}
