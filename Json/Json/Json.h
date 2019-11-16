#pragma once

#include <QtWidgets/QWidget>
#include "ui_Json.h"

class Json : public QWidget
{
	Q_OBJECT

public:
	Json(QWidget *parent = Q_NULLPTR);

private:
	Ui::JsonClass ui;
};
