#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QtSql/QSqlRecord>
#include<QStringList>
#include<QtDebug>
class MySql :public QObject

{
    Q_OBJECT
public:
    MySql(QObject *parent=nullptr);
    MySql(const MySql&)=default;

    bool connectDataBase();
   Q_INVOKABLE  bool insertMember(QString & name, QString & type, int access);
   Q_INVOKABLE bool  removeMember(QString & name);
   Q_INVOKABLE bool removeFunction(QString & name);
  Q_INVOKABLE  bool insertFunction(QString & name, QString & returnValue, QString & args, int access);
public slots:
    // 每4个一次 如果为null则是空字符串
    Q_INVOKABLE QStringList refleshFunction();
    Q_INVOKABLE QStringList refleshMember();
signals:
    void FunctionChanged();
    void MemberChanged();
private:
    inline bool isExitTable(QString tableName){
        if(database.isOpen ()){
            if(database.tables ().contains (tableName)){
                return  true;
            }
            return  false;
        }
        else {
            return false;
        }
    }
    QString className;
    QString myRole;
    QSqlQuery query;
    QString fileName="test";
    QSqlDatabase database;
    bool isOpen=false;

};

#endif // MYSQL_H
