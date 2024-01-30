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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QPushButton *pushButton_add;
    QPushButton *pushButton_balanced;
    QPushButton *pushButton_find;
    QPushButton *pushButton_deleter;
    QPushButton *pushButton_printStraight;
    QPushButton *pushButton_printBackward;
    QPushButton *pushButton_printAscending;
    QLineEdit *valueLineEdit;
    QLineEdit *keyLineEdit;
    QPushButton *pushButton_countNodesWithOneChild;
    QTextEdit *textEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(220, 40, 321, 311));
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(30, 70, 181, 41));
        pushButton_balanced = new QPushButton(centralwidget);
        pushButton_balanced->setObjectName(QString::fromUtf8("pushButton_balanced"));
        pushButton_balanced->setGeometry(QRect(30, 120, 181, 41));
        pushButton_find = new QPushButton(centralwidget);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setGeometry(QRect(30, 170, 181, 41));
        pushButton_deleter = new QPushButton(centralwidget);
        pushButton_deleter->setObjectName(QString::fromUtf8("pushButton_deleter"));
        pushButton_deleter->setGeometry(QRect(30, 220, 181, 41));
        pushButton_printStraight = new QPushButton(centralwidget);
        pushButton_printStraight->setObjectName(QString::fromUtf8("pushButton_printStraight"));
        pushButton_printStraight->setGeometry(QRect(550, 70, 181, 41));
        pushButton_printBackward = new QPushButton(centralwidget);
        pushButton_printBackward->setObjectName(QString::fromUtf8("pushButton_printBackward"));
        pushButton_printBackward->setGeometry(QRect(550, 120, 181, 41));
        pushButton_printAscending = new QPushButton(centralwidget);
        pushButton_printAscending->setObjectName(QString::fromUtf8("pushButton_printAscending"));
        pushButton_printAscending->setGeometry(QRect(550, 170, 181, 41));
        valueLineEdit = new QLineEdit(centralwidget);
        valueLineEdit->setObjectName(QString::fromUtf8("valueLineEdit"));
        valueLineEdit->setGeometry(QRect(220, 370, 321, 31));
        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName(QString::fromUtf8("keyLineEdit"));
        keyLineEdit->setGeometry(QRect(220, 410, 321, 31));
        pushButton_countNodesWithOneChild = new QPushButton(centralwidget);
        pushButton_countNodesWithOneChild->setObjectName(QString::fromUtf8("pushButton_countNodesWithOneChild"));
        pushButton_countNodesWithOneChild->setGeometry(QRect(10, 440, 181, 41));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(10, 490, 181, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(200, 490, 61, 41));
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
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_balanced->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\320\260\320\273\320\260\320\275\321\201\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_find->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270(\320\277\320\276 \320\272\320\273\321\216\321\207\321\203)", nullptr));
        pushButton_deleter->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214(\320\277\320\276 \320\272\320\273\321\216\321\207\321\203)", nullptr));
        pushButton_printStraight->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\271", nullptr));
        pushButton_printBackward->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\271", nullptr));
        pushButton_printAscending->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\217\320\264\320\276\320\272", nullptr));
        valueLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        keyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        pushButton_countNodesWithOneChild->setText(QCoreApplication::translate("MainWindow", "countNodesWithOneChild", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'sans-serif'; font-size:8pt;\">\320\247\320\270\321\201\320\273\320\276 \321\203\320\267\320\273\320\276\320\262 \320\262 \320\264\320\265\321\200\320\265\320\262\320\265, \320\262 \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \320\265\321\201\321\202\321\214 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \321\202\320\276\320\273\321\214\320\272\320\276 \320\275\320\260</span><span style=\" font-size:8pt;\"><br /></span><span style=\" font-family:'sans-serif'; font-size:8pt;\">\320\276\320\264"
                        "\320\275\321\203 \320\262\320\265\321\202\320\262\321\214.</span></p></body></html>", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
