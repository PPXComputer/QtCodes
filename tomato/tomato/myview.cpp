#include "myview.h"
#pragma  execution_character_set("utf-8")
myview::myview(QWidget *parent) :QChartView(parent)
{
	menu->setParent(this);
	menu->addAction(QIcon(":/new/icon/setting"), "更改数据图", this, &myview::show_setting);
	auto study = new QPieSeries();
	study->setName("专注");
	study->append("学习", 25);
	/*study->append("工作", 30);
	study->append("学习", 40);
	study->append("积累", 30);*/
	auto rest = new QPieSeries();
	rest->setName("休息");
	rest->append("放松", 5);
	/*rest->append("放松", 20);
	rest->append("娱乐", 30);
	rest->append("运动", 40);
	auto others = new QPieSeries();
	others->setName("其他");
	others->append("其他", 25); */
	chart->setAnimationOptions(QChart::AllAnimations);
	chart->setTitle("这是你的一个作息表格");
	chart->legend()->setAlignment(Qt::AlignRight);
	chart->addBreakdownSeries(study, Qt::darkGray);
	chart->addBreakdownSeries(rest, Qt::darkGreen);
	//chart->addBreakdownSeries(others, Qt::darkGray);
	QChartView::setChart(chart);
	setRenderHint(QPainter::Antialiasing);
}

myview::~myview()
{
	delete menu;
	delete chart;
}

inline void myview::contextMenuEvent(QContextMenuEvent * event)
{
	menu->exec();
}