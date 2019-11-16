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

// �ݹ������ļ�
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

// ���̵߳��ʼ���������
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

// countWords ���㵥���ļ��ĵ��������ú����ɶ���̲߳��е��ã����ұ������̰߳�ȫ�ġ�
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

// reduce �� map �Ľ����ӵ����ս�����ú���ֻ����һ���߳�һ�ε��á�
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
		// ���߳�ͳ�ƣ��� mapreduce ����ʵ�ֵ����Ա�
		WordCount total = singleThreadedWordCount(files);
		singleThreadTime = time.elapsed();
		// ��ӡ�����ķѵ�ʱ��
		qDebug() << "single thread" << singleThreadTime;
	}
	QThreadPool ThreadPool;
	qDebug()<<ThreadPool.maxThreadCount();

	//int mapReduceTime = 0;
	//{
	//	QTime time;
	//	time.start();
	//	// mappedReduced ��ʽ����ͳ��
	//	//���߳̿��ܻ�cpu���ɹ���
	//	WordCount total = mappedReduced(files, countWords, reduce);
	//	mapReduceTime = time.elapsed();
	//	qDebug() << "MapReduce" << mapReduceTime;
	//}
	//// ��� mappedReduced ��ʽ�ȵ��̴߳���ʽҪ��ı���
	//qDebug() << "MapReduce speedup x" << ((double)singleThreadTime - (double)mapReduceTime) / (double)mapReduceTime + 1;
}

