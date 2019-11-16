#pragma once
#pragma  execution_character_set("utf-8")
#include <QWindow>
#include "ui_main_windows.h"
#include "my_gif.h"
#include<qmainwindow.h>
#include <qstring.h>
#include <myview.h>
#include <qcombobox.h>
#include <QTime>
#include <MyListItem.h>
#include <qlineseries.h>
#include <qpieseries.h>
#include <qlistwidget.h>
#include <QListWidgetItem>
#include<qfile.h>
using Data = QPair<QPointF, QString>;
using DataList = QList<Data>;
using DataTable = QList<DataList>;
using namespace QtCharts;
class main_windows : public QMainWindow
{
	Q_OBJECT

public:
	main_windows(QMainWindow*parent = Q_NULLPTR);
	~main_windows();

private:
	Ui::MainWindow ui;
	my_gif * gif = new my_gif;//缩略图
private: //为了窗口移动
	bool isDrag = false;
	QPoint start = QPoint();
	QPoint end = QPoint();
private:
	//创建的图表格
//	QChart *PieChart=nullptr;
	QChart *LineChart = nullptr;
	//QChart* creatpiechart();
	QChart* creatlinechart();
	QList<QChartView *> mychartView;
	//初始化函数 进行 按键的连接
	void CreateConnection();
	void CreateBoxes();
	//我的数据存储
	DataTable table;
	int m_listCount;
	int m_valueMax;
	int m_valueCount;
	DataTable creattable(int listCount, int valueMax, int valueCount) const;
	void setchartView();
	//关于更新场景
private	slots:void update_view();
private	slots:void update_item();
private:
	void SetStyle_Listwidget();
protected:
	void mouseMoveEvent(QMouseEvent *event)override;
	void mousePressEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event)override;
};
