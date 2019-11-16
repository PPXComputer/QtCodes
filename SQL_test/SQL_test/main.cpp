// #include <QApplication>

#include "SQL_test.h"
#include <connection.h>
#include <qapplication.h>
#include<QtSql/qtsqlglobal.h>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	if (!createConnection())
		return 1;

	TableEditor editor("person");
	editor.show();
	return app.exec();
}
