#include "Sql_Test.h"

Sql_Test::Sql_Test(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QPluginLoader loader;
	// MySQL ���������·��
	loader.setFileName("E:/Qt/Qt5.10.1/5.10.1/msvc2017_64/plugins/sqldrivers/qsqlmysqld.dll");
	qDebug() << loader.load();
	//qDebug() << loader.errorString();
	for (auto& sd : QSqlDatabase::drivers())
	{
		ui.textEdit->append(QString("֧�ֵ����ݿ�����") +sd);
	}
	if (!connectSQL())
	{
		qDebug() << "����ʧ��";
		exit(1);
	}
	ui.textEdit->document()->setMaximumBlockCount(30);

	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//������ʾ����
	My_connection();
	//�Ѿ������� sql_test�ı��
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
	//��������
	auto sdsd1 = connect(ui.Insert, &QPushButton::clicked, this, &Sql_Test::Insert_Button);
	auto sdsd2 = connect(ui.Delete, &QPushButton::clicked, this, &Sql_Test::Delete_Button);
	auto sdsd3 = connect(ui.Search, &QPushButton::clicked, this, &Sql_Test::Select_Button);
	auto sdsd4 = connect(ui.Clean, &QPushButton::clicked, this, &Sql_Test::Clean_Button);
	auto sdsd5 = connect(ui.sql_words, &QPushButton::clicked, this, &Sql_Test::Sql_Button);
	//ÿ�ν����޸ĵ�sql��������� ���±��
	auto sdsd6=connect(this, &Sql_Test::query, this, &Sql_Test::Sql_changed);
	auto sdsd7=connect(this, &Sql_Test::InsertSql, this, &Sql_Test::Sql_changed);
	auto sdsd8=connect(this, &Sql_Test::DeleteSql, this, &Sql_Test::Sql_changed);
	//���ı༭ֱ��Ӱ�����ݿ�
}

bool Sql_Test::query(QString& sd)
{
	
	if ((DBquery->exec(sd))) {
		ui.textEdit->append(QString("����SQL���ɹ�"));
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
		ui.textEdit->append("ɾ���Ŀյ�ѧ��,�������ܽ���");
		return false;
	}
	if (DBquery->exec(  QString("delete from sql_test where num='%1'").arg(number)))
	{
		ui.textEdit->append(QString("ɾ���ɹ� ѧ��Ϊ : %1").arg(number));
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
        auto sd=QString("���ݴ�ʧ�� %1").arg(db->lastError().text());
		ui.textEdit->append(sd);
		qDebug() << sd;
		return false;
	}
	DBquery = new QSqlQuery;
	model = new QSqlTableModel(this, *db);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setTable("sql_test");
	model->select();
	model->setHeaderData(0, Qt::Horizontal, tr("����"));
	model->setHeaderData(1, Qt::Horizontal, tr("����"));
	model->setHeaderData(2, Qt::Horizontal, tr("ѧ��"));
	//δ�����ݿ���ж���ṹ  ����δ�����: ����
	//model->setHeaderData(3, Qt::Horizontal, tr("����"));
	ui.tableView->setModel(model); 
	return true;
}

void Sql_Test::Select_Button()
{
	//��ѯΪ��ʱ�Զ���ѯȫ��������
	auto Number = ui.NumberEdit->text();
	if (!SearchSql(Number))
	{
		ui.textEdit->append("��ѯʧ��");
		ui.textEdit->append(DBquery->lastError().text());
	}
}

void Sql_Test::Insert_Button()
{
	qDebug() << "���в������";
    auto Name = ui.NameEdit->text();
    auto ages = ui.AgeEdit->text();
    auto Number = ui.NumberEdit->text();
	if (Name.isEmpty() || ages.isEmpty()|| Number.isEmpty())
	{
		ui.textEdit->append(QString("������Ϊ���޷����в���"));
		return;
	}
	InsertSql(Name, ages, Number);
}

void Sql_Test::Delete_Button()
{
	qDebug() << "ɾ������";
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
		ui.textEdit->append("��ѯ���Ϊ�� ,����������");
		return;
	}
	else
	{
		query(sd);
	}
}

//���ڶ������ݿ� ������ر��Ĳ���
inline void Sql_Test::Sql_changed()
{
	if (model->select())
	{
		ui.textEdit->append("�����ݸĶ�");
	}
}

bool Sql_Test::Model_Changed()
{
	//������������ ��ɾ�����ݽ��� �޸�ͬʱ�������ݿ�
	//1.����δ֪�﷨����
	//2.�޸��޷��������ݿ��Ҫ��
	//3.�����޸�

	//��ʼ�������
	model->database().transaction();
	if (model->submitAll())
	{
		//�����ύ����
		model->database().commit();
		ui.textEdit->append("���ݿ�ͬ���޸ĳɹ�");
	}
	else
	{
		model->database().rollback();
		ui.textEdit->append(QString("ͬ���޸����ݿ� ���ִ��� %1").arg(model->lastError().text()));
	}
	return false;
}
