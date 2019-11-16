#include "main_windows.h"
main_windows::main_windows(QMainWindow *parent)
	: QMainWindow(parent),
	m_listCount(3),
	m_valueMax(10),
	m_valueCount(7)
{
	table = creattable(m_listCount, m_valueMax, m_valueCount);
	LineChart = creatlinechart();
	qDebug() << "开始创建元素";
	ui.setupUi(this);
	setWindowIcon(QIcon(":/new/prefix1/ppx2"));
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	ui.listWidget->sizeHintForRow(20);
	qDebug() << "开始创建连接";
	CreateConnection();
	CreateBoxes();
	setchartView();
	auto widgetItem = new QListWidgetItem(ui.listWidget);
	widgetItem->setSizeHint(QSize(100, 70));
	auto Myitem = new MyListItem(ui.listWidget);
	ui.listWidget->addItem(widgetItem);
	ui.listWidget->setItemWidget(widgetItem, Myitem);
	SetStyle_Listwidget();
}

main_windows::~main_windows()
{
	delete gif;
}

void main_windows::CreateConnection()
{
	qDebug() << "连接信号 ";
	connect(ui.pushButton_3, &QPushButton::clicked, ui.stackedWidget, [this]() {
		gif->show();
	});

	connect(ui.pushButton, &QPushButton::clicked, ui.stackedWidget, [this]() {
		ui.stackedWidget->setCurrentIndex(0); qDebug() << "首页";
	});
	connect(ui.pushButton_5, &QPushButton::clicked, ui.stackedWidget, [this]() {
		ui.stackedWidget->setCurrentIndex(0); qDebug() << "首页";
	});
	connect(gif, &my_gif::main_panel, this, [this]() {
		this->showNormal();
		ui.stackedWidget->setCurrentIndex(0); qDebug() << "首页";
	});
	connect(ui.pushButton_2, &QPushButton::clicked, ui.stackedWidget, [this]() {
		ui.stackedWidget->setCurrentIndex(1); qDebug() << "编辑";
	});
	connect(ui.pushButton_3, &QPushButton::clicked, ui.stackedWidget, [this]() {
		//ui.stackedWidget->setCurrentIndex(2);
		qDebug() << "缩略图";
	});
	connect(ui.pushButton_6, &QPushButton::clicked, ui.stackedWidget, [this]() {
		ui.stackedWidget->setCurrentIndex(2); qDebug() << "日程";
	});
	connect(gif, &my_gif::show_setting, this, [this]() {
		this->showNormal();
		ui.stackedWidget->setCurrentIndex(2); qDebug() << "设置";
	});
	connect(ui.comboBox_3,
		static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &main_windows::update_view);
	connect(ui.checkBox, &QCheckBox::toggled, this, &main_windows::update_view);
	connect(ui.comboBox_2,
		static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &main_windows::update_view);
	connect(ui.comboBox,
		static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &main_windows::update_view);
	connect(ui.add_item, &QPushButton::clicked, this, &main_windows::update_item);
	//发现大小不合格 设置
	ui.pushButton_2->setGeometry(QRect(ui.pushButton->pos(), ui.pushButton->iconSize()));
	//保存信息??? 是数据库还是 文件
	//文件
	QFile  file("calenar.txt");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	else
	{
		QTextStream out(&file);
		for (size_t i = 0; i < ui.listWidget->count(); i++)
		{
			auto widget_temp = ui.listWidget->itemWidget(ui.listWidget->item(i));
			auto &ui_copy = static_cast<MyListItem *>(widget_temp)->ui;
			out << "The magic number is: " << i << "\n";
			out << ui_copy.pass->text() << ' ' << ui_copy.text->text() << ' ' << ui_copy.start->text() << "\n";
		}
	}
}

void main_windows::CreateBoxes()
{
	ui.comboBox->addItem("不使用图标 ", 0);
	ui.comboBox->addItem("图标置顶", Qt::AlignTop);
	ui.comboBox->addItem("图标置下", Qt::AlignBottom);
	ui.comboBox->addItem("图标置左", Qt::AlignLeft);
	ui.comboBox->addItem("图标置右", Qt::AlignRight);

	ui.comboBox_2->addItem("无动画特效", QChart::NoAnimation);
	ui.comboBox_2->addItem("线性轴动画", QChart::GridAxisAnimations);
	ui.comboBox_2->addItem("曲线动画", QChart::SeriesAnimations);
	ui.comboBox_2->addItem("全开", QChart::AllAnimations);

	ui.comboBox_3->addItem("明亮", QChart::ChartThemeLight);
	ui.comboBox_3->addItem("蔚蓝", QChart::ChartThemeBlueCerulean);
	ui.comboBox_3->addItem("黑暗", QChart::ChartThemeDark);
	ui.comboBox_3->addItem("棕色", QChart::ChartThemeBrownSand);
	ui.comboBox_3->addItem("整洁", QChart::ChartThemeBlueNcs);
	ui.comboBox_3->addItem("高光", QChart::ChartThemeHighContrast);
	ui.comboBox_3->addItem("冰蓝", QChart::ChartThemeBlueIcy);
	ui.comboBox_3->addItem("平常", QChart::ChartThemeQt);
}

void main_windows::update_view()
{
	auto Legend = ui.comboBox;
	auto Animations = ui.comboBox_2;
	auto Theme = ui.comboBox_3;
	//获得当前的数据
	QChart::ChartTheme theme = static_cast<QChart::ChartTheme>(Theme->itemData(Theme->currentIndex()).toInt());
	for (auto & sd : mychartView)
	{
		sd->chart()->setTheme(theme);
	}
	QPalette pal = window()->palette();
	if (LineChart->theme() != theme)
	{
		switch (theme)
		{
		case  QChart::ChartThemeLight: {
			pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}break;
		case  QChart::ChartThemeDark: {
			pal.setColor(QPalette::Window, QRgb(0x121218));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
		}break;
		case QChart::ChartThemeBlueCerulean: {
			pal.setColor(QPalette::Window, QRgb(0x40434a));
			pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
		}break;
		case  QChart::ChartThemeBrownSand: {
			pal.setColor(QPalette::Window, QRgb(0x9e8965));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}break;
		case  QChart::ChartThemeBlueNcs: {
			pal.setColor(QPalette::Window, QRgb(0x018bba));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}break;
		case QChart::ChartThemeHighContrast: {
			pal.setColor(QPalette::Window, QRgb(0xffab03));
			pal.setColor(QPalette::WindowText, QRgb(0x181818));
		}break;
		case QChart::ChartThemeBlueIcy: {
			pal.setColor(QPalette::Window, QRgb(0xcee7f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}break;
		default: {pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
			pal.setColor(QPalette::WindowText, QRgb(0x404044));
		}	break;
		}
	}
	window()->setPalette(pal);
	bool checked = ui.checkBox->isChecked();
	for (QChartView *chart : mychartView)
		chart->setRenderHint(QPainter::Antialiasing, checked);
	Qt::Alignment legend = static_cast<Qt::Alignment>(Legend->itemData(Legend->currentIndex()).toInt());
	if (!legend) {
		for (QChartView *chartView : mychartView)
			chartView->chart()->legend()->hide();
	}
	else {
		for (QChartView *chartView : mychartView) {
			chartView->chart()->legend()->setAlignment(legend);
			chartView->chart()->legend()->show();
		}
	}
	QChart::AnimationOptions  animation = static_cast<QChart::AnimationOptions>(Animations->itemData(Animations->currentIndex()).toInt());
	for (QChartView *chartView : mychartView)
		if (chartView->chart()->animationOptions() != animation)
		{
			chartView->chart()->setAnimationOptions(animation);
		}
}

void main_windows::update_item() {
	auto widgetItem = new QListWidgetItem(ui.listWidget);
	widgetItem->setSizeHint(QSize(100, 70));
	auto Myitem = new MyListItem(ui.listWidget);
	ui.listWidget->addItem(widgetItem);
	ui.listWidget->setItemWidget(widgetItem, Myitem);
	qDebug() << "现在的元素个数 " << ui.listWidget->count();
}

DataTable main_windows::creattable(int listCount, int valueMax, int valueCount) const
{
	DataTable dataTable;

	// set seed for random stuff
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	qDebug() << "开始获得随机数";
	// generate random data
	qDebug() << listCount << valueCount;
	for (int i(0); i < listCount; i++) {
		DataList dataList;
		qreal yValue(0);
		for (int j(0); j < valueCount; j++) {
			yValue = yValue + (qreal)(qrand() % valueMax) / (qreal)valueCount;
			QPointF value((j + (qreal)rand() / (qreal)RAND_MAX) * ((qreal)m_valueMax / (qreal)valueCount),
				yValue);
			QString label = "Slice " + QString::number(i) + ":" + QString::number(j);
			dataList << Data(value, label);
		}
		dataTable << dataList;
	}
	return dataTable;
}

QChart * main_windows::creatlinechart()
{
	QChart *chart = new QChart();
	chart->setTitle("Line chart");
	qDebug() << "创建折线图";
	QString name("Series ");
	int nameIndex = 0;
	for (const DataList &list : table) {
		QLineSeries *series = new QLineSeries(chart);
		for (const Data &data : list)
			series->append(data.first);
		series->setName(name + QString::number(nameIndex));
		nameIndex++;
		chart->addSeries(series);
	}
	chart->createDefaultAxes();

	return chart;
}

void main_windows::setchartView()
{
	qDebug() << "table元素检测" << table.count();
	//if (PieChart!=nullptr)
	//{
	//	auto chartview = new QChartView(PieChart);
	//	ui.piechart->addWidget(chartview);
	//	qDebug() << "添加饼图"<<(ui.piechart->widget()==nullptr);
	//}
	if (LineChart != nullptr)
	{
		auto chartview = new QChartView(LineChart);
		mychartView.push_back(chartview);
		ui.linechart->addWidget(chartview);
	}
}

inline void main_windows::SetStyle_Listwidget()
{
	//设置透明        点击时加深背景右键 设置界面
	//时间跳动特效? 开始和 进行的时间格式设置.文本设置 初始时间设置
	ui.listWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
	ui.listWidget->setStyleSheet("QWidget{border:1px solid gray; color:black; }"
		//"QListView::item{background-color( 0, 0,  0, 0}"
		"QListWidget::Item:hover{background-color: rgb(111, 161, 199);}"
		//"QListView::item:selected:!active{background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 #ABAFE5, stop: 1 #8588B2);}"
		"QListView::item:selected:active{   }"
		//"QListWidget{background-image: url(:/tomato/Resources/feizhuliuzhuomianbizhi_351225_9.jpg);}"
		//"QListWidget::item::QLabel:active{background-color:black}"
	);
}

void main_windows::mouseMoveEvent(QMouseEvent * event)
{
	if (isDrag && (event->buttons() && Qt::LeftButton))
	{
		move(event->globalPos() - start);
		event->accept();
	}
}

void main_windows::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		isDrag = true;
		start = event->pos();
	}
	QMainWindow::mousePressEvent(event);
}

void main_windows::mouseReleaseEvent(QMouseEvent * event)
{
	isDrag = false;
	QMainWindow::mouseReleaseEvent(event);
}