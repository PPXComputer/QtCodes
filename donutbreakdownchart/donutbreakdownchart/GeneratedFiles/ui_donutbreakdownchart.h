/********************************************************************************
** Form generated from reading UI file 'donutbreakdownchart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONUTBREAKDOWNCHART_H
#define UI_DONUTBREAKDOWNCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qcharview.h>

QT_BEGIN_NAMESPACE

class Ui_donutbreakdownchartClass
{
public:
    QCharView *graphicsView;

    void setupUi(QWidget *donutbreakdownchartClass)
    {
        if (donutbreakdownchartClass->objectName().isEmpty())
            donutbreakdownchartClass->setObjectName(QStringLiteral("donutbreakdownchartClass"));
        donutbreakdownchartClass->resize(600, 400);
        graphicsView = new QCharView(donutbreakdownchartClass);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(100, 100, 256, 192));

        retranslateUi(donutbreakdownchartClass);

        QMetaObject::connectSlotsByName(donutbreakdownchartClass);
    } // setupUi

    void retranslateUi(QWidget *donutbreakdownchartClass)
    {
        donutbreakdownchartClass->setWindowTitle(QApplication::translate("donutbreakdownchartClass", "donutbreakdownchart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class donutbreakdownchartClass: public Ui_donutbreakdownchartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONUTBREAKDOWNCHART_H
