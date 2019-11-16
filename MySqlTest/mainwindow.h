#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql/QSqlDatabase>
#include<QMessageBox>
#include<QtSql/QSqlQuery>
#include<qdebug.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static bool ConnectDataBase(){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost:3306");
        db.setDatabaseName("windows");
        db.setUserName("root");
        db.setPassword("chenshy2272");
        bool ok = db.open();
        if(ok){
              qDebug()<<"成功连接数据库";
             return ok;
        }else{
              QMessageBox::warning(NULL,"警告","无法连接数据库");
              return ok;
        }
    }
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
