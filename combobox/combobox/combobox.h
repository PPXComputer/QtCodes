#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_combobox.h"

class combobox : public QMainWindow
{
	Q_OBJECT

public:
	combobox(QWidget *parent = Q_NULLPTR);

private:
	Ui::comboboxClass ui;
};
