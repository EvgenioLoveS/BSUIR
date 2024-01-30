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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *OpenFile;
    QPushButton *SaveFile;
    QLCDNumber *lcdNumber;
    QDateEdit *Date_Birthday_Text;
    QDateEdit *Date_Add_Text;
    QDateEdit *Date_Change_Text;
    QPushButton *addDate;
    QPushButton *changeDate;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *Line_Number_Change;
    QLineEdit *lineEdit_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1294, 629);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(250, 10, 711, 351));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        OpenFile = new QPushButton(centralwidget);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        OpenFile->setGeometry(QRect(20, 40, 151, 61));
        OpenFile->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        SaveFile = new QPushButton(centralwidget);
        SaveFile->setObjectName(QString::fromUtf8("SaveFile"));
        SaveFile->setGeometry(QRect(20, 130, 151, 61));
        SaveFile->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 430, 161, 121));
        lcdNumber->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        lcdNumber->setSmallDecimalPoint(true);
        Date_Birthday_Text = new QDateEdit(centralwidget);
        Date_Birthday_Text->setObjectName(QString::fromUtf8("Date_Birthday_Text"));
        Date_Birthday_Text->setGeometry(QRect(20, 290, 201, 51));
        Date_Birthday_Text->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 255);"));
        Date_Birthday_Text->setCalendarPopup(true);
        Date_Add_Text = new QDateEdit(centralwidget);
        Date_Add_Text->setObjectName(QString::fromUtf8("Date_Add_Text"));
        Date_Add_Text->setGeometry(QRect(250, 420, 201, 31));
        Date_Add_Text->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 255);"));
        Date_Add_Text->setCalendarPopup(true);
        Date_Change_Text = new QDateEdit(centralwidget);
        Date_Change_Text->setObjectName(QString::fromUtf8("Date_Change_Text"));
        Date_Change_Text->setGeometry(QRect(720, 480, 241, 31));
        Date_Change_Text->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 0, 255);"));
        Date_Change_Text->setCalendarPopup(true);
        addDate = new QPushButton(centralwidget);
        addDate->setObjectName(QString::fromUtf8("addDate"));
        addDate->setGeometry(QRect(250, 520, 181, 51));
        addDate->setAutoFillBackground(false);
        addDate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);\n"
"color: rgb(255, 0, 0);"));
        changeDate = new QPushButton(centralwidget);
        changeDate->setObjectName(QString::fromUtf8("changeDate"));
        changeDate->setGeometry(QRect(720, 520, 181, 51));
        changeDate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);\n"
"color: rgb(255, 0, 0);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(250, 390, 201, 21));
        lineEdit->setMouseTracking(true);
        lineEdit->setAcceptDrops(true);
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        lineEdit->setFrame(false);
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 230, 201, 51));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        lineEdit_2->setFont(font);
        lineEdit_2->setMouseTracking(false);
        lineEdit_2->setTabletTracking(false);
        lineEdit_2->setAutoFillBackground(false);
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        lineEdit_2->setFrame(false);
        lineEdit_2->setReadOnly(true);
        lineEdit_2->setClearButtonEnabled(false);
        Line_Number_Change = new QLineEdit(centralwidget);
        Line_Number_Change->setObjectName(QString::fromUtf8("Line_Number_Change"));
        Line_Number_Change->setGeometry(QRect(720, 390, 201, 21));
        Line_Number_Change->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        Line_Number_Change->setFrame(true);
        Line_Number_Change->setClearButtonEnabled(true);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(720, 430, 201, 21));
        lineEdit_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        lineEdit_4->setFrame(false);
        lineEdit_4->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1294, 25));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Next Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Previous Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Is Leap", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Week Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        OpenFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        SaveFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        addDate->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\260\321\202\321\203", nullptr));
        changeDate->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \320\264\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        Line_Number_Change->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
