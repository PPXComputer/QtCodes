#pragma once

#include <QtWidgets/QWidget>
#include "ui_concurrent_test.h"
#include<qlist.h>
#include<qvector.h>
#include<QtConcurrent>
#include<QTime>
#include<qdebug.h>
#include<qfile.h>
using namespace QtConcurrent;
using map_count=QMap<QString ,int>;
inline	int countWords(QString& FileName)
	{
		map_count count;
		QFile file{FileName};
			if (file.open(QIODevice::ReadOnly))
			{
				QTextStream line(&file);
				while (!line.atEnd())
				{
					for (auto& lineString : line.readLine().split(' '))
					{
						count[lineString] += 1;
					}
				}
				file.close();
		}
		int count_words = 0;
		for (auto& sd : count)
		{
			count_words += sd;
		}
		return count_words;
	}
class concurrent_test : public QWidget
{
	Q_OBJECT

public:
	concurrent_test(QWidget *parent = Q_NULLPTR);
	void SetVector(QVector<int>& sd)
	{
		for (size_t i = 0; i < VectorSize; i++)
		{
			QVector <int >sd;
			for (size_t i = 0; i < VectorSize; i++)
			{
				sd.push_back(i);
			}
			ppx.push_back(sd);
		}
	}
	void reduce(const QVector<int >& sd) = delete;
private:
	Ui::concurrent_testClass ui;
	int VectorSize = 10;
	QVector<QVector<int> >ppx;
};
inline QStringList filenames( QString& Qdir, const QStringList& filters)
{
	QStringList fileName;
	QDir dir(Qdir);
	for (auto& file : dir.entryList(filters,QDir::Files)) {
		fileName += Qdir+'/'+file;
	}
	foreach(QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot))
		fileName += filenames(QString(Qdir + '/' + subdir), filters);
	
	return fileName;
}
