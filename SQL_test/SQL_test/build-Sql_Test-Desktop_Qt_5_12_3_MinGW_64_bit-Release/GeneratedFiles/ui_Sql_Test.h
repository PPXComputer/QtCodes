/********************************************************************************
** Form generated from reading UI file 'Sql_Test.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQL_TEST_H
#define UI_SQL_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sql_TestClass
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *NumberEdit;
    QLineEdit *AgeEdit;
    QLabel *label_2;
    QLineEdit *NameEdit;
    QLabel *label;
    QTextEdit *sql_Edit;
    QTableView *tableView;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QPushButton *Insert;
    QPushButton *Clean;
    QPushButton *Search;
    QPushButton *Delete;
    QPushButton *sql_words;

    void setupUi(QWidget *Sql_TestClass)
    {
        if (Sql_TestClass->objectName().isEmpty())
            Sql_TestClass->setObjectName(QString::fromUtf8("Sql_TestClass"));
        Sql_TestClass->resize(839, 672);
        gridLayout_2 = new QGridLayout(Sql_TestClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(Sql_TestClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        NumberEdit = new QLineEdit(Sql_TestClass);
        NumberEdit->setObjectName(QString::fromUtf8("NumberEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NumberEdit->sizePolicy().hasHeightForWidth());
        NumberEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, NumberEdit);

        AgeEdit = new QLineEdit(Sql_TestClass);
        AgeEdit->setObjectName(QString::fromUtf8("AgeEdit"));
        sizePolicy.setHeightForWidth(AgeEdit->sizePolicy().hasHeightForWidth());
        AgeEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, AgeEdit);

        label_2 = new QLabel(Sql_TestClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        NameEdit = new QLineEdit(Sql_TestClass);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));
        sizePolicy.setHeightForWidth(NameEdit->sizePolicy().hasHeightForWidth());
        NameEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, NameEdit);

        label = new QLabel(Sql_TestClass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);

        sql_Edit = new QTextEdit(Sql_TestClass);
        sql_Edit->setObjectName(QString::fromUtf8("sql_Edit"));
        sizePolicy.setHeightForWidth(sql_Edit->sizePolicy().hasHeightForWidth());
        sql_Edit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(sql_Edit);

        tableView = new QTableView(Sql_TestClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSortingEnabled(false);

        verticalLayout->addWidget(tableView);

        textEdit = new QTextEdit(Sql_TestClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        textEdit->setFont(font);
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 5);
        verticalLayout->setStretch(3, 1);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Insert = new QPushButton(Sql_TestClass);
        Insert->setObjectName(QString::fromUtf8("Insert"));

        gridLayout->addWidget(Insert, 0, 0, 1, 1);

        Clean = new QPushButton(Sql_TestClass);
        Clean->setObjectName(QString::fromUtf8("Clean"));

        gridLayout->addWidget(Clean, 4, 0, 1, 1);

        Search = new QPushButton(Sql_TestClass);
        Search->setObjectName(QString::fromUtf8("Search"));

        gridLayout->addWidget(Search, 2, 0, 1, 1);

        Delete = new QPushButton(Sql_TestClass);
        Delete->setObjectName(QString::fromUtf8("Delete"));

        gridLayout->addWidget(Delete, 1, 0, 1, 1);

        sql_words = new QPushButton(Sql_TestClass);
        sql_words->setObjectName(QString::fromUtf8("sql_words"));

        gridLayout->addWidget(sql_words, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(NumberEdit);
        label_2->setBuddy(AgeEdit);
        label->setBuddy(NameEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Sql_TestClass);

        QMetaObject::connectSlotsByName(Sql_TestClass);
    } // setupUi

    void retranslateUi(QWidget *Sql_TestClass)
    {
        Sql_TestClass->setWindowTitle(QApplication::translate("Sql_TestClass", "Sql_Test", nullptr));
        label_3->setText(QApplication::translate("Sql_TestClass", "\345\255\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Sql_TestClass", "\345\271\264\351\276\204", nullptr));
        label->setText(QApplication::translate("Sql_TestClass", "\345\220\215\345\255\227", nullptr));
        textEdit->setDocumentTitle(QString());
        Insert->setText(QApplication::translate("Sql_TestClass", "\346\217\222\345\205\245", nullptr));
        Clean->setText(QApplication::translate("Sql_TestClass", "\346\270\205\347\251\272", nullptr));
        Search->setText(QApplication::translate("Sql_TestClass", "\346\237\245\350\257\242", nullptr));
        Delete->setText(QApplication::translate("Sql_TestClass", "\345\210\240\351\231\244", nullptr));
        sql_words->setText(QApplication::translate("Sql_TestClass", "SQL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sql_TestClass: public Ui_Sql_TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQL_TEST_H
