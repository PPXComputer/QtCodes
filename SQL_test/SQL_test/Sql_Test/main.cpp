#include "Sql_Test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Sql_Test w;
	w.show();
	return a.exec();
}
