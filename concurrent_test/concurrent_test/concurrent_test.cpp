#include "concurrent_test.h"
#pragma execution_character_set("utf-8")

concurrent_test::concurrent_test(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	qDebug() << "��ʼ���߳̽���ͳ��";
	QString dir(R"(F:\\Csgo)");
	QStringList filtes;
	filtes<<" * .cpp"<<" * .h" ;
	auto& sd = filenames(dir, filtes);
	QTime first;
	first.start();
	//ʹ�õ��߳̽���ͳ��
	for (auto& s : sd) {
		countWords(s);
	}
	int timeFirst = first.elapsed();
	qDebug() << timeFirst;
	QTime second;
	second.start();
	//ʹ�õ��߳̽���ͳ��
	map(sd, countWords);
	int timesecond = second.elapsed();
	qDebug() << timesecond;
	//����QtConcurrent���
	//�͵ع��������ͺ���
	//map(container<T> , function)  functionΪ u fuction( 

}