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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *line_input_code;
    QPlainTextEdit *input_code;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QListWidget *listWidget_3;
    QListWidget *listWidget_4;
    QPushButton *parsing;
    QPushButton *open_file;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget_6;
    QListWidget *listWidget_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1195, 635);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 391, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line_input_code = new QLineEdit(verticalLayoutWidget);
        line_input_code->setObjectName(QString::fromUtf8("line_input_code"));
        line_input_code->setEnabled(false);

        verticalLayout->addWidget(line_input_code);

        input_code = new QPlainTextEdit(verticalLayoutWidget);
        input_code->setObjectName(QString::fromUtf8("input_code"));

        verticalLayout->addWidget(input_code);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(410, 50, 381, 531));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEnabled(false);

        verticalLayout_2->addWidget(listWidget);

        listWidget_2 = new QListWidget(verticalLayoutWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setEnabled(false);

        verticalLayout_2->addWidget(listWidget_2);

        listWidget_3 = new QListWidget(verticalLayoutWidget_2);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setEnabled(false);

        verticalLayout_2->addWidget(listWidget_3);

        listWidget_4 = new QListWidget(verticalLayoutWidget_2);
        listWidget_4->setObjectName(QString::fromUtf8("listWidget_4"));
        listWidget_4->setEnabled(false);

        verticalLayout_2->addWidget(listWidget_4);

        parsing = new QPushButton(centralwidget);
        parsing->setObjectName(QString::fromUtf8("parsing"));
        parsing->setGeometry(QRect(410, 0, 381, 41));
        open_file = new QPushButton(centralwidget);
        open_file->setObjectName(QString::fromUtf8("open_file"));
        open_file->setGeometry(QRect(800, 0, 381, 41));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(800, 50, 381, 531));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidget_6 = new QListWidget(verticalLayoutWidget_3);
        listWidget_6->setObjectName(QString::fromUtf8("listWidget_6"));
        listWidget_6->setEnabled(false);

        verticalLayout_3->addWidget(listWidget_6);

        listWidget_5 = new QListWidget(verticalLayoutWidget_3);
        listWidget_5->setObjectName(QString::fromUtf8("listWidget_5"));
        listWidget_5->setEnabled(false);

        verticalLayout_3->addWidget(listWidget_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1195, 25));
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
        line_input_code->setText(QCoreApplication::translate("MainWindow", "Input your code:", nullptr));
        parsing->setText(QCoreApplication::translate("MainWindow", "Parsing....", nullptr));
        open_file->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
