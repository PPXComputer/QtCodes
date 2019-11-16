/********************************************************************************
** Form generated from reading UI file 'drop_test.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROP_TEST_H
#define UI_DROP_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drop_testClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *drop_testClass)
    {
        if (drop_testClass->objectName().isEmpty())
            drop_testClass->setObjectName(QStringLiteral("drop_testClass"));
        drop_testClass->resize(600, 400);
        centralWidget = new QWidget(drop_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        drop_testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(drop_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        drop_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(drop_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        drop_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(drop_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        drop_testClass->setStatusBar(statusBar);

        retranslateUi(drop_testClass);

        QMetaObject::connectSlotsByName(drop_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *drop_testClass)
    {
        drop_testClass->setWindowTitle(QApplication::translate("drop_testClass", "drop_test", Q_NULLPTR));
        pushButton->setText(QApplication::translate("drop_testClass", "Start A", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("drop_testClass", "Start B", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("drop_testClass", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class drop_testClass: public Ui_drop_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROP_TEST_H
