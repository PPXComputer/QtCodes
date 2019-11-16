#include "myview.h"
#pragma  execution_character_set("utf-8")
myview::myview(QWidget *parent) :QChartView(parent)
{
	menu->setParent(this);
	menu->addAction(QIcon(":/new/icon/setting"), "��������ͼ", this, &myview::show_setting);
	auto study = new QPieSeries();
	study->setName("רע");
	study->append("ѧϰ", 25);
	/*study->append("����", 30);
	study->append("ѧϰ", 40);
	study->append("����", 30);*/
	auto rest = new QPieSeries();
	rest->setName("��Ϣ");
	rest->append("����", 5);
	/*rest->append("����", 20);
	rest->append("����", 30);
	rest->append("�˶�", 40);
	auto others = new QPieSeries();
	others->setName("����");
	others->append("����", 25); */
	chart->setAnimationOptions(QChart::AllAnimations);
	chart->setTitle("�������һ����Ϣ���");
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