#pragma once

#include <QtWidgets/QWidget>
#include "ui_web_test.h"

class web_test : public QWidget
{
	Q_OBJECT

public:
	web_test(QWidget *parent = Q_NULLPTR);

private:
	Ui::web_testClass ui;
	int progress = 0;
	void adjustProgress()
	{
		if (progress >= 0 && progress <= 100)
		{
			setWindowTitle(QString("progress: %1").arg(progress));
		}
		else
		{
			setWindowTitle(ui.View->title());
		}
	}
};
