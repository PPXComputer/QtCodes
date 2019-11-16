#include "mymenu.h"

mymenu::mymenu(QWidget *parent)
	: QMenu(parent)
{
	setting = new QAction(QIcon(":/tomato/setting"), "设置");
	main_panel = new QAction(QIcon(":/tomato/home"), "打开主面板");
	close = new QAction(QIcon(":/tomato/quit"), "退出");
	addAction(main_panel);
	addAction(setting);
	addAction(close);
	setStyleSheet(" QMenu {	background - color: white;margin: 2px;}");
	setStyleSheet("QMenu::item{  padding: 2px 25px 2px 20px;  border: 1px solid transparent;}");
	setStyleSheet("QMenu::item:selected{ 	border - color: darkblue; 	background: rgba(100, 100, 100, 150);}");
}

mymenu::~mymenu()
{
	delete setting;
	delete main_panel;
	delete close;
}