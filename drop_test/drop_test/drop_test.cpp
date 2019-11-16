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
#include "drop_test.h"
drop_test::drop_test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	threadA.setMessage("A");
	threadB.setMessage("B");
	connect(ui.pushButton, &QPushButton::clicked, &threadA, [this]() {
		stopOrstart(threadA);
	});
	connect(ui.pushButton_2, &QPushButton::clicked, &threadB, [this]() {
		stopOrstart(threadB);
	});
	connect(ui.pushButton_3, &QPushButton::clicked, this, [this]() {
		this->threadA.wait();
		this->threadB.wait();
	});
}

//void drop_test::dragEnterEvent(QDragEnterEvent *event)
//{
//	if (event->mimeData()->hasFormat("text/uri-list"))
//	{
//		event->acceptProposedAction();
//	}
//	return QMainWindow::dragEnterEvent(event);
//}
//
//void drop_test::dropEvent(QDropEvent *event)
//{
//	QList<QUrl> urls = event->mimeData()->urls();
//	if (urls.isEmpty()) return;
//	auto fileName = urls.first().toLocalFile();
//	if (!QFile::exists(fileName))return;
//	this->setWindowTitle(QString("%1 �Ѿ����� ").arg(fileName));
//}