#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!MainWindow::ConnectDataBase())
        return 1;
    MainWindow w;
    w.show();

    return a.exec();
}
