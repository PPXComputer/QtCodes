#include "combobox.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	combobox w;
	w.show();
	return a.exec();
}
