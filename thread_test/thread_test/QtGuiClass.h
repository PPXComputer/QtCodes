/**
 *                 ━━━━━━神兽出没━━━━━━
 *　　　　　　　 ┏┓       ┏┓+ +
 *　　　　　　　┏┛┻━━━━━━━┛┻┓ + +
 *　　　　　　　┃　　　　　　 ┃
 *　　　　　　　┃　　　━　　　┃ ++ + + +
 *　　　　　　 █████━█████  ┃+
 *　　　　　　　┃　　　　　　 ┃ +
 *　　　　　　　┃　　　┻　　　┃
 *　　　　　　　┃　　　　　　 ┃ + +
 *　　　　　　　┗━━┓　　　 ┏━┛
 *                              ┃　　    ┃
 *　　　　　　　　   ┃　　    ┃ + + + +
 *　　　　　　　　　┃　　　┃　Code is far away from     bug with the animal protecting
 *　　　　　　　　　┃　　　┃ + 　　　　         神兽保佑,代码无bug
 *　　　　　　　　　┃　　　┃
 *　　　　　　　　　┃　　　┃　　+
 *　　　　　　　　　┃　 　 ┗━━━┓ + +
 *　　　　　　　　　┃ 　　　　　┣┓
 *　　　　　　　　　┃ 　　　　　┏┛
 *　　　　　　　　　┗┓┓┏━━━┳┓┏┛ + + + +
 *　　　　　　　　　 ┃┫┫　 ┃┫┫
 *　　　　　　　　　 ┗┻┛　 ┗┻┛+ + + +
 *                     ━━━━━━感觉萌萌哒━━━━━━
 */
#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"
#include"thread_test.h"
#include<qpushbutton.h>
#include<qevent.h>/*
class QtGuiClass : public QWidget
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

private:
	Ui::QtGuiClass ui;
	Thread threadA;
	Thread threadB;
	void closeEvent(QCloseEvent *)override;
protected slots:
	void StartOrStopA() {
		if (threadA.isRunning())
		{
			threadA.stop();
			ui.Button1->setText("start A");
		}
		else
		{
			threadA.start();
			ui.Button1->setText("stop A");
		}
	}
	void StartOrStopB() {
		if (threadB.isRunning())
		{
			threadB.stop();
			ui.Button_2->setText("start B");
		}
		else
		{
			threadB.start();
			ui.Button_2->setText("stop B");
		}
	}
};
*/