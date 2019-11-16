#include "Https.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Https w;
	w.show();
	return a.exec();
}
