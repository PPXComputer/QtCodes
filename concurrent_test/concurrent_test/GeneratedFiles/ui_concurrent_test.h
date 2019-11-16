/********************************************************************************
** Form generated from reading UI file 'concurrent_test.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONCURRENT_TEST_H
#define UI_CONCURRENT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_concurrent_testClass
{
public:

    void setupUi(QWidget *concurrent_testClass)
    {
        if (concurrent_testClass->objectName().isEmpty())
            concurrent_testClass->setObjectName(QStringLiteral("concurrent_testClass"));
        concurrent_testClass->resize(600, 400);

        retranslateUi(concurrent_testClass);

        QMetaObject::connectSlotsByName(concurrent_testClass);
    } // setupUi

    void retranslateUi(QWidget *concurrent_testClass)
    {
        concurrent_testClass->setWindowTitle(QApplication::translate("concurrent_testClass", "concurrent_test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class concurrent_testClass: public Ui_concurrent_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONCURRENT_TEST_H
