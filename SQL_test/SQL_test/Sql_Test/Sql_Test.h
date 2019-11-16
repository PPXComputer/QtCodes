#pragma once

#include <QtWidgets/QWidget>
#include "ui_Sql_Test.h"
#include<qsql.h>
#include<qsqldatabase.h>
#include<qtextcodec.h>
#include<qsqlquery.h>
#include<qtextedit.h>
#include<qstring.h>
#include<qdebug.h>
#include<qsqlerror.h>
#include<qpluginloader.h>
#include<qtableview.h>
#include<qsqltablemodel.h>
#include<qsqlerror.h>
#pragma execution_character_set("utf-8")
class Sql_Test : public QWidget
{
	Q_OBJECT

public:
	Sql_Test(QWidget *parent = Q_NULLPTR);
	bool  connectSQL();
	~Sql_Test()
	{
	}
private:
	Ui::Sql_TestClass ui;
	QSqlDatabase* db=nullptr;
	QSqlQuery* DBquery=nullptr;
	QSqlTableModel* model = nullptr;
	inline void My_connection();
signals:
	bool query(QString &msg);
	bool InsertSql(const QString&name, const QString& ages,const QString&number );
	bool SearchSql(const QString&number);
	bool DeleteSql(const QString &number);
public slots:
	inline bool Model_Changed();
	//与ui界面进行的解析的信号槽
public slots:
inline	void Select_Button();
inline	void Insert_Button();
inline	void Delete_Button();
inline	void Clean_Button();
inline	void Sql_Button();
inline	void Sql_changed();
};
