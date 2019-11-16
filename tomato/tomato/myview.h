#pragma once
#include <qdebug.h>
#include <QChartView>
#include <mychart.h>
#include <qmenu.h>
#include <qicon.h>
#include <qstring.h>
using namespace QtCharts;
class myview : public QChartView
{
	Q_OBJECT
		friend class QGraphicsScene;
public:
	myview(QWidget *parent);
	~myview();
private:
	QMenu * menu = new QMenu;
	DonutBreakdownChart * chart = new DonutBreakdownChart;
protected:
	void contextMenuEvent(QContextMenuEvent *event) override;
private slots:
	void show_setting() {
		qDebug() << "ppx";
	}
};
