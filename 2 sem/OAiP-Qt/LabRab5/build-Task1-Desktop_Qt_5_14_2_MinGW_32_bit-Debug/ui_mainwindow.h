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
    QPushButton *pushButton_isEmpty;
    QPushButton *pushButton_getSize;
    QPushButton *pushButton_dequeue;
    QPushButton *pushButton_enqueue;
    QPushButton *pushButton_Back;
    QPushButton *pushButton_Front;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
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
        pushButton_isEmpty = new QPushButton(centralwidget);
        pushButton_isEmpty->setObjectName(QString::fromUtf8("pushButton_isEmpty"));
        pushButton_isEmpty->setGeometry(QRect(10, 10, 171, 51));
        pushButton_getSize = new QPushButton(centralwidget);
        pushButton_getSize->setObjectName(QString::fromUtf8("pushButton_getSize"));
        pushButton_getSize->setGeometry(QRect(10, 70, 171, 51));
        pushButton_dequeue = new QPushButton(centralwidget);
        pushButton_dequeue->setObjectName(QString::fromUtf8("pushButton_dequeue"));
        pushButton_dequeue->setGeometry(QRect(10, 190, 171, 51));
        pushButton_enqueue = new QPushButton(centralwidget);
        pushButton_enqueue->setObjectName(QString::fromUtf8("pushButton_enqueue"));
        pushButton_enqueue->setGeometry(QRect(10, 130, 171, 51));
        pushButton_Back = new QPushButton(centralwidget);
        pushButton_Back->setObjectName(QString::fromUtf8("pushButton_Back"));
        pushButton_Back->setGeometry(QRect(10, 310, 171, 51));
        pushButton_Front = new QPushButton(centralwidget);
        pushButton_Front->setObjectName(QString::fromUtf8("pushButton_Front"));
        pushButton_Front->setGeometry(QRect(10, 250, 171, 51));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 130, 161, 51));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(460, 10, 331, 421));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(10, 370, 171, 51));
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
        pushButton_dequeue->setText(QCoreApplication::translate("MainWindow", "dequeue", nullptr));
        pushButton_enqueue->setText(QCoreApplication::translate("MainWindow", "enqueue", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_Front->setText(QCoreApplication::translate("MainWindow", "Front", nullptr));
        lineEdit->setText(QString());
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
