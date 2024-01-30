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
    QPushButton *pushButton_add;
    QPushButton *pushButton_get;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_size;
    QLineEdit *valueLineEdit;
    QLineEdit *keyLineEdit;
    QPushButton *pushButton_task;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(584, 476);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(190, 40, 371, 331));
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(0, 40, 181, 51));
        pushButton_get = new QPushButton(centralwidget);
        pushButton_get->setObjectName(QString::fromUtf8("pushButton_get"));
        pushButton_get->setGeometry(QRect(0, 100, 181, 51));
        pushButton_remove = new QPushButton(centralwidget);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));
        pushButton_remove->setGeometry(QRect(0, 160, 181, 51));
        pushButton_size = new QPushButton(centralwidget);
        pushButton_size->setObjectName(QString::fromUtf8("pushButton_size"));
        pushButton_size->setGeometry(QRect(0, 220, 181, 51));
        valueLineEdit = new QLineEdit(centralwidget);
        valueLineEdit->setObjectName(QString::fromUtf8("valueLineEdit"));
        valueLineEdit->setGeometry(QRect(0, 280, 181, 41));
        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName(QString::fromUtf8("keyLineEdit"));
        keyLineEdit->setGeometry(QRect(0, 330, 181, 41));
        pushButton_task = new QPushButton(centralwidget);
        pushButton_task->setObjectName(QString::fromUtf8("pushButton_task"));
        pushButton_task->setGeometry(QRect(190, 380, 371, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 584, 25));
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
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        pushButton_get->setText(QCoreApplication::translate("MainWindow", "get", nullptr));
        pushButton_remove->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        pushButton_size->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        valueLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "value", nullptr));
        keyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "key", nullptr));
        pushButton_task->setText(QCoreApplication::translate("MainWindow", "task", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
