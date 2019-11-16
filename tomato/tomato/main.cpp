#include <QtWidgets/QApplication>
#include "main_windows.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	main_windows w;
	w.show();
	return a.exec();
}