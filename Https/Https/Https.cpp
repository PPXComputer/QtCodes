#include "Https.h"

Https::Https(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//QUrl baseUrl= "http://www.csdn.net/" ;
	////ÇëÇóÉêÇë
	//QNetworkRequest request  ;
	//request.setUrl(baseUrl);
	////·¢ËÍÇëÇó
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
	//query.addQueryItem("key","Æ¤Æ¤Ïº");
	//sd.setQuery(query);
	//qDebug() << sd.toString();
	////ÇëÇóÉêÇë
	//QNetworkRequest request  ;
	//request.setUrl(sd);
	////·¢ËÍÇëÇó
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
