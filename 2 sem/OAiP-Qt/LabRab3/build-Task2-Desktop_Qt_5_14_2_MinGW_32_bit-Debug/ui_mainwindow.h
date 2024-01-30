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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *how_many_pair;
    QSpinBox *count_pair;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *first_matric;
    QTextEdit *output_first_matric;
    QVBoxLayout *verticalLayout_2;
    QLabel *second_matric;
    QTextEdit *output_second_matric;
    QPushButton *outputButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 251, 271));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        how_many_pair = new QLabel(formLayoutWidget);
        how_many_pair->setObjectName(QString::fromUtf8("how_many_pair"));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        how_many_pair->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, how_many_pair);

        count_pair = new QSpinBox(formLayoutWidget);
        count_pair->setObjectName(QString::fromUtf8("count_pair"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, count_pair);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(270, 10, 521, 531));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        first_matric = new QLabel(horizontalLayoutWidget);
        first_matric->setObjectName(QString::fromUtf8("first_matric"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        first_matric->setFont(font1);

        verticalLayout->addWidget(first_matric);

        output_first_matric = new QTextEdit(horizontalLayoutWidget);
        output_first_matric->setObjectName(QString::fromUtf8("output_first_matric"));
        output_first_matric->setReadOnly(true);

        verticalLayout->addWidget(output_first_matric);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        second_matric = new QLabel(horizontalLayoutWidget);
        second_matric->setObjectName(QString::fromUtf8("second_matric"));
        second_matric->setFont(font1);

        verticalLayout_2->addWidget(second_matric);

        output_second_matric = new QTextEdit(horizontalLayoutWidget);
        output_second_matric->setObjectName(QString::fromUtf8("output_second_matric"));
        output_second_matric->setReadOnly(true);

        verticalLayout_2->addWidget(output_second_matric);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        outputButton = new QPushButton(centralwidget);
        outputButton->setObjectName(QString::fromUtf8("outputButton"));
        outputButton->setGeometry(QRect(10, 300, 251, 241));
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
        how_many_pair->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\320\273\321\214\320\272\320\276 \320\262\321\213 \321\205\320\276\321\202\320\270\321\202\320\265 \321\201\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\260\321\200?", nullptr));
        first_matric->setText(QCoreApplication::translate("MainWindow", "\320\277\320\265\321\200\320\262\320\260\321\217 \320\274\320\260\321\202\321\200\320\270\321\206\320\260", nullptr));
        second_matric->setText(QCoreApplication::translate("MainWindow", "\320\262\321\202\320\276\321\200\320\260\321\217 \320\274\320\260\321\202\321\200\320\270\321\206\320\260", nullptr));
        outputButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
