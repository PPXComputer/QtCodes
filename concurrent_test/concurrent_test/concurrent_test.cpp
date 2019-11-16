#include "concurrent_test.h"
#pragma execution_character_set("utf-8")

concurrent_test::concurrent_test(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	qDebug() << "开始主线程进行统计";
	QString dir(R"(F:\\Csgo)");
	QStringList filtes;
	filtes<<" * .cpp"<<" * .h" ;
	auto& sd = filenames(dir, filtes);
	QTime first;
	first.start();
	//使用单线程进行统计
	for (auto& s : sd) {
		countWords(s);
	}
	int timeFirst = first.elapsed();
	qDebug() << timeFirst;
	QTime second;
	second.start();
	//使用单线程进行统计
	map(sd, countWords);
	int timesecond = second.elapsed();
	qDebug() << timesecond;
	//对于QtConcurrent框架
	//就地管理容器和函数
	//map(container<T> , function)  function为 u fuction( 

}