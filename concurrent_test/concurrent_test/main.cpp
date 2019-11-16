//#include "concurrent_test.h"
#include <QtWidgets/QApplication>
#include <QList>
#include <QMap>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QTime>
#include <QApplication>
#include <QDebug>
#include <qtconcurrentmap.h>

using namespace QtConcurrent;

// 递归搜索文件
QStringList findFiles(const QString& startDir, QStringList filters)
{
	QStringList names;
	QDir dir(startDir);

	foreach(QString file, dir.entryList(filters, QDir::Files))
		names += startDir + '/' + file;

	foreach(QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot))
		names += findFiles(startDir + '/' + subdir, filters);
	return names;
}

typedef QMap<QString, int> WordCount;

// 单线程单词计数器函数
WordCount singleThreadedWordCount(QStringList files)
{
	WordCount wordCount;
	foreach(QString file, files) {
		QFile f(file);
		f.open(QIODevice::ReadOnly);
		QTextStream textStream(&f);
		while (textStream.atEnd() == false)
			foreach(const QString & word, textStream.readLine().split(' '))
			wordCount[word] += 1;
	}
	return wordCount;
}

// countWords 计算单个文件的单词数，该函数由多个线程并行调用，并且必须是线程安全的。
WordCount countWords(const QString & file)
{
	QFile f(file);
	f.open(QIODevice::ReadOnly);
	QTextStream textStream(&f);
	WordCount wordCount;

	while (textStream.atEnd() == false)
		foreach(const QString & word, textStream.readLine().split(' '))
		wordCount[word] += 1;

	return wordCount;
}

// reduce 将 map 的结果添加到最终结果，该函数只能由一个线程一次调用。
void reduce(WordCount & result, const WordCount & w)
{
	QMapIterator<QString, int> i(w);
	while (i.hasNext()) {
		i.next();
		result[i.key()] += i.value();
	}
}

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	qDebug() << "finding files...";
	QStringList files = findFiles("../../", QStringList() << "*.cpp" << "*.h");
	qDebug() << files.count() << "files";

	int singleThreadTime = 0;
	{
		QTime time;
		time.start();
		// 单线程统计，与 mapreduce 机制实现的作对比
		WordCount total = singleThreadedWordCount(files);
		singleThreadTime = time.elapsed();
		// 打印出所耗费的时间
		qDebug() << "single thread" << singleThreadTime;
	}
	QThreadPool ThreadPool;
	qDebug()<<ThreadPool.maxThreadCount();

	//int mapReduceTime = 0;
	//{
	//	QTime time;
	//	time.start();
	//	// mappedReduced 方式进行统计
	//	//多线程可能会cpu负荷过大
	//	WordCount total = mappedReduced(files, countWords, reduce);
	//	mapReduceTime = time.elapsed();
	//	qDebug() << "MapReduce" << mapReduceTime;
	//}
	//// 输出 mappedReduced 方式比单线程处理方式要快的倍数
	//qDebug() << "MapReduce speedup x" << ((double)singleThreadTime - (double)mapReduceTime) / (double)mapReduceTime + 1;
}

