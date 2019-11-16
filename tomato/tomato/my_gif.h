#pragma once
#include <QtWidgets/QWidget>
#include "ui_tomato.h"
#include <qpoint.h>
#include <mymenu.h>
class my_gif : public QWidget
{
	Q_OBJECT
		friend class main_windows;
public:
	my_gif(QWidget *parent = Q_NULLPTR);
	my_gif& operator=(const my_gif&) = delete;
	my_gif& operator=(const my_gif&&) = delete;
	~my_gif() {
		delete menu;
	}

protected:
	void mouseMoveEvent(QMouseEvent *event) override;
	void mousePressEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void	contextMenuEvent(QContextMenuEvent *event) override;

private:
	Ui::tomatoClass ui;
	bool mMoving = true;
	QPoint mMovePosition = QPoint();
	mymenu * menu = new mymenu;
signals:
	void show_setting();
	void main_panel();
};
