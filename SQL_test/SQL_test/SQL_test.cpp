#include "SQL_test.h"
#include <QtWidgets>
#include <QtSql>
#include <QSqlDatabase>
#pragma  execution_character_set("utf-8")
TableEditor::TableEditor(const QString &tableName, QWidget *parent)
	: QWidget(parent)
{
	model = new QSqlTableModel(this);
	model->setTable(tableName);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	model->setHeaderData(0, Qt::Horizontal, tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, tr("First name"));
	model->setHeaderData(2, Qt::Horizontal, tr("Last name"));

	auto sd = QSqlDatabase::drivers();
	for (auto &s : sd) {
		qDebug() << "可用的设备"<<s;
	}
	auto *view = new QTableView;
	view->setModel(model);
	view->resizeColumnsToContents();

	submitButton = new QPushButton(tr("Submit"));
	submitButton->setDefault(true);
	revertButton = new QPushButton(tr("&Revert"));
	quitButton = new QPushButton(tr("Quit"));

	buttonBox = new QDialogButtonBox(Qt::Vertical);
	buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
	buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
	buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

	connect(submitButton, &QPushButton::clicked, this, &TableEditor::submit);
	connect(revertButton, &QPushButton::clicked, model, &QSqlTableModel::revertAll);
	connect(quitButton, &QPushButton::clicked, this, &TableEditor::close);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addWidget(view);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);

	setWindowTitle(tr("Cached Table"));
}

void TableEditor::submit()
{
	qDebug() << "进行提交";
	model->database().transaction();
	if (model->submitAll()) {
		qDebug() << "提交全部";
		model->database().commit();
	}
	else {
		model->database().rollback();
		QMessageBox::warning(this, tr("Cached Table"),
			tr("The database reported an error: %1")
			.arg(model->lastError().text()));
	}
}