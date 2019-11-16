/**
 *                 ━━━━━━神兽出没━━━━━━
 *　　　　　　　 ┏┓       ┏┓+ +
 *　　　　　　　┏┛┻━━━━━━━┛┻┓ + +
 *　　　　　　　┃　　　　　　 ┃
 *　　　　　　　┃　　　━　　　┃ ++ + + +
 *　　　　　　 █████━█████  ┃+
 *　　　　　　　┃　　　　　　 ┃ +
 *　　　　　　　┃　　　┻　　　┃
 *　　　　　　　┃　　　　　　 ┃ + +
 *　　　　　　　┗━━┓　　　 ┏━┛
 *                              ┃　　    ┃
 *　　　　　　　　   ┃　　    ┃ + + + +
 *　　　　　　　　　┃　　　┃　Code is far away from     bug with the animal protecting
 *　　　　　　　　　┃　　　┃ + 　　　　         神兽保佑,代码无bug
 *　　　　　　　　　┃　　　┃
 *　　　　　　　　　┃　　　┃　　+
 *　　　　　　　　　┃　 　 ┗━━━┓ + +
 *　　　　　　　　　┃ 　　　　　┣┓
 *　　　　　　　　　┃ 　　　　　┏┛
 *　　　　　　　　　┗┓┓┏━━━┳┓┏┛ + + + +
 *　　　　　　　　　 ┃┫┫　 ┃┫┫
 *　　　　　　　　　 ┗┻┛　 ┗┻┛+ + + +
 *                     ━━━━━━感觉萌萌哒━━━━━━
 */
 /*
 //#pragma once
 //#include<qdebug.h>
 //#include <QtWidgets/QWidget>
 //#include<qthread.h>
 //#include<vector>
 //#include<qsemaphore.h>
 //#pragma execution_character_set("utf-8")
 // //class Worker : public QObject
 // //{
 // //	Q_OBJECT
 // //
 // //public slots:
 // //	void doWork(const QString &parameter) {
 // //		QString result;
 // //		qDebug() << "工作进行";
 // //		/* ... here is the expensive or blocking operation ... */
 // //		emit resultReady(result);
 // //	}
 // //
 // //signals:
 // //	void resultReady(const QString &result);
 // //};
 // //
 // //class Controller : public QObject
 // //{
 // //	Q_OBJECT
 // //		QThread workerThread;
 // //public:
 // //	Controller() {
 // //		Worker *worker = new Worker;
 // //		worker->moveToThread(&workerThread);
 // //		connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
 // //		connect(this, &Controller::operate, worker, &Worker::doWork);
 // //		connect(worker, &Worker::resultReady, this, &Controller::handleResults);
 // //		workerThread.start();
 // //		qDebug() << "线程开启";
 // //	}
 // //	~Controller() {
 // //		workerThread.quit();//线程完成
 // //		workerThread.wait();//阻止线程
 // //	}
 // //public slots:
 // //	void handleResults(const QString &) {
 // //		qDebug() << "获得controll进行";
 // //	};
 // //signals:
 // //	void operate(const QString &);
 // //};
 //
 // //线程试验  生成者 与 消费者
 // //消费 者5-10
 // //生成者 7
 //constexpr int buffsize = 5;
 //QSemaphore freeBytes(buffsize);
 //QSemaphore useBytes;
 //QString buff = QString(buffsize, 0);//共用的量
 //QString ppx{ "1234" };
 //class Producer :public QThread
 //{
 //public:
 //	Producer();
 //	~Producer();
 //	void run()
 //	{
 //		constexpr int DataSize = 7;
 //		for (size_t i = 0; i < DataSize; i++)
 //		{
 //			freeBytes.acquire();
 //			auto sd = ppx[qrand() % 4];
 //			buff.append(sd);
 //			qDebug() << "生产者的最近的生成" << sd;
 //			useBytes.release();
 //		}
 //	}
 //private:
 //};
 //
 //Producer::Producer()
 //{
 //}
 //
 //Producer::~Producer()
 //{
 //}
 //
 //class Consumer :public QThread
 //{
 //public:
 //	Consumer();
 //	~Consumer();
 //	void run() {
 //		constexpr int useDate = 10;
 //		for (size_t i = 0; i < useDate; i++)
 //		{
 //			useBytes.acquire();
 //			qDebug() << "现在的需求";
 //			freeBytes.release();
 //		}
 //	}
 //};
 //
 //Consumer::Consumer()
 //{
 //}
 //
 //Consumer::~Consumer()
 //{
 //	QString name = R"(dsd)";
 //	name.ds
 //}*/

//#pragma once
//#include<qdebug.h>
//#include <QtWidgets/QWidget>
//#include<qthread.h>
//#include<vector>
//#include<qstring.h>
//#include<qsemaphore.h>
//#include<qmutex.h>
//#pragma execution_character_set("utf-8")
//class Thread : public QThread
//{
//public:
//	Thread()
//	{
//	}
//
//	~Thread()
//	{
//	}
//	void run() override {/*
//		while (!stopped)
//		{
//			qDebug() << message;
//		}
//		stopped = false;*/
//		//使用mutex来进行保护 stopped变量
//		forever{
//			QMutexLocker locker(&mutex);
//			mutex.lock();
//		if (stopped) {	
//			stopped = false;
//			mutex.unlock();
//			break;
//		}
//		mutex.unlock();
//		qDebug() << "锁打开";
//		}
//	}
//	/*void constTest()const {
//		i=i+1;
//	}*/
//	void SetMessage(const QString &msg);
//	void stop();
//private:
//	QString message = "此处设置为错误信息提示";
//	volatile bool stopped = false;
//	mutable QMutex mutex;//mutable使其在const 函数中被修改
//};
#include<qdebug.h>
#include<qdir.h>
#include<qstring.h>
#include<qstringlist.h>
#include<qfiledialog.h>
#include<qmap.h>
#include<QTime>
#include<qlist.h>
#include<qtextstream.h>

