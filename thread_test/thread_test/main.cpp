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
 *                �������������о������թ�����������
 */
 //
 //#include<stdio.h>
 //#include<stdio.h>
 //#include "thread_test.h"
 //#include <QtWidgets/QApplication>
 //#include<QtGuiClass.h>
 //#include<QtConcurrent>
 //
 //QStringList findFiles(const QString&dirS, QStringList filters)
 //{
 //	QStringList filename;
 //	QDir dir(dirS);
 //	foreach(QString file, dir.entryList(filters, (QDir::Filter::Files)))
 //		filename += dirS + '/' + file;
 //	foreach(QString dirPart, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot))
 //		foreach(auto& sd, findFiles(dirS + '/' + dirPart, filters)) {
 //		filename += sd;
 //	}
 //	return filename;
 //}
 //typedef QMap<QString , int> WordCount  ;
 //
 //// ���̵߳��ʼ���������
 //WordCount singleThreadedWordCount(QStringList files)
 //{
 //	WordCount wordCount;
 //	foreach(QString file, files) {
 //		QFile f(file);
 //		f.open(QIODevice::ReadOnly);
 //		QTextStream textStream(&f);
 //		while (textStream.atEnd() == false)
 //			foreach(const QString &word, textStream.readLine().split(' '))
 //			wordCount[word] += 1;
 //
 //	}
 //	return wordCount;
 //}
 //
 //
 //WordCount CountWords(const QString& filename)
 //{
 //	QFile file(filename);
 //	file.open(QFile::ReadOnly);
 //	QTextStream stream(&file);
 //	WordCount count;
 //	while (!stream.atEnd())
 //	{
 //		foreach(auto & word, stream.readLine().split(' '))
 //			count[word] += 1;
 //	}
 //	return count;
 //}
 //void reduce(WordCount &result, const WordCount &w)
 //{
 //	QMapIterator< QString ,int> i(w);
 //	while (i.hasNext()) {
 //		i.next();
 //		result[i.key()] += i.value();
 //	}
 //}
 //
 //int main(int argc, char *argv[])
 //{
 //	QApplication a(argc, argv);
 //	qDebug() << "finding files...";
 //	QStringList files = findFiles("F:\\Csgo", QStringList() << "*.cpp" << "*.h");
 //	qDebug() << files.count() << "files";
 //	//Consumer consumer;
 //	//Producer producer;
 //	//producer.start();
 //	//consumer.start();
 //	//producer.wait();
 //	//consumer.wait();
 //	/*QtGuiClass m;
 //	m.show();*/
 //	int singleThreadTime = 0;
 //	{
 //		QTime time;
 //		time.start();
 //		// ���߳�ͳ�ƣ��� mapreduce ����ʵ�ֵ����Ա�
 //		WordCount total = singleThreadedWordCount(files);
 //		singleThreadTime = time.elapsed();
 //		// ��ӡ�����ķѵ�ʱ��
 //		qDebug() << "single thread" << singleThreadTime;
 //	}
 //
 //	int mapReduceTime = 0;
 //	{
 //		QTime time;
 //		time.start();
 //		// mappedReduced ��ʽ����ͳ��qtconcurrent
 //		WordCount total = QtConcurrent::mappedReduced(files, CountWords, reduce);
 //		mapReduceTime = time.elapsed();
 //		qDebug() << "MapReduce" << mapReduceTime;
 //	}
 //	// ��� mappedReduced ��ʽ�ȵ��̴߳���ʽҪ��ı���
 //	qDebug() << "MapReduce speedup x" << ((double)singleThreadTime - (double)mapReduceTime) / (double)mapReduceTime + 1;
 //	return a.exec();
 //}
#include<qthread.h>
#include<qprogressbar.h>
#include<qpushbutton.h>
#include< QVBoxLayout>
#include<qdebug.h>
#include<qwidget.h>
#include <QtWidgets/QApplication>
#pragma execution_character_set("utf-8")

//class WorkerThread : public QThread
//{
//	Q_OBJECT
//
//public:
//	explicit WorkerThread(QObject *parent = 0)
//		: QThread(parent)
//	{
//		qDebug() << "Worker Thread : " << QThread::currentThreadId();
//	}
//	void run() override{
//		qDebug() << "Worker Run Thread : " << QThread::currentThreadId();
//		int nValue = 0;
//		while (nValue < 100)
//		{
//			// ����50����
//			msleep(50);
//			++nValue;
//
//			// ׼������
//			emit resultReady(nValue);
//		}
//	}
//signals:
//	void resultReady(int value);
//};
class WorkerThread : public QThread
{
	Q_OBJECT

public:
	explicit WorkerThread(QObject* parent = 0)
		: QThread(parent)
	{
		qDebug() << "Worker Thread : " << QThread::currentThreadId();
	}

protected:
	virtual void run() Q_DECL_OVERRIDE {
		qDebug() << "Worker Run Thread : " << QThread::currentThreadId();
		int nValue = 0;
		while (nValue < 100)
		{
			// ����50����
			msleep(50);
			++nValue;

			// ׼������
			emit resultReady(nValue);
		}
	}
signals:
	void resultReady(int value);
};

//class MainWindow : public QWidget{
//	Q_OBJECT
//public:
//	explicit MainWindow(QWidget *parent = 0)
//		: QWidget(parent)
//	{
//		qDebug() << "Main Thread : " << QThread::currentThreadId();
//
//		// ������ʼ��ť��������
//		QPushButton *pStartButton = new QPushButton(this);
//		m_pProgressBar = new QProgressBar(this);
//
//		//�����ı���������ȡֵ��Χ
//		pStartButton->setText(QString::fromLocal8Bit("��ʼ"));
//		m_pProgressBar->setFixedHeight(25);
//		m_pProgressBar->setRange(0, 100);
//		m_pProgressBar->setValue(0);
//
//		QVBoxLayout *pLayout = new QVBoxLayout();
//		pLayout->addWidget(pStartButton, 0, Qt::AlignHCenter);
//		pLayout->addWidget(m_pProgressBar);
//		pLayout->setSpacing(50);
//		pLayout->setContentsMargins(10, 10, 10, 10);
//		setLayout(pLayout);
//
//		// �����źŲ�
//		auto sd=connect(pStartButton, &QPushButton::clicked, this, &MainWindow::startThread);
//	}
//	~MainWindow() {}
//
//private slots:
//	// ���½���
//	void handleResults(int value)
//	{
//		qDebug() << "Handle Thread : " << QThread::currentThreadId();
//		m_pProgressBar->setValue(value);
//	}
//	// �����߳�
//	void startThread()
//	{
//		auto workThead = new WorkerThread(this);
//		connect(workThead,&WorkerThread::resultReady, this, &MainWindow::handleResults);
//		// �߳̽������Զ�����
//		connect(workThead,&QThread::finished, workThead, &QObject::deleteLater);
//		workThead->start();
//	}
//
//private:
//	QProgressBar *m_pProgressBar;
//	WorkerThread m_WorkThead;
//};
class MainWindowsd : public QWidget
{
	Q_OBJECT

public:
	explicit MainWindowsd(QWidget* parent = 0)
		: QWidget(parent)
	{
		qDebug() << "Main Thread : " << QThread::currentThreadId();

		// ������ʼ��ť��������
		QPushButton* pStartButton = new QPushButton(this);
		m_pProgressBar = new QProgressBar(this);

		//�����ı���������ȡֵ��Χ
		pStartButton->setText(QString::fromLocal8Bit("��ʼ"));
		m_pProgressBar->setFixedHeight(25);
		m_pProgressBar->setRange(0, 100);
		m_pProgressBar->setValue(0);

		QVBoxLayout* pLayout = new QVBoxLayout();
		pLayout->addWidget(pStartButton, 0, Qt::AlignHCenter);
		pLayout->addWidget(m_pProgressBar);
		pLayout->setSpacing(50);
		pLayout->setContentsMargins(10, 10, 10, 10);
		setLayout(pLayout);

		connect(&m_workerThread, &WorkerThread::resultReady, this, &MainWindowsd::handleResults);
		// �߳̽������Զ�����
		connect(&m_workerThread, &WorkerThread::finished, &m_workerThread, &MainWindowsd::deleteLater);
		// �����źŲ�
		connect(pStartButton, &QPushButton::clicked, this, &MainWindowsd::startThread);
	}

	~MainWindowsd() {}

private slots:
	// ���½���
	void handleResults(int value)
	{
		qDebug() << "Handle Thread : " << QThread::currentThreadId();
		m_pProgressBar->setValue(value);
	}

	// �����߳�
	void startThread()
	{
	}

private:
	QProgressBar* m_pProgressBar;
	WorkerThread m_workerThread;
};
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindowsd sd;
	sd.show();
	return a.exec();
}