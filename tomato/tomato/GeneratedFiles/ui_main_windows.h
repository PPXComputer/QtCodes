/********************************************************************************
** Form generated from reading UI file 'main_windows.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOWS_H
#define UI_MAIN_WINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton_5;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widgetbox;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QCheckBox *checkBox;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *linechart;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    myview *graphicsView;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_add;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *add_item;
    QListWidget *listWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 700);
        MainWindow->setMinimumSize(QSize(900, 700));
        MainWindow->setMaximumSize(QSize(900, 700));
        MainWindow->setStyleSheet(QLatin1String(".QMainWidow{\n"
"background-color: rgb(223, 223, 223);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setStyleSheet(QLatin1String(".QWidget{\n"
"background-color: rgb(167, 205, 255);\n"
"\n"
"}/*\n"
"QPushButton{\n"
"  border-bottom:3px solid black;\n"
"	background:none;\n"
"    background: transparent;\n"
"selection-background-color:rgb(247, 184, 199);\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"background-color: rgb(255, 255, 255);\n"
"}*/\n"
"QPushButton\n"
"{ color: rgb(255, 255, 255);\n"
"	background-color: rgb(167, 205, 255);\n"
"	border:none;\n"
"    padding: 3px;\n"
"	font-family: \"Verdana\";\n"
"	font-size: 15px;\n"
"	text-align: center;\n"
"}\n"
"QPushButton:hover, QPushButton:pressed , QPushButton:checked\n"
"{background-color: rgb(85, 170, 255);\n"
"	text-align: right;\n"
"	padding-right: 20px;\n"
"	font-weight:100\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-image:url(:/tomato/Resources/appbar.navigate.next2.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
"QPushButton:pressed, QPushButton:checked\n"
"{\n"
"	background-image:url(:/tomato/Resources/appbar.navigate.next.png);\n"
"	backgr"
                        "ound-repeat:no-repeat;\n"
"	background-position: center left;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(60);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 20, 0, 200);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setBaseSize(QSize(0, 0));
        widget_4->setStyleSheet(QStringLiteral("QWidget::QLabel{border-bottom:1px solid lightgray;}"));
        verticalLayout_9 = new QVBoxLayout(widget_4);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        pushButton_5 = new QPushButton(widget_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background:none;\n"
"    background: transparent;\n"
"	bored :none;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background-color: rgb(179, 179, 179);\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tomato/E:/360downloads/Marketing Icon Set/PNG/48x48/Browser.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon);
        pushButton_5->setIconSize(QSize(48, 48));

        verticalLayout_9->addWidget(pushButton_5);

        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(40);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setStyleSheet(QString::fromUtf8("font: 13pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"background:none;"));
        label_7->setTextFormat(Qt::RichText);
        label_7->setAlignment(Qt::AlignJustify|Qt::AlignTop);

        verticalLayout_9->addWidget(label_7);


        verticalLayout->addWidget(widget_4);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);
        pushButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/icon/E:/360downloads/Marketing Icon Set/PNG/24x24/Idea.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setCheckable(true);
        pushButton->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy4.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy4);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/icon/E:/360downloads/Marketing Icon Set/PNG/24x24/Chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setCheckable(true);
        pushButton_2->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton_6 = new QPushButton(widget_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy4.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy4);
        pushButton_6->setMouseTracking(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/icon/E:/360downloads/Marketing Icon Set/PNG/24x24/Screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);
        pushButton_6->setCheckable(true);
        pushButton_6->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_6);

        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy4.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy4);
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        pushButton_4->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/tomato/E:/360downloads/Marketing Icon Set/PNG/48x48/Setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(16, 16));
        pushButton_4->setCheckable(true);
        pushButton_4->setAutoExclusive(true);

        verticalLayout->addWidget(pushButton_4);


        gridLayout->addWidget(widget_3, 0, 0, 3, 2);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setStyleSheet(QLatin1String("QFrame{\n"
"\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton{\n"
"border:none;\n"
"}"));
        horizontalLayout_10 = new QHBoxLayout(frame_3);
        horizontalLayout_10->setSpacing(20);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("font: 75 11pt \"Agency FB\";\n"
"border:0px"));

        horizontalLayout_10->addWidget(label_4);

        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/icon/E:/360downloads/Marketing Icon Set/PNG/24x24/Time.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon5);
        pushButton_3->setCheckable(true);
        pushButton_3->setAutoExclusive(true);

        horizontalLayout_10->addWidget(pushButton_3);

        pushButton_8 = new QPushButton(frame_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/icon/E:/360downloads/Marketing Icon Set/PNG/24x24/Mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);

        horizontalLayout_10->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(frame_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/icon/E:/360downloads/Marketing Icon Set/PNG/24x24/Target.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon7);

        horizontalLayout_10->addWidget(pushButton_7);

        horizontalLayout_10->setStretch(0, 15);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 1);
        horizontalLayout_10->setStretch(3, 1);

        gridLayout->addWidget(frame_3, 1, 2, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy5);
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border:none;"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral("QScrollArea{border:0px}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 797, 642));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widgetbox = new QWidget(scrollAreaWidgetContents_2);
        widgetbox->setObjectName(QStringLiteral("widgetbox"));
        horizontalLayout_3 = new QHBoxLayout(widgetbox);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 10, -1, -1);
        comboBox = new QComboBox(widgetbox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFrame(false);

        horizontalLayout_3->addWidget(comboBox);

        comboBox_2 = new QComboBox(widgetbox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_3->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(widgetbox);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        sizePolicy2.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(comboBox_3);

        checkBox = new QCheckBox(widgetbox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        horizontalLayout_3->addWidget(checkBox);

        widget_2 = new QWidget(widgetbox);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));

        horizontalLayout_3->addWidget(widget_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout_6->addWidget(widgetbox);

        linechart = new QVBoxLayout();
        linechart->setObjectName(QStringLiteral("linechart"));

        verticalLayout_6->addLayout(linechart);

        verticalLayout_6->setStretch(1, 7);
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_5->addWidget(scrollArea);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(page_2);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        graphicsView = new myview(widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QLatin1String("QGraphicsView\n"
"{\n"
"border:0px\n"
"	background-color: rgb(65, 109, 253);\n"
"}"));

        verticalLayout_4->addWidget(graphicsView);


        verticalLayout_3->addWidget(widget);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_add = new QWidget(page_3);
        widget_add->setObjectName(QStringLiteral("widget_add"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(widget_add->sizePolicy().hasHeightForWidth());
        widget_add->setSizePolicy(sizePolicy6);
        widget_add->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(widget_add);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, -1, 1, -1);
        add_item = new QPushButton(widget_add);
        add_item->setObjectName(QStringLiteral("add_item"));
        sizePolicy1.setHeightForWidth(add_item->sizePolicy().hasHeightForWidth());
        add_item->setSizePolicy(sizePolicy1);
        add_item->setMinimumSize(QSize(20, 0));
        add_item->setMaximumSize(QSize(40, 30));
        add_item->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background:none;\n"
"    background: transparent;\n"
"	bored :none;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"background-color: rgb(157, 157, 157);\n"
"}\n"
"QPushBuuton:hover\n"
"{\n"
"	background-color:white; color: black;\n"
"}"));

        horizontalLayout_2->addWidget(add_item);


        verticalLayout_2->addWidget(widget_add);

        listWidget = new QListWidget(page_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(listWidget);

        stackedWidget->addWidget(page_3);

        gridLayout->addWidget(stackedWidget, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_8, SIGNAL(clicked(bool)), MainWindow, SLOT(showMinimized()));
        QObject::connect(pushButton_7, SIGNAL(clicked(bool)), MainWindow, SLOT(close()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("MainWindow", "\350\277\224\345\233\236\351\246\226\351\241\265", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_5->setProperty("Text", QVariant(QString()));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\347\232\256\347\232\256\350\231\276\350\275\257\344\273\266</p></body></html>", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\202\250\347\232\204\346\234\200\350\277\221\345\256\211\346\216\222", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton->setText(QApplication::translate("MainWindow", "\344\270\273\351\241\265", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\344\270\200\344\270\252\347\225\252\350\214\204\345\221\250\346\234\237\347\232\204\346\227\266\351\227\264", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("MainWindow", "\350\277\231\351\207\214\346\230\257\346\202\250\347\232\204\346\227\245\347\250\213\345\256\211\346\216\222", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\227\245\347\250\213", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("MainWindow", "\350\277\233\345\205\245\350\256\276\347\275\256\347\225\214\351\235\242 \345\217\257\344\273\245\346\233\264\346\224\271\347\225\214\351\235\242\345\222\214\345\237\272\346\234\254\345\261\236\346\200\247", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_4->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\350\277\231\346\230\257\344\270\200\344\270\252\347\256\241\347\220\206\346\227\266\351\227\264\347\232\204\350\275\257\344\273\266 \345\217\257\344\273\245\346\237\245\347\234\213\346\227\245\347\250\213\345\222\214\347\273\237\350\256\241\344\275\277\347\224\250", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\347\274\251\347\225\245\345\233\276\351\203\250\344\273\266\350\277\233\350\241\214\344\270\223\346\263\250\345\221\250\346\234\237", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("MainWindow", "\347\274\251\347\225\245\345\233\276", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QString());
        pushButton_3->setProperty("Text", QVariant(QApplication::translate("MainWindow", "\347\274\251\347\225\245\345\233\276", Q_NULLPTR)));
#ifndef QT_NO_STATUSTIP
        pushButton_8->setStatusTip(QApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226\347\250\213\345\272\217(\345\217\257\344\273\245\350\256\276\347\275\256\345\234\250\344\273\273\345\212\241\346\240\217\344\270\255\346\230\276\347\244\272)", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_8->setProperty("Text", QVariant(QString()));
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255  \350\207\252\351\227\255\344\270\255----", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pushButton_7->setProperty("Text", QVariant(QString()));
        checkBox->setText(QApplication::translate("MainWindow", "\346\212\227\351\224\257\351\275\277", Q_NULLPTR));
        checkBox->setProperty("Text", QVariant(QApplication::translate("MainWindow", "\345\217\215\345\244\261\347\234\237", Q_NULLPTR)));
#ifndef QT_NO_STATUSTIP
        graphicsView->setStatusTip(QApplication::translate("MainWindow", "\350\277\231\351\207\214\344\270\223\346\263\250\346\227\266\351\227\264\351\273\230\350\256\24430\345\210\206\351\222\237(25\345\210\206\351\222\237\344\270\223\346\263\250\345\222\214 5\345\210\206\351\222\237\344\274\221\346\201\257", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        add_item->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        listWidget->setStatusTip(QApplication::translate("MainWindow", "\350\277\231\346\230\257\346\227\245\347\250\213\350\241\250", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOWS_H
