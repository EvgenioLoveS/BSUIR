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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *pushButton;
    QPushButton *changeButton;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_a;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_b;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_c;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_d;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_e;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 40, 521, 311));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 10, 501, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 10, 115, 25));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(530, 50, 241, 301));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton);

        changeButton = new QPushButton(formLayoutWidget);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, changeButton);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        doubleSpinBox_a = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_a->setObjectName(QString::fromUtf8("doubleSpinBox_a"));
        doubleSpinBox_a->setSingleStep(0.100000000000000);
        doubleSpinBox_a->setValue(8.600000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_a);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        doubleSpinBox_b = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_b->setObjectName(QString::fromUtf8("doubleSpinBox_b"));
        doubleSpinBox_b->setSingleStep(0.100000000000000);
        doubleSpinBox_b->setValue(2.400000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBox_b);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        doubleSpinBox_c = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_c->setObjectName(QString::fromUtf8("doubleSpinBox_c"));
        doubleSpinBox_c->setSingleStep(0.100000000000000);
        doubleSpinBox_c->setValue(5.100000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBox_c);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        doubleSpinBox_d = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_d->setObjectName(QString::fromUtf8("doubleSpinBox_d"));
        doubleSpinBox_d->setSingleStep(0.100000000000000);
        doubleSpinBox_d->setValue(0.300000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, doubleSpinBox_d);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        doubleSpinBox_e = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_e->setObjectName(QString::fromUtf8("doubleSpinBox_e"));
        doubleSpinBox_e->setSingleStep(0.100000000000000);
        doubleSpinBox_e->setValue(7.900000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, doubleSpinBox_e);

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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\270\320\275\321\204\320\270\320\272\321\201\320\275\320\260\321\217 \321\204\320\276\321\200\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\321\201\321\202\321\204\320\270\320\272\321\201\320\275\320\260\321\217 \321\204\320\276\321\200\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262 \320\270\320\275\321\204\320\270\320\272\321\201\320\275\320\276\320\271 \321\204\320\276\321\200\320\274\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        changeButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\207\320\270\321\201\320\273\320\260 \321\201\321\202\321\200\320\276\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "a:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "b:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "c:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "d:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "e:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
