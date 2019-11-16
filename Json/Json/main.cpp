#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtCore>
#include<memory>
#pragma execution_character_set("utf-8")
/*		json�� 5�� ������������
		bool��QJsonValue::Bool�� 0
		double��QJsonValue::Double��1
		string��QJsonValue::String��2
		array��QJsonValue::Array��3
		object��QJsonValue::Object��4
		null��QJsonValue::Null��5

QVector<QPair<QString, int>> container{
	QPair("loaction",2),QPair<>
};*/
class MyClass :public QThread
{
public:
	MyClass();
	void run()override {
	}
	~MyClass();
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
class TT : public QObject
{
	Q_OBJECT
public:
	static void getHtml(QString url)
	{
		QNetworkAccessManager* manager = new QNetworkAccessManager();
		QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(url)));

		QEventLoop eventLoop;
		auto sd1 = connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
		auto sd2 = connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
		eventLoop.exec();       //block until finish

		//readAll �����ظ�����!!!!
		QJsonParseError error;
		auto Document = QJsonDocument::fromJson(reply->readAll(), &error);
		qDebug() << Document << endl;//ֱ�Ӵ�ӡ

		//json����Ľ���
		if (auto sd = Document.object(); !sd.isEmpty())
		{
			if (sd.contains("HeWeather6"))
			{
				auto value = sd.take("HeWeather6");
				if (value.isArray())
				{//�ͷ�������json ���ݴ����  ����� json������
					//heweather ����� һ������
					if (auto first = value.toArray().at(0); first.isObject())
					{    //�� basic  update stauts now �⼸���Ӷ���
						//����״̬�ж�
						if (auto DataMap = first.toObject(); DataMap.contains("status"))
						{
								qDebug() << "���`���ʵ�״̬��Ϣ" << DataMap.value("status").toString();
								 IndexToData(first.toObject());
							}
					}
					else 
					{
						qDebug() << "�������Ų�����һ������";
					}
				}
			}
			else
			{
				qDebug() << "�����δ���ַ��� ";
			}
		}
		else
		{
			qDebug() << "���������Ϣ" << error.errorString();
		}
		reply->deleteLater();
	}

	using Vec=std::shared_ptr<QVector<const char* > >;
	//map��key��  basic  update stauts now �⼸���Ӷ���
	//����ֻ�洢���й� now������
	using Map=std::shared_ptr<QMap<QString, Vec>>;
	inline static void IndexToData(QJsonObject& object) {
		Vec nowList = std::make_shared
			<QVector< const char *> >(std::initializer_list
				{ 
				"cloud",
				"cond_code" ,
				"cond_txt",
				"fl",
				"hum",
				"pcpn",
				"pres" ,
				"tmp",
				"vis" ,
				"wind_deg" ,
				"wind_dir" ,
				"wind_sc"});
		auto result = std::make_shared<QMap<QString, Vec>>();
		result->insert("now", nowList);
		MapResult(object, result);
	}
	//����ÿһ����key������н���
	inline static void MapResult(QJsonObject& object,Map& map) {
		QMapIterator it{ *map };
		while (it.hasNext())
		{
			it.next();
			auto key = it.key();
			if (auto Result = object.contains(it.key()))
			{
				if (auto Key_name = object.take(key); Key_name.isObject())
				{
					auto obejct = Key_name.toObject();
					auto value = it.value();
					for (auto begin = value->begin(); begin != value->end(); begin++)
					{
						if (auto Result=obejct.value(*begin);Result!= QJsonValue::Undefined)
						{
							qDebug() << "��������Ϊ" << key << "�ؼ���Ϊ" << *begin << "ֵΪ" << Result.toString();
						}
					}
				}
			}
		}
	}
	private:
		void run() override {


		}
};
//
int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);
	TT::getHtml(QString("https://free-api.heweather.net/s6/weather/now?location=beijing&key=e76da20009e841f5a66a7a3791a3d75f"));
	return a.exec();
}