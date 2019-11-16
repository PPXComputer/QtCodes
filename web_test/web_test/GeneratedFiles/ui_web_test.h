/********************************************************************************
** Form generated from reading UI file 'web_test.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEB_TEST_H
#define UI_WEB_TEST_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_web_testClass
{
public:
    QGridLayout *gridLayout;
    QPushButton *forward;
    QPushButton *back;
    QLineEdit *edit;
    QPushButton *enter;
    QWebEngineView *View;

    void setupUi(QWidget *web_testClass)
    {
        if (web_testClass->objectName().isEmpty())
            web_testClass->setObjectName(QStringLiteral("web_testClass"));
        web_testClass->resize(880, 629);
        gridLayout = new QGridLayout(web_testClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        forward = new QPushButton(web_testClass);
        forward->setObjectName(QStringLiteral("forward"));

        gridLayout->addWidget(forward, 0, 0, 1, 1);

        back = new QPushButton(web_testClass);
        back->setObjectName(QStringLiteral("back"));

        gridLayout->addWidget(back, 0, 1, 1, 1);

        edit = new QLineEdit(web_testClass);
        edit->setObjectName(QStringLiteral("edit"));

        gridLayout->addWidget(edit, 0, 2, 1, 1);

        enter = new QPushButton(web_testClass);
        enter->setObjectName(QStringLiteral("enter"));

        gridLayout->addWidget(enter, 0, 3, 1, 1);

        View = new QWebEngineView(web_testClass);
        View->setObjectName(QStringLiteral("View"));
        View->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(View, 1, 0, 1, 4);


        retranslateUi(web_testClass);
        QObject::connect(forward, SIGNAL(clicked(bool)), View, SLOT(forward()));
        QObject::connect(back, SIGNAL(clicked(bool)), View, SLOT(back()));
        QObject::connect(enter, SIGNAL(clicked(bool)), View, SLOT(reload()));

        QMetaObject::connectSlotsByName(web_testClass);
    } // setupUi

    void retranslateUi(QWidget *web_testClass)
    {
        web_testClass->setWindowTitle(QApplication::translate("web_testClass", "web_test", Q_NULLPTR));
        forward->setText(QApplication::translate("web_testClass", "forward", Q_NULLPTR));
        back->setText(QApplication::translate("web_testClass", "back", Q_NULLPTR));
        enter->setText(QApplication::translate("web_testClass", "\350\277\233\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class web_testClass: public Ui_web_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEB_TEST_H
