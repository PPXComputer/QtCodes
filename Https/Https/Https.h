#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Https.h"
#include<qurl.h>
#include<qurlquery.h>
#include<qnetworkrequest.h>
#include<qstring.h>
#include<qnetworkreply.h>
#include<qnetworkaccessmanager.h>
#include<qeventloop.h>
#include<qtcpserver.h>
#include<qdebug.h>
#include<qrandom.h>
#include<qthread.h>
#pragma execution_character_set("utf-8")
class Https;
class MyServer;
class Private;
class FortuneThread;
class Https : public QMainWindow
{
	Q_OBJECT

public:
	Https(QWidget *parent = Q_NULLPTR);

private:
	Ui::HttpsClass ui;
};
class MyServer :public  QTcpServer
{
	Q_OBJECT
public:
	MyServer();
	~MyServer();

private:
	void incomingConnection(qintptr ) override;
	QStringList fortunes{ "皮皮虾服务","皮皮虾服务器","皮皮猪服务" };
};

MyServer::MyServer()
{
}

MyServer::~MyServer()
{
}

inline void MyServer::incomingConnection(qintptr)
{
	//在另一个线程中进行网络连接
	QString fortune = fortunes.at(QRandomGenerator::global()->bounded(fortunes.size()));
	FortuneThread* thread = new FortuneThread(socketDescriptor(), fortune, this);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}
class FortuneThread :public QThread
{
	Q_OBJECT
public:
	FortuneThread(qintptr socketDescriptor, const QString& fortune, QObject* parent):socketDescriptor(socketDescriptor),
		text(fortune),QThread(parent){}
	void run() override;
signals:
	void error(QTcpSocket::SocketError socketError);

private:
	qintptr  socketDescriptor;
	QString text;
};
class NetWork : public QObject
{
	Q_OBJECT
		friend class Private;
public:
	NetWork();
	~NetWork();
	static NetWork* instance();
private:
	
	Private* p;

};

NetWork::NetWork()
{
}

NetWork::~NetWork()
{
}