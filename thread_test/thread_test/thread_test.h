/**
 *                 ���������������޳�û������������
 *�������������� ����       ����+ +
 *�������������������ߩ����������������ߩ� + +
 *���������������������������� ��
 *�������������������������������� ++ + + +
 *������������ ����������������������  ��+
 *���������������������������� �� +
 *�����������������������ߡ�������
 *���������������������������� �� + +
 *���������������������������� ������
 *                              ������    ��
 *����������������   ������    �� + + + +
 *������������������������������Code is far away from     bug with the animal protecting
 *���������������������������� + ��������         ���ޱ���,������bug
 *����������������������������
 *��������������������������������+
 *���������������������� �� ���������� + +
 *�������������������� �����������ǩ�
 *�������������������� ��������������
 *���������������������������������ש����� + + + +
 *������������������ ���ϩϡ� ���ϩ�
 *������������������ ���ߩ��� ���ߩ�+ + + +
 *                     �������������о������թ�����������
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
 // //		qDebug() << "��������";
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
 // //		qDebug() << "�߳̿���";
 // //	}
 // //	~Controller() {
 // //		workerThread.quit();//�߳����
 // //		workerThread.wait();//��ֹ�߳�
 // //	}
 // //public slots:
 // //	void handleResults(const QString &) {
 // //		qDebug() << "���controll����";
 // //	};
 // //signals:
 // //	void operate(const QString &);
 // //};
 //
 // //�߳�����  ������ �� ������
 // //���� ��5-10
 // //������ 7
 //constexpr int buffsize = 5;
 //QSemaphore freeBytes(buffsize);
 //QSemaphore useBytes;
 //QString buff = QString(buffsize, 0);//���õ���
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
 //			qDebug() << "�����ߵ����������" << sd;
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
 //			qDebug() << "���ڵ�����";
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
//		//ʹ��mutex�����б��� stopped����
//		forever{
//			QMutexLocker locker(&mutex);
//			mutex.lock();
//		if (stopped) {	
//			stopped = false;
//			mutex.unlock();
//			break;
//		}
//		mutex.unlock();
//		qDebug() << "����";
//		}
//	}
//	/*void constTest()const {
//		i=i+1;
//	}*/
//	void SetMessage(const QString &msg);
//	void stop();
//private:
//	QString message = "�˴�����Ϊ������Ϣ��ʾ";
//	volatile bool stopped = false;
//	mutable QMutex mutex;//mutableʹ����const �����б��޸�
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

