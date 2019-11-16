#include "MyListItem.h"
#include <qdebug.h>
#include<Windows.h>
#pragma  execution_character_set("utf-8")
MyListItem::MyListItem(QWidget *parent)
	: QWidget(parent)
{
	GetLocalTime(&sys);
	start = sys;
	qDebug() << "创建个体";
	SetItems();
	setText((QString("%1年%2月%3日").arg(start.wYear)
		.arg(start.wMonth).arg(start.wDay)));
	setStart(QString("start"));
	setPassed(QString("passed"));
	setScale(QString("scale"));
	setStyleSheet("MyListitem:hover{ background-color: yellow     }");
	/*ui.scale->setStyleSheet("QCombox {boder:none;background-color:rgb(111, 161, 199   }"
		"QCombox:hover{background-color: rgb(111, 161, 199);"
	);*/
	connect(count, &QTimer::timeout, this, [this]() {
		//auto&date = passed.toString("yyyy:MM:dd");
		//使用windows api
		GetLocalTime(&sys);
		ui.pass->setText(QString("%1年%2月%3日%4小时:%5分钟:%6秒").arg(sys.wYear)
			.arg(sys.wMonth).arg(sys.wDay).arg(sys.wHour).arg(sys.wMinute).arg(sys.wSecond));
	});
	connect(ui.scale, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), ui.text, [this]() {
		switch (ui.scale->currentIndex())
		{
		case scale_set::year: setText(QString("%1年%2月%3日").arg(start.wYear)
			.arg(start.wMonth).arg(start.wDay));
			break;
		case scale_set::month:setText(QString("%1月%2日")
			.arg(start.wMonth).arg(start.wDay));
			break;
		case scale_set::second: setText(QString("%1年%2月%3日%4小时%5分钟%6秒").arg(start.wYear)
			.arg(start.wMonth).arg(start.wDay).arg(start.wHour).arg(start.wMinute).arg(start.wSecond));
			break;
		default:break;
		}
	});
}

MyListItem::~MyListItem()
{
	delete count;
}

inline void MyListItem::setText(QString &sd)
{
	ui.text->setText(sd);
}

void MyListItem::setStart(QString &start)
{
	ui.start->setText(start);
}

void MyListItem::setPassed(QString &Text)
{
	count->start(1000);//开始计时
	ui.pass->setText(Text);
}

void MyListItem::setScale(QString &scale)
{}

void MyListItem::SetItems()
{
	auto gridLayout = new QGridLayout(this);
	gridLayout->setSpacing(6);
	gridLayout->setContentsMargins(11, 11, 11, 11);
	gridLayout->setObjectName(QStringLiteral("gridLayout"));
	gridLayout->setVerticalSpacing(4);
	ui.scale = new QComboBox(this);
	ui.scale->setObjectName(QStringLiteral("ui.scale"));
	ui.scale->setAttribute(Qt::WA_TranslucentBackground);
	ui.scale->addItem(" 年 月 日", scale_set::year);
	ui.scale->addItem(" 月 日 ", scale_set::month);
	ui.scale->addItem("月 日 秒 ", scale_set::second);
	ui.scale->setStyleSheet("QComboBox QAbstractItemView {outline: none;}");
	gridLayout->addWidget(ui.scale, 2, 2, 1, 1);

	ui.start = new QLineEdit(this);
	ui.start->setObjectName(QStringLiteral("start"));
	ui.start->setAttribute(Qt::WA_TranslucentBackground);
	gridLayout->addWidget(ui.start, 2, 0, 1, 1);
	ui.start->setStyleSheet("background:transparent;border-width:0;border-style:outset");

	ui.text = new QLabel(this);
	ui.text->setObjectName(QStringLiteral("text"));
	ui.text->setAttribute(Qt::WA_TranslucentBackground);
	gridLayout->addWidget(ui.text, 0, 0, 1, 1);

	ui.pass = new QLabel(this);
	ui.pass->setObjectName(QStringLiteral("pass"));
	ui.pass->setAttribute(Qt::WA_TranslucentBackground);
	gridLayout->addWidget(ui.pass, 0, 2, 1, 1);

	auto horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);

	gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

	auto horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);

	gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);
	QFont font_copy;
	font_copy.setStretch(QFont::Expanded);
	font_copy.setPointSize(11);
	font_copy.setFamily("微软雅黑");
	ui.pass->setFont(font_copy);
	ui.text->setFont(font_copy);
	ui.scale->setFont(font_copy);
	ui.start->setFont(font_copy);
}