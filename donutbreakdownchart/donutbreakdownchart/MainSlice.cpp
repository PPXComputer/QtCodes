#include "mainslice.h"

QT_CHARTS_USE_NAMESPACE

MainSlice::MainSlice(QPieSeries *breakdownSeries, QObject *parent)
	: QPieSlice(parent),
	m_breakdownSeries(breakdownSeries)
{
	connect(this, &MainSlice::percentageChanged, this, &MainSlice::updateLabel);
}

QPieSeries *MainSlice::breakdownSeries() const
{
	return m_breakdownSeries;
}

void MainSlice::setName(QString name)
{
	m_name = name;
}

QString MainSlice::name() const
{
	return m_name;
}

void MainSlice::updateLabel()
{
	this->setLabel(QString("%1 %2%").arg(m_name).arg(percentage() * 100, 0, 'f', 2));
}
