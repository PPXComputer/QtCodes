#include "chart_theme_test.h"
#include <QtWidgets/QApplication>
#include <qmainwindow.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMainWindow window;
	ThemeWidget *widget = new ThemeWidget();
	window.setCentralWidget(widget);
	window.resize(900, 600);
	window.show();
	return a.exec();
}
