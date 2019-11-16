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
 *                ━━━━━━感觉萌萌哒━━━━━━
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
 //// 单线程单词计数器函数
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
 //		// 单线程统计，与 mapreduce 机制实现的作对比
 //		WordCount total = singleThreadedWordCount(files);
 //		singleThreadTime = time.elapsed();
 //		// 打印出所耗费的时间
 //		qDebug() << "single thread" << singleThreadTime;
 //	}
 //
 //	int mapReduceTime = 0;
 //	{
 //		QTime time;
 //		time.start();
 //		// mappedReduced 方式进行统计qtconcurrent
 //		WordCount total = QtConcurrent::mappedReduced(files, CountWords, reduce);
 //		mapReduceTime = time.elapsed();
 //		qDebug() << "MapReduce" << mapReduceTime;
 //	}
 //	// 输出 mappedReduced 方式比单线程处理方式要快的倍数
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
//			// 休眠50毫秒
//			msleep(50);
//			++nValue;
//
//			// 准备更新
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
			// 休眠50毫秒
			msleep(50);
			++nValue;

			// 准备更新
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
//		// 创建开始按钮、进度条
//		QPushButton *pStartButton = new QPushButton(this);
//		m_pProgressBar = new QProgressBar(this);
//
//		//设置文本、进度条取值范围
//		pStartButton->setText(QString::fromLocal8Bit("开始"));
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
//		// 连接信号槽
//		auto sd=connect(pStartButton, &QPushButton::clicked, this, &MainWindow::startThread);
//	}
//	~MainWindow() {}
//
//private slots:
//	// 更新进度
//	void handleResults(int value)
//	{
//		qDebug() << "Handle Thread : " << QThread::currentThreadId();
//		m_pProgressBar->setValue(value);
//	}
//	// 开启线程
//	void startThread()
//	{
//		auto workThead = new WorkerThread(this);
//		connect(workThead,&WorkerThread::resultReady, this, &MainWindow::handleResults);
//		// 线程结束后，自动销毁
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

		// 创建开始按钮、进度条
		QPushButton* pStartButton = new QPushButton(this);
		m_pProgressBar = new QProgressBar(this);

		//设置文本、进度条取值范围
		pStartButton->setText(QString::fromLocal8Bit("开始"));
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
		// 线程结束后，自动销毁
		connect(&m_workerThread, &WorkerThread::finished, &m_workerThread, &MainWindowsd::deleteLater);
		// 连接信号槽
		connect(pStartButton, &QPushButton::clicked, this, &MainWindowsd::startThread);
	}

	~MainWindowsd() {}

private slots:
	// 更新进度
	void handleResults(int value)
	{
		qDebug() << "Handle Thread : " << QThread::currentThreadId();
		m_pProgressBar->setValue(value);
	}

	// 开启线程
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