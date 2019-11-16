/********************************************************************************
** Form generated from reading UI file 'chart_theme_test.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHART_THEME_TEST_H
#define UI_CHART_THEME_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chart_theme_testClass
{
public:

    void setupUi(QWidget *chart_theme_testClass)
    {
        if (chart_theme_testClass->objectName().isEmpty())
            chart_theme_testClass->setObjectName(QStringLiteral("chart_theme_testClass"));
        chart_theme_testClass->resize(600, 400);

        retranslateUi(chart_theme_testClass);

        QMetaObject::connectSlotsByName(chart_theme_testClass);
    } // setupUi

    void retranslateUi(QWidget *chart_theme_testClass)
    {
        chart_theme_testClass->setWindowTitle(QApplication::translate("chart_theme_testClass", "chart_theme_test", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chart_theme_testClass: public Ui_chart_theme_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHART_THEME_TEST_H
