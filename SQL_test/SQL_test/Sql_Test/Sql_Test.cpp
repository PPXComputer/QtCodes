#include "Sql_Test.h"

Sql_Test::Sql_Test(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QPluginLoader loader;
	// MySQL 驱动插件的路径
	loader.setFileName("E:/Qt/Qt5.10.1/5.10.1/msvc2017_64/plugins/sqldrivers/qsqlmysqld.dll");
	qDebug() << loader.load();
	//qDebug() << loader.errorString();
	for (auto& sd : QSqlDatabase::drivers())
	{
		ui.textEdit->append(QString("支持的数据库类型") +sd);
	}
	if (!connectSQL())
	{
		qDebug() << "连接失败";
		exit(1);
	}
	ui.textEdit->document()->setMaximumBlockCount(30);

	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//设置显示中文
	My_connection();
	//已经存在着 sql_test的表格
	/*for (auto& sd : db->tables())
	{
		qDebug() << sd;
	}
	if( !(db->tables().contains("sql_test")))
	{
		auto& sd = QString("create table sql_test(name char(10),age char(3),num char(20) primary key);");
		ui.textEdit->append(sd);
		query(sd);
	}*/
}

inline void Sql_Test::My_connection()
{
	//动作触发
	auto sdsd1 = connect(ui.Insert, &QPushButton::clicked, this, &Sql_Test::Insert_Button);
	auto sdsd2 = connect(ui.Delete, &QPushButton::clicked, this, &Sql_Test::Delete_Button);
	auto sdsd3 = connect(ui.Search, &QPushButton::clicked, this, &Sql_Test::Select_Button);
	auto sdsd4 = connect(ui.Clean, &QPushButton::clicked, this, &Sql_Test::Clean_Button);
	auto sdsd5 = connect(ui.sql_words, &QPushButton::clicked, this, &Sql_Test::Sql_Button);
	//每次进行修改的sql操作会进行 更新表格
	auto sdsd6=connect(this, &Sql_Test::query, this, &Sql_Test::Sql_changed);
	auto sdsd7=connect(this, &Sql_Test::InsertSql, this, &Sql_Test::Sql_changed);
	auto sdsd8=connect(this, &Sql_Test::DeleteSql, this, &Sql_Test::Sql_changed);
	//表格的编辑直接影响数据库
}

bool Sql_Test::query(QString& sd)
{
	
	if ((DBquery->exec(sd))) {
		ui.textEdit->append(QString("输入SQL语句成功"));
		while (DBquery->next())
		{
            auto name = DBquery->value(0).toString();
            auto ages = DBquery->value(1).toString();
            auto number1 = DBquery->value(2).toString();
			ui.textEdit->append(QString(" name :%1 ,age :%2, number : %3").arg(name).
				arg(ages).arg(number1));
		}
		return true;
	}
	ui.textEdit->append(DBquery->lastError().text());
	return false;
}

bool Sql_Test::InsertSql(const QString& name, const QString& ages, const QString& number)
{
    auto sd = QString("insert into sql_test values('%1','%2','%3');")
		.arg(name).arg(ages).arg(number);
	if (!DBquery->exec(sd)) {
		ui.textEdit->append(DBquery->lastError().text());
		return false;
	}
	ui.textEdit->append(sd);
	return true;
}

bool Sql_Test::SearchSql(const QString&number)
{   
    auto Number = QString("select * from sql_test where num=\"%1\" ;").arg(number);
    auto empty = QString("select * from sql_test;");
	QString& sd=Number;
	if (number.isEmpty())
	{
		sd = empty;
	}
	return query(sd);
}

bool Sql_Test::DeleteSql(const QString & number)
{
	if (number.isEmpty())
	{
		ui.textEdit->append("删除的空的学号,操作不能进行");
		return false;
	}
	if (DBquery->exec(  QString("delete from sql_test where num='%1'").arg(number)))
	{
		ui.textEdit->append(QString("删除成功 学号为 : %1").arg(number));
		return true;
	}
	ui.textEdit->append(DBquery->lastError().text());
	return false;
}

bool Sql_Test::connectSQL()
{
    db =&( QSqlDatabase::addDatabase("QMYSQL"));
	db->setHostName("127.0.0.1");
	db->setPort(3306);
	db->setDatabaseName("sql_test");
	db->setUserName("root");
	db->setPassword("chenshy2272");
	if (!db->open())
	{
        auto sd=QString("数据打开失败 %1").arg(db->lastError().text());
		ui.textEdit->append(sd);
		qDebug() << sd;
		return false;
	}
	DBquery = new QSqlQuery;
	model = new QSqlTableModel(this, *db);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setTable("sql_test");
	model->select();
	model->setHeaderData(0, Qt::Horizontal, tr("名字"));
	model->setHeaderData(1, Qt::Horizontal, tr("年龄"));
	model->setHeaderData(2, Qt::Horizontal, tr("学号"));
	//未将数据库进行定义结构  存在未添加项: 描述
	//model->setHeaderData(3, Qt::Horizontal, tr("描述"));
	ui.tableView->setModel(model); 
	return true;
}

void Sql_Test::Select_Button()
{
	//查询为空时自动查询全部的数据
	auto Number = ui.NumberEdit->text();
	if (!SearchSql(Number))
	{
		ui.textEdit->append("查询失败");
		ui.textEdit->append(DBquery->lastError().text());
	}
}

void Sql_Test::Insert_Button()
{
	qDebug() << "进行插入操作";
    auto Name = ui.NameEdit->text();
    auto ages = ui.AgeEdit->text();
    auto Number = ui.NumberEdit->text();
	if (Name.isEmpty() || ages.isEmpty()|| Number.isEmpty())
	{
		ui.textEdit->append(QString("有数据为空无法进行插入"));
		return;
	}
	InsertSql(Name, ages, Number);
}

void Sql_Test::Delete_Button()
{
	qDebug() << "删除操作";
    auto number = ui.NumberEdit->text();
	DeleteSql(number);
}

void Sql_Test::Clean_Button()
{
}

void Sql_Test::Sql_Button()
{
    auto sd = ui.sql_Edit->toPlainText();
	if (sd.isEmpty())
	{
		ui.textEdit->append("查询语句为空 ,请重新输入");
		return;
	}
	else
	{
		query(sd);
	}
}

//用于对于数据库 更新相关表格的部分
inline void Sql_Test::Sql_changed()
{
	if (model->select())
	{
		ui.textEdit->append("无数据改动");
	}
}

bool Sql_Test::Model_Changed()
{
	//表格里添加数据 或删除数据进行 修改同时进入数据库
	//1.出现未知语法错误
	//2.修改无法满足数据库的要求
	//3.撤销修改

	//开始事务操作
	model->database().transaction();
	if (model->submitAll())
	{
		//真正提交操作
		model->database().commit();
		ui.textEdit->append("数据库同步修改成功");
	}
	else
	{
		model->database().rollback();
		ui.textEdit->append(QString("同步修改数据库 出现错误 %1").arg(model->lastError().text()));
	}
	return false;
}
