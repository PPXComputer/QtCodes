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
	my_gif * gif = new my_gif;//����ͼ
private: //Ϊ�˴����ƶ�
	bool isDrag = false;
	QPoint start = QPoint();
	QPoint end = QPoint();
private:
	//������ͼ���
//	QChart *PieChart=nullptr;
	QChart *LineChart = nullptr;
	//QChart* creatpiechart();
	QChart* creatlinechart();
	QList<QChartView *> mychartView;
	//��ʼ������ ���� ����������
	void CreateConnection();
	void CreateBoxes();
	//�ҵ����ݴ洢
	DataTable table;
	int m_listCount;
	int m_valueMax;
	int m_valueCount;
	DataTable creattable(int listCount, int valueMax, int valueCount) const;
	void setchartView();
	//���ڸ��³���
private	slots:void update_view();
private	slots:void update_item();
private:
	void SetStyle_Listwidget();
protected:
	void mouseMoveEvent(QMouseEvent *event)override;
	void mousePressEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event)override;
};
