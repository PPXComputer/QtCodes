#include "Https.h"

Https::Https(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//QUrl baseUrl= "http://www.csdn.net/" ;
	////��������
	//QNetworkRequest request  ;
	//request.setUrl(baseUrl);
	////��������
	//auto manger = new QNetworkAccessManager(this);
	//auto reply = manger->get(request);
	//QEventLoop loop;
	//auto sd=connect(manger, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
	//loop.exec();
	// 
	// qDebug()<< reply->readAll();
	//QUrl sd="https://www.zhihu.com/search";
	//QUrlQuery query(sd);
	//query.addQueryItem("type", "content");
	//query.addQueryItem("key","ƤƤϺ");
	//sd.setQuery(query);
	//qDebug() << sd.toString();
	////��������
	//QNetworkRequest request  ;
	//request.setUrl(sd);
	////��������
	//auto manger = new QNetworkAccessManager(this);
	//auto reply = manger->get(request);
	//QEventLoop loop;
	//auto sd2=connect(manger, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
	//loop.exec(); 
	//qDebug()<<reply->readAll();
}

void FortuneThread::run()
{
}
