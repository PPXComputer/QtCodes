#pragma once

#include <QtWidgets/QWidget>

#include <QDialog>

class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;

class TableEditor : public QWidget
{
	Q_OBJECT

public:
	explicit TableEditor(const QString &tableName, QWidget *parent = nullptr);

private slots:
	void submit();

private:
	QPushButton *submitButton;
	QPushButton *revertButton;
	QPushButton *quitButton;
	QDialogButtonBox *buttonBox;
	QSqlTableModel *model;
};
