#pragma once
#pragma  execution_character_set("utf-8")
#include <QMenu>
#include <qaction.h>
class my_gif;
class mian_windows;
class mymenu : public QMenu
{
	Q_OBJECT
		friend class my_gif;
	friend class main_windows;
public:
	mymenu(QWidget *parent = nullptr);
	~mymenu();
private:
	QAction* setting;
	QAction *main_panel;
	QAction *close;
};
