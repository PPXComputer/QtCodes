/********************************************************************************
** Form generated from reading UI file 'QtGuiClass.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICLASS_H
#define UI_QTGUICLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiClass
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *Button1;
    QPushButton *Button_2;
    QPushButton *Button_3;

    void setupUi(QWidget *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QStringLiteral("QtGuiClass"));
        QtGuiClass->resize(400, 300);
        horizontalLayout = new QHBoxLayout(QtGuiClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Button1 = new QPushButton(QtGuiClass);
        Button1->setObjectName(QStringLiteral("Button1"));

        horizontalLayout->addWidget(Button1);

        Button_2 = new QPushButton(QtGuiClass);
        Button_2->setObjectName(QStringLiteral("Button_2"));

        horizontalLayout->addWidget(Button_2);

        Button_3 = new QPushButton(QtGuiClass);
        Button_3->setObjectName(QStringLiteral("Button_3"));

        horizontalLayout->addWidget(Button_3);


        retranslateUi(QtGuiClass);

        QMetaObject::connectSlotsByName(QtGuiClass);
    } // setupUi

    void retranslateUi(QWidget *QtGuiClass)
    {
        QtGuiClass->setWindowTitle(QApplication::translate("QtGuiClass", "QtGuiClass", nullptr));
        Button1->setText(QApplication::translate("QtGuiClass", "Start  A", nullptr));
        Button_2->setText(QApplication::translate("QtGuiClass", "Start B", nullptr));
        Button_3->setText(QApplication::translate("QtGuiClass", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICLASS_H
