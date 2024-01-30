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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *clear_vector;
    QPushButton *add_in_vector;
    QSpinBox *add_number;
    QLineEdit *output_medians;
    QPushButton *show_vector;
    QLineEdit *output_vec;
    QPushButton *set_of_medians;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        clear_vector = new QPushButton(centralwidget);
        clear_vector->setObjectName(QString::fromUtf8("clear_vector"));
        clear_vector->setGeometry(QRect(10, 170, 251, 131));
        add_in_vector = new QPushButton(centralwidget);
        add_in_vector->setObjectName(QString::fromUtf8("add_in_vector"));
        add_in_vector->setGeometry(QRect(10, 10, 251, 71));
        add_number = new QSpinBox(centralwidget);
        add_number->setObjectName(QString::fromUtf8("add_number"));
        add_number->setGeometry(QRect(10, 90, 251, 71));
        output_medians = new QLineEdit(centralwidget);
        output_medians->setObjectName(QString::fromUtf8("output_medians"));
        output_medians->setGeometry(QRect(280, 270, 511, 161));
        show_vector = new QPushButton(centralwidget);
        show_vector->setObjectName(QString::fromUtf8("show_vector"));
        show_vector->setGeometry(QRect(280, 10, 461, 71));
        output_vec = new QLineEdit(centralwidget);
        output_vec->setObjectName(QString::fromUtf8("output_vec"));
        output_vec->setGeometry(QRect(280, 90, 461, 81));
        set_of_medians = new QPushButton(centralwidget);
        set_of_medians->setObjectName(QString::fromUtf8("set_of_medians"));
        set_of_medians->setGeometry(QRect(280, 180, 461, 81));
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
        clear_vector->setText(QCoreApplication::translate("MainWindow", "clear vector", nullptr));
        add_in_vector->setText(QCoreApplication::translate("MainWindow", "add on vector", nullptr));
        show_vector->setText(QCoreApplication::translate("MainWindow", "show vector", nullptr));
        set_of_medians->setText(QCoreApplication::translate("MainWindow", "set of medians", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
