#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlTableModel>
#include<QString>
#include<QVector>
#include<QMap>
#include <QMainWindow>
#include<QFile>
#include<sstream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(const MainWindow& )=delete ;
    MainWindow &operator =(const MainWindow &)=delete ;
    bool DataBase();
    ~MainWindow(){
        delete ui;
        delete query;
        ui=nullptr;
        query=nullptr;
    }

private:
    Ui::MainWindow *ui;
    QSqlQuery * query;
    QSqlDatabase *dataBase;
};

#endif // MAINWINDOW_H
