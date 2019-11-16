#pragma once
#include <QWidget>
#include <qstring.h>
#include<memory>
#include<qsharedpointer.h>
#include <QListWidgetItem>
#include <QDate>
#include <qtimer.h>
#include<qlabel.h>
#include<qgridlayout.h>
#include <QMouseEvent>
#include<qlineedit.h>
#include<qcombobox.h>
#include<Windows.h>
class main_windows;
struct UI
{
	QLabel *text = nullptr;
	QComboBox*scale = nullptr;
	QLineEdit *start = nullptr;
	QLabel *pass = nullptr;
};
class MyListItem : public QWidget
{
	Q_OBJECT
		friend class main_windows;
public:
	MyListItem(QWidget *parent = Q_NULLPTR);
	~MyListItem();
	enum  scale_set
	{
		year, month, second
	};
	inline void setText(QString&);
	inline void setStart(QString &);
	inline void setPassed(QString&);
	inline void setScale(QString&);
	//开始的时间和 经过的时间
	SYSTEMTIME start;
	SYSTEMTIME sys;
	QDate passed;
	QTimer *count = new QTimer(this);
	UI ui;
private:
	void SetItems();
};
