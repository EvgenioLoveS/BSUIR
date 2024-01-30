/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QLineEdit *lineEdit_value;
    QLineEdit *lineEdit_key;
    QPushButton *pushButton_insert;
    QPushButton *pushButton_find;
    QPushButton *pushButton_erase;
    QPushButton *pushButton_contains;
    QPushButton *pushButton_size;
    QPushButton *pushButton_clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 501, 391));
        lineEdit_value = new QLineEdit(centralwidget);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(520, 10, 141, 41));
        lineEdit_key = new QLineEdit(centralwidget);
        lineEdit_key->setObjectName(QString::fromUtf8("lineEdit_key"));
        lineEdit_key->setGeometry(QRect(520, 60, 141, 41));
        pushButton_insert = new QPushButton(centralwidget);
        pushButton_insert->setObjectName(QString::fromUtf8("pushButton_insert"));
        pushButton_insert->setGeometry(QRect(520, 110, 141, 41));
        pushButton_find = new QPushButton(centralwidget);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setGeometry(QRect(520, 160, 141, 41));
        pushButton_erase = new QPushButton(centralwidget);
        pushButton_erase->setObjectName(QString::fromUtf8("pushButton_erase"));
        pushButton_erase->setGeometry(QRect(520, 210, 141, 41));
        pushButton_contains = new QPushButton(centralwidget);
        pushButton_contains->setObjectName(QString::fromUtf8("pushButton_contains"));
        pushButton_contains->setGeometry(QRect(520, 260, 141, 41));
        pushButton_size = new QPushButton(centralwidget);
        pushButton_size->setObjectName(QString::fromUtf8("pushButton_size"));
        pushButton_size->setGeometry(QRect(520, 310, 141, 41));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(520, 360, 141, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        lineEdit_value->setText(QString());
        lineEdit_value->setPlaceholderText(QCoreApplication::translate("MainWindow", "value", nullptr));
        lineEdit_key->setText(QString());
        lineEdit_key->setPlaceholderText(QCoreApplication::translate("MainWindow", "key", nullptr));
        pushButton_insert->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        pushButton_find->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        pushButton_erase->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        pushButton_contains->setText(QCoreApplication::translate("MainWindow", "contains", nullptr));
        pushButton_size->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
