#include "QtGuiApplication4.h"
#include<qfile.h>
#include<QtUiTools/QUiLoader>
#include <qdebug>
#include <QVBoxLayout>
QtGuiApplication4::QtGuiApplication4(QWidget *parent)
	: QWidget(parent, Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint)
{
	QFile file(":/QtGuiApplication4/QtGuiApplication4.ui");
	if (file.exists())
		qDebug() << "open";
	file.open(QFile::ReadOnly);
	QUiLoader loader;
	QWidget *uiWidget = loader.load(&file, this);
	file.close();

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(uiWidget);
	setLayout(layout);
	uiWidget->show();
}
