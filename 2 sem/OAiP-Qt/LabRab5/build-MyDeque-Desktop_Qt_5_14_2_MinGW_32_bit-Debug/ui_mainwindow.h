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
    QPushButton *pushButton_isEmpty;
    QPushButton *pushButton_getSize;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_push_front;
    QPushButton *pushButton_push_back;
    QPushButton *pushButton_pop_back;
    QPushButton *pushButton_pop_front;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
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
        listWidget->setGeometry(QRect(380, 30, 331, 471));
        pushButton_isEmpty = new QPushButton(centralwidget);
        pushButton_isEmpty->setObjectName(QString::fromUtf8("pushButton_isEmpty"));
        pushButton_isEmpty->setGeometry(QRect(10, 10, 171, 51));
        pushButton_getSize = new QPushButton(centralwidget);
        pushButton_getSize->setObjectName(QString::fromUtf8("pushButton_getSize"));
        pushButton_getSize->setGeometry(QRect(10, 70, 171, 51));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(10, 130, 171, 51));
        pushButton_push_front = new QPushButton(centralwidget);
        pushButton_push_front->setObjectName(QString::fromUtf8("pushButton_push_front"));
        pushButton_push_front->setGeometry(QRect(10, 250, 171, 51));
        pushButton_push_back = new QPushButton(centralwidget);
        pushButton_push_back->setObjectName(QString::fromUtf8("pushButton_push_back"));
        pushButton_push_back->setGeometry(QRect(10, 190, 171, 51));
        pushButton_pop_back = new QPushButton(centralwidget);
        pushButton_pop_back->setObjectName(QString::fromUtf8("pushButton_pop_back"));
        pushButton_pop_back->setGeometry(QRect(10, 310, 171, 51));
        pushButton_pop_front = new QPushButton(centralwidget);
        pushButton_pop_front->setObjectName(QString::fromUtf8("pushButton_pop_front"));
        pushButton_pop_front->setGeometry(QRect(10, 370, 171, 51));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 190, 161, 51));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 250, 161, 51));
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
        pushButton_isEmpty->setText(QCoreApplication::translate("MainWindow", "isEmpty", nullptr));
        pushButton_getSize->setText(QCoreApplication::translate("MainWindow", "getSize", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        pushButton_push_front->setText(QCoreApplication::translate("MainWindow", "push_front", nullptr));
        pushButton_push_back->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        pushButton_pop_back->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
        pushButton_pop_front->setText(QCoreApplication::translate("MainWindow", "pop_front", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
