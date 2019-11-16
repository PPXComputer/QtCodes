/********************************************************************************
** Form generated from reading UI file 'tomato.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOMATO_H
#define UI_TOMATO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tomatoClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *tomatoClass)
    {
        if (tomatoClass->objectName().isEmpty())
            tomatoClass->setObjectName(QStringLiteral("tomatoClass"));
        tomatoClass->setWindowModality(Qt::ApplicationModal);
        tomatoClass->resize(117, 70);
        tomatoClass->setMouseTracking(true);
        tomatoClass->setTabletTracking(true);
        verticalLayout = new QVBoxLayout(tomatoClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(tomatoClass);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        retranslateUi(tomatoClass);

        QMetaObject::connectSlotsByName(tomatoClass);
    } // setupUi

    void retranslateUi(QWidget *tomatoClass)
    {
        tomatoClass->setWindowTitle(QApplication::translate("tomatoClass", "tomato", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        tomatoClass->setWhatsThis(QApplication::translate("tomatoClass", "\350\277\231\346\230\257\344\270\200\344\270\252\347\210\266\347\252\227\345\217\243\350\277\233\350\241\214\346\222\255\346\224\276GIF", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("tomatoClass", "\350\277\231\346\230\257\344\270\200\344\270\252\345\212\250\345\233\276(\344\274\232\345\217\230\345\214\226\347\232\204\345\223\246)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setProperty("Text", QVariant(QApplication::translate("tomatoClass", "TextLabel", Q_NULLPTR)));
    } // retranslateUi

};

namespace Ui {
    class tomatoClass: public Ui_tomatoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOMATO_H
