#pragma once
#include <QChartView>
#include<qwidget.h>
#include <qchart.h>
#include<qpieslice.h>
#include <qpieseries.h>
#include<qlist.h>
#include <qchart.h>
#include <qpieseries.h>
#include <qpieslice.h>
#include <qpielegendmarker.h>
#pragma  execution_character_set("utf-8")
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class DonutBreakdownChart : public QChart
{
public:
	DonutBreakdownChart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = nullptr);
	void addBreakdownSeries(QPieSeries *series, QColor color);

private:
	void recalculateAngles();
	void updateLegendMarkers();

private:
	QPieSeries *m_mainSeries;
};