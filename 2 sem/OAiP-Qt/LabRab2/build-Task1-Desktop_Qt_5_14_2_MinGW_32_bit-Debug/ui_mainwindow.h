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
    QTextBrowser *textBrowser;
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
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QPushButton *deleteButton;
    QLineEdit *lineDeleteDestination;
    QPushButton *addButton;
    QPushButton *showAllButton;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QPushButton *showButton;
    QTimeEdit *findTimeDepartureTime;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QPushButton *saveFileButton;
    QPushButton *openFileButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(840, 606);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 20, 471, 381));
        textBrowser->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 85, 0);\n"
"color: rgb(85, 255, 0);\n"
"background-color:transparent;"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(480, 20, 251, 151));
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

        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(480, 240, 311, 81));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        deleteButton = new QPushButton(formLayoutWidget_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, deleteButton);

        lineDeleteDestination = new QLineEdit(formLayoutWidget_2);
        lineDeleteDestination->setObjectName(QString::fromUtf8("lineDeleteDestination"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineDeleteDestination);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(480, 180, 251, 41));
        addButton->setStyleSheet(QString::fromUtf8(""));
        showAllButton = new QPushButton(centralwidget);
        showAllButton->setObjectName(QString::fromUtf8("showAllButton"));
        showAllButton->setGeometry(QRect(480, 330, 251, 61));
        formLayoutWidget_3 = new QWidget(centralwidget);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(480, 400, 341, 51));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        showButton = new QPushButton(formLayoutWidget_3);
        showButton->setObjectName(QString::fromUtf8("showButton"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, showButton);

        findTimeDepartureTime = new QTimeEdit(formLayoutWidget_3);
        findTimeDepartureTime->setObjectName(QString::fromUtf8("findTimeDepartureTime"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, findTimeDepartureTime);

        formLayoutWidget_4 = new QWidget(centralwidget);
        formLayoutWidget_4->setObjectName(QString::fromUtf8("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(0, 410, 471, 41));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        saveFileButton = new QPushButton(formLayoutWidget_4);
        saveFileButton->setObjectName(QString::fromUtf8("saveFileButton"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, saveFileButton);

        openFileButton = new QPushButton(formLayoutWidget_4);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, openFileButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 840, 25));
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
        labelNumflight->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\276\320\273\320\265\321\202\320\260:", nullptr));
        lineNumFlight->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200", nullptr));
        labelTypePlane->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\201\320\260\320\274\320\276\320\273\320\265\321\202\320\260:", nullptr));
        lineTypePlane->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\270\320\277", nullptr));
        labelDestination->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217:", nullptr));
        lineDestination->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\265\321\201\321\202\320\276", nullptr));
        labelDepartureTime->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\262\321\213\320\273\320\265\321\202\320\260:", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\320\265\321\202 \320\277\320\276 \320\274\320\265\321\201\321\202\321\203 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        lineDeleteDestination->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\320\265\321\202", nullptr));
        showAllButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\321\221", nullptr));
        showButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \320\262\321\213\320\273\320\265\321\202\320\260", nullptr));
        saveFileButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
