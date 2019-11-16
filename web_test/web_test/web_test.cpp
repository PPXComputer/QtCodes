#include<qdebug.h>
#include "web_test.h"
#include<qwebengineview.h>
#include<qurl.h>
#include<qpushbutton.h>
#pragma execution_character_set("utf-8")
web_test::web_test(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.View->load(QUrl("https://www.bilibili.com/"));
	ui.View->setFocus();
	connect(ui.View, &QWebEngineView::loadStarted, []() {
		qDebug() << "开始加载"; }
	);
	connect(ui.View, &QWebEngineView::loadProgress, this, [this](int sd)
	{
		progress = sd;
		adjustProgress();
	});
	connect(ui.View, &QWebEngineView::titleChanged, this, &web_test::adjustProgress);
	connect(ui.enter, &QPushButton::clicked, ui.View, [this]() {
		ui.View->load(QUrl(ui.edit->text()));
		qDebug() << "重新加载" << ui.edit->text();
	});
	connect(ui.View, &QWebEngineView::loadFinished, this, [this]() {
		setWindowTitle("loading error");
	});
}