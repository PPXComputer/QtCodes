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
//#include<qtextedit.h>
//#include<qevent.h>
//#include<qdrag.h>
//#include<QDropEvent>
//#include<QDragEnterEvent>
//#include<qfile>
//#include<qmimedata.h>
#include <QtWidgets/QMainWindow>
#include "ui_drop_test.h"
#include<qthread.h>
#include<qdebug.h>
#include<qpushbutton.h>
#pragma execution_character_set("utf-8")
class Thread :public QThread
{
public:
	Thread() = default;
	void setMessage(const QString & message) {
		Message = message;
	}
	QString getMessage()
	{
		QString copy = Message;
		return copy;
	}
	void stop()
	{
		stopped = true;
	}
	~Thread();
protected:
	void run()override;
private:
	QString Message;
	volatile bool stopped=false;
};


inline void Thread::run()
{
	if (!stopped)
	{
		qDebug() << Message;
	}
	stopped = false;
	qDebug() <<'\n';
}

class drop_test : public QMainWindow
{
	Q_OBJECT
public:
	drop_test(QWidget *parent = Q_NULLPTR);

private:
	Ui::drop_testClass ui;
//	
//protected:
//	void dragEnterEvent(QDragEnterEvent *) override;
//	void dropEvent(QDropEvent *) override;
	Thread threadA;
	Thread threadB;
protected slots:
	void stopOrstart(Thread &thread) {
		QPushButton * button=nullptr;
		if (thread.getMessage() == "A")		 button = ui.pushButton;
		else			button = ui.pushButton_2;
		if (thread.isRunning())
		{
			thread.stop();
			button->setText(QString("start%1").arg(thread.getMessage()));
		}
		else
		{
			thread.start();
			button->setText(QString("stop%1").arg(thread.getMessage()));
		}
	}
};

