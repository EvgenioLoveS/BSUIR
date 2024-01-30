/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelNumflight;
    QLineEdit *lineNumFlight;
    QLabel *labelTypePlane;
    QLineEdit *lineTypePlane;
    QLabel *labelDestination;
    QLineEdit *lineDestination;
    QLabel *labelDepartureTime;
    QTimeEdit *timeDepartureTime;
    QLabel *labelArrivalTime;
    QTimeEdit *timeArrivalTime;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QPushButton *openFileButton;
    QPushButton *saveFileButton;
    QPushButton *addButton;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QPushButton *changeButton;
    QLineEdit *lineDelNumBus;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QPushButton *showButton;
    QLineEdit *lineShowDestination;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_5;
    QPushButton *showAllButton;
    QPushButton *deleteButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(893, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(570, 10, 291, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelNumflight = new QLabel(formLayoutWidget);
        labelNumflight->setObjectName(QString::fromUtf8("labelNumflight"));
        labelNumflight->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNumflight);

        lineNumFlight = new QLineEdit(formLayoutWidget);
        lineNumFlight->setObjectName(QString::fromUtf8("lineNumFlight"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineNumFlight);

        labelTypePlane = new QLabel(formLayoutWidget);
        labelTypePlane->setObjectName(QString::fromUtf8("labelTypePlane"));
        labelTypePlane->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelTypePlane);

        lineTypePlane = new QLineEdit(formLayoutWidget);
        lineTypePlane->setObjectName(QString::fromUtf8("lineTypePlane"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineTypePlane);

        labelDestination = new QLabel(formLayoutWidget);
        labelDestination->setObjectName(QString::fromUtf8("labelDestination"));
        labelDestination->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelDestination);

        lineDestination = new QLineEdit(formLayoutWidget);
        lineDestination->setObjectName(QString::fromUtf8("lineDestination"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineDestination);

        labelDepartureTime = new QLabel(formLayoutWidget);
        labelDepartureTime->setObjectName(QString::fromUtf8("labelDepartureTime"));
        labelDepartureTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelDepartureTime);

        timeDepartureTime = new QTimeEdit(formLayoutWidget);
        timeDepartureTime->setObjectName(QString::fromUtf8("timeDepartureTime"));

        formLayout->setWidget(3, QFormLayout::FieldRole, timeDepartureTime);

        labelArrivalTime = new QLabel(formLayoutWidget);
        labelArrivalTime->setObjectName(QString::fromUtf8("labelArrivalTime"));
        labelArrivalTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelArrivalTime);

        timeArrivalTime = new QTimeEdit(formLayoutWidget);
        timeArrivalTime->setObjectName(QString::fromUtf8("timeArrivalTime"));

        formLayout->setWidget(4, QFormLayout::FieldRole, timeArrivalTime);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 561, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(0, 255, 0);"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 1);

        textBrowser_2 = new QTextBrowser(gridLayoutWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(85, 255, 0);"));

        gridLayout->addWidget(textBrowser_2, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 420, 551, 58));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        openFileButton = new QPushButton(formLayoutWidget_2);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, openFileButton);

        saveFileButton = new QPushButton(formLayoutWidget_2);
        saveFileButton->setObjectName(QString::fromUtf8("saveFileButton"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, saveFileButton);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(570, 200, 291, 41));
        formLayoutWidget_3 = new QWidget(centralwidget);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(570, 250, 291, 81));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        changeButton = new QPushButton(formLayoutWidget_3);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, changeButton);

        lineDelNumBus = new QLineEdit(formLayoutWidget_3);
        lineDelNumBus->setObjectName(QString::fromUtf8("lineDelNumBus"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineDelNumBus);

        formLayoutWidget_4 = new QWidget(centralwidget);
        formLayoutWidget_4->setObjectName(QString::fromUtf8("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(570, 340, 291, 81));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        showButton = new QPushButton(formLayoutWidget_4);
        showButton->setObjectName(QString::fromUtf8("showButton"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, showButton);

        lineShowDestination = new QLineEdit(formLayoutWidget_4);
        lineShowDestination->setObjectName(QString::fromUtf8("lineShowDestination"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineShowDestination);

        formLayoutWidget_5 = new QWidget(centralwidget);
        formLayoutWidget_5->setObjectName(QString::fromUtf8("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(570, 430, 291, 81));
        formLayout_5 = new QFormLayout(formLayoutWidget_5);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        showAllButton = new QPushButton(formLayoutWidget_5);
        showAllButton->setObjectName(QString::fromUtf8("showAllButton"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, showAllButton);

        deleteButton = new QPushButton(formLayoutWidget_5);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, deleteButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 893, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelNumflight->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\260\320\262\321\202\320\276\320\261\321\203\321\201\320\260:", nullptr));
        lineNumFlight->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200", nullptr));
        labelTypePlane->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\260\320\262\321\202\320\276\320\261\321\203\321\201\320\260", nullptr));
        lineTypePlane->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\270\320\277", nullptr));
        labelDestination->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217:", nullptr));
        lineDestination->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\265\321\201\321\202\320\276", nullptr));
        labelDepartureTime->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\276\321\202\321\212\320\265\320\267\320\264\320\260:", nullptr));
        labelArrivalTime->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\260\320\262\321\202\320\276\320\277\320\260\321\200\320\272\320\265:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\277\321\203\321\202\320\270:", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        saveFileButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        changeButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \320\260\320\262\321\202\320\276\320\261\321\203\321\201\320\260", nullptr));
        lineDelNumBus->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200", nullptr));
        showButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\276 \320\274\320\265\321\201\321\202\321\203 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        lineShowDestination->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        showAllButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\321\221", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
