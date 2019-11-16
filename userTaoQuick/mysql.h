#ifndef MYSQL_H
#define MYSQL_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlError>
#include<QtDebug>
#include <QObject>
#include<QUrl>
#include<QMediaMetaData>
class MySql : public QObject
{
    Q_OBJECT
public:
    explicit MySql(QObject *parent = nullptr);
    bool connectDatabase();

public slots:
    Q_INVOKABLE bool insertMusic(QString & author,QString& album,QString & duration,QString & filePath);
    Q_INVOKABLE bool removeMusic(QString &filepath);
    Q_INVOKABLE bool insertTourList(QString &className,QString &dataArray,QString image=QString(":/new/qq"));
    Q_INVOKABLE bool removeList(QString &className,QString&dataArray);
    inline bool printError(QSqlQuery &query){
      if(!query.exec()){
                qDebug()<<query.lastError();
                return false;
            }
            return true;

    }
private:
     QSqlDatabase database;
     QSqlQuery query;
};

#endif // MYSQL_H
