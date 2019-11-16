#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString test;
    test.split ('1');
    return a.exec();
}
