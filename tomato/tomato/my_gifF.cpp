#include "my_gif.h"
#include<qmovie.h>
#include<qevent.h>
#include <QMouseEvent>
#include<qlabel.h>
#include <qstring.h>
#include <qapplication.h>
#include <qdesktopwidget.h>
#include<qdebug.h>
my_gif::my_gif(QWidget *parent)
	: QWidget(parent)
{
	qDebug() << "´´½¨gif";
	ui.setupUi(this);
	setWindowOpacity(1);
	setAttribute(Qt::WA_TranslucentBackground);
	QWidget::setWindowFlags(Qt::FramelessWindowHint);
	setWindowModality(Qt::NonModal);
	setGeometry(QApplication::desktop()->rect());
	auto movie = new QMovie(":/tomato/studying");
	ui.label->setMovie(movie);
	//ui.label->setFixedSize(200, 200);
	movie->start();
	connect(menu->setting, &QAction::triggered, this, [this]() {
		emit show_setting();
	});
	connect(menu->main_panel, &QAction::triggered, this, [this]() {
		emit main_panel();
	});
	connect(menu->close, &QAction::triggered, this, &QWidget::close);
}

void my_gif::mouseMoveEvent(QMouseEvent * event)
{
	if (mMoving && (event->buttons() && Qt::LeftButton)
		&& (event->globalPos() - mMovePosition).manhattanLength() > QApplication::startDragDistance())
	{
		move(event->globalPos() - mMovePosition);
	}
	QWidget::mouseMoveEvent(event);
}

void my_gif::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		mMoving = true;
		mMovePosition = event->globalPos() - pos();
	}
	QWidget::mousePressEvent(event);
}

void my_gif::mouseReleaseEvent(QMouseEvent * event)
{
	mMoving = false;
}

void my_gif::contextMenuEvent(QContextMenuEvent * event)
{
	menu->move(event->globalPos());
	menu->exec();
}