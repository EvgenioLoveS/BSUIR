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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QPushButton *generationVec2;
    QLineEdit *output_of_vec2;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QPushButton *generationVec1;
    QLineEdit *output_of_vec1;
    QPushButton *EmptyMethods;
    QPushButton *ClearMethods;
    QPushButton *Max_SizeMethods;
    QPushButton *DataMethods;
    QPushButton *SizeMethods;
    QPushButton *CapacityMethods;
    QPushButton *SwapMethods;
    QPushButton *Pop_BackMethods;
    QPushButton *BackMethods;
    QPushButton *FrontMethods;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Push_BackMethods;
    QLineEdit *Push_Back_output;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AtMethods;
    QLineEdit *At_output;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *ReserveMethods;
    QLineEdit *Reserve_output;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *ResizeMethods;
    QLineEdit *Resize_output;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *AssignMethods;
    QLineEdit *Assign_output_1;
    QLineEdit *Assign_output_2;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *InsertMethods;
    QLineEdit *Insert_output_1;
    QLineEdit *Insert_output_2;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QPushButton *EraseMethods;
    QLineEdit *Erase_output_1;
    QLineEdit *Erase_output_2;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QPushButton *EmplaceMethods;
    QLineEdit *Emplace_output_1;
    QLineEdit *Emplace_output_2;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *verticalLayout_9;
    QPushButton *Emplace_BackMethods;
    QLineEdit *Emplace_Back_output;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1175, 605);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(570, 10, 571, 201));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        generationVec2 = new QPushButton(formLayoutWidget_2);
        generationVec2->setObjectName(QString::fromUtf8("generationVec2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, generationVec2);

        output_of_vec2 = new QLineEdit(formLayoutWidget_2);
        output_of_vec2->setObjectName(QString::fromUtf8("output_of_vec2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, output_of_vec2);

        formLayoutWidget_3 = new QWidget(centralwidget);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 10, 551, 201));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        generationVec1 = new QPushButton(formLayoutWidget_3);
        generationVec1->setObjectName(QString::fromUtf8("generationVec1"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, generationVec1);

        output_of_vec1 = new QLineEdit(formLayoutWidget_3);
        output_of_vec1->setObjectName(QString::fromUtf8("output_of_vec1"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, output_of_vec1);

        EmptyMethods = new QPushButton(centralwidget);
        EmptyMethods->setObjectName(QString::fromUtf8("EmptyMethods"));
        EmptyMethods->setGeometry(QRect(10, 220, 121, 41));
        ClearMethods = new QPushButton(centralwidget);
        ClearMethods->setObjectName(QString::fromUtf8("ClearMethods"));
        ClearMethods->setGeometry(QRect(140, 220, 121, 41));
        Max_SizeMethods = new QPushButton(centralwidget);
        Max_SizeMethods->setObjectName(QString::fromUtf8("Max_SizeMethods"));
        Max_SizeMethods->setGeometry(QRect(660, 220, 121, 41));
        DataMethods = new QPushButton(centralwidget);
        DataMethods->setObjectName(QString::fromUtf8("DataMethods"));
        DataMethods->setGeometry(QRect(530, 220, 121, 41));
        SizeMethods = new QPushButton(centralwidget);
        SizeMethods->setObjectName(QString::fromUtf8("SizeMethods"));
        SizeMethods->setGeometry(QRect(270, 220, 121, 41));
        CapacityMethods = new QPushButton(centralwidget);
        CapacityMethods->setObjectName(QString::fromUtf8("CapacityMethods"));
        CapacityMethods->setGeometry(QRect(400, 220, 121, 41));
        SwapMethods = new QPushButton(centralwidget);
        SwapMethods->setObjectName(QString::fromUtf8("SwapMethods"));
        SwapMethods->setGeometry(QRect(790, 220, 121, 41));
        Pop_BackMethods = new QPushButton(centralwidget);
        Pop_BackMethods->setObjectName(QString::fromUtf8("Pop_BackMethods"));
        Pop_BackMethods->setGeometry(QRect(10, 270, 121, 41));
        BackMethods = new QPushButton(centralwidget);
        BackMethods->setObjectName(QString::fromUtf8("BackMethods"));
        BackMethods->setGeometry(QRect(920, 220, 121, 41));
        FrontMethods = new QPushButton(centralwidget);
        FrontMethods->setObjectName(QString::fromUtf8("FrontMethods"));
        FrontMethods->setGeometry(QRect(1050, 220, 121, 41));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 270, 251, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Push_BackMethods = new QPushButton(verticalLayoutWidget);
        Push_BackMethods->setObjectName(QString::fromUtf8("Push_BackMethods"));

        verticalLayout->addWidget(Push_BackMethods);

        Push_Back_output = new QLineEdit(verticalLayoutWidget);
        Push_Back_output->setObjectName(QString::fromUtf8("Push_Back_output"));

        verticalLayout->addWidget(Push_Back_output);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(400, 270, 251, 111));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        AtMethods = new QPushButton(verticalLayoutWidget_2);
        AtMethods->setObjectName(QString::fromUtf8("AtMethods"));

        verticalLayout_2->addWidget(AtMethods);

        At_output = new QLineEdit(verticalLayoutWidget_2);
        At_output->setObjectName(QString::fromUtf8("At_output"));

        verticalLayout_2->addWidget(At_output);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(660, 270, 251, 111));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ReserveMethods = new QPushButton(verticalLayoutWidget_3);
        ReserveMethods->setObjectName(QString::fromUtf8("ReserveMethods"));

        verticalLayout_3->addWidget(ReserveMethods);

        Reserve_output = new QLineEdit(verticalLayoutWidget_3);
        Reserve_output->setObjectName(QString::fromUtf8("Reserve_output"));

        verticalLayout_3->addWidget(Reserve_output);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(920, 270, 251, 111));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        ResizeMethods = new QPushButton(verticalLayoutWidget_4);
        ResizeMethods->setObjectName(QString::fromUtf8("ResizeMethods"));

        verticalLayout_4->addWidget(ResizeMethods);

        Resize_output = new QLineEdit(verticalLayoutWidget_4);
        Resize_output->setObjectName(QString::fromUtf8("Resize_output"));

        verticalLayout_4->addWidget(Resize_output);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 320, 121, 231));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        AssignMethods = new QPushButton(verticalLayoutWidget_5);
        AssignMethods->setObjectName(QString::fromUtf8("AssignMethods"));

        verticalLayout_5->addWidget(AssignMethods);

        Assign_output_1 = new QLineEdit(verticalLayoutWidget_5);
        Assign_output_1->setObjectName(QString::fromUtf8("Assign_output_1"));

        verticalLayout_5->addWidget(Assign_output_1);

        Assign_output_2 = new QLineEdit(verticalLayoutWidget_5);
        Assign_output_2->setObjectName(QString::fromUtf8("Assign_output_2"));

        verticalLayout_5->addWidget(Assign_output_2);

        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(140, 390, 251, 151));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        InsertMethods = new QPushButton(verticalLayoutWidget_6);
        InsertMethods->setObjectName(QString::fromUtf8("InsertMethods"));

        verticalLayout_6->addWidget(InsertMethods);

        Insert_output_1 = new QLineEdit(verticalLayoutWidget_6);
        Insert_output_1->setObjectName(QString::fromUtf8("Insert_output_1"));

        verticalLayout_6->addWidget(Insert_output_1);

        Insert_output_2 = new QLineEdit(verticalLayoutWidget_6);
        Insert_output_2->setObjectName(QString::fromUtf8("Insert_output_2"));

        verticalLayout_6->addWidget(Insert_output_2);

        verticalLayoutWidget_7 = new QWidget(centralwidget);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(400, 390, 251, 151));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        EraseMethods = new QPushButton(verticalLayoutWidget_7);
        EraseMethods->setObjectName(QString::fromUtf8("EraseMethods"));

        verticalLayout_7->addWidget(EraseMethods);

        Erase_output_1 = new QLineEdit(verticalLayoutWidget_7);
        Erase_output_1->setObjectName(QString::fromUtf8("Erase_output_1"));

        verticalLayout_7->addWidget(Erase_output_1);

        Erase_output_2 = new QLineEdit(verticalLayoutWidget_7);
        Erase_output_2->setObjectName(QString::fromUtf8("Erase_output_2"));

        verticalLayout_7->addWidget(Erase_output_2);

        verticalLayoutWidget_8 = new QWidget(centralwidget);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(660, 390, 251, 151));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        EmplaceMethods = new QPushButton(verticalLayoutWidget_8);
        EmplaceMethods->setObjectName(QString::fromUtf8("EmplaceMethods"));

        verticalLayout_8->addWidget(EmplaceMethods);

        Emplace_output_1 = new QLineEdit(verticalLayoutWidget_8);
        Emplace_output_1->setObjectName(QString::fromUtf8("Emplace_output_1"));

        verticalLayout_8->addWidget(Emplace_output_1);

        Emplace_output_2 = new QLineEdit(verticalLayoutWidget_8);
        Emplace_output_2->setObjectName(QString::fromUtf8("Emplace_output_2"));

        verticalLayout_8->addWidget(Emplace_output_2);

        verticalLayoutWidget_9 = new QWidget(centralwidget);
        verticalLayoutWidget_9->setObjectName(QString::fromUtf8("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(920, 390, 251, 151));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        Emplace_BackMethods = new QPushButton(verticalLayoutWidget_9);
        Emplace_BackMethods->setObjectName(QString::fromUtf8("Emplace_BackMethods"));

        verticalLayout_9->addWidget(Emplace_BackMethods);

        Emplace_Back_output = new QLineEdit(verticalLayoutWidget_9);
        Emplace_Back_output->setObjectName(QString::fromUtf8("Emplace_Back_output"));

        verticalLayout_9->addWidget(Emplace_Back_output);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1175, 25));
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
        generationVec2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\200\320\260\320\275\320\264\320\276\320\274\320\275\321\213\320\271 \320\262\320\265\320\272\321\202\320\276\321\200(\320\262\321\202\320\276\321\200\320\276\320\271)", nullptr));
        generationVec1->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\200\320\260\320\275\320\264\320\276\320\274\320\275\321\213\320\271 \320\262\320\265\320\272\321\202\320\276\321\200(\320\277\320\265\321\200\320\262\321\213\320\271)", nullptr));
        EmptyMethods->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        ClearMethods->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Max_SizeMethods->setText(QCoreApplication::translate("MainWindow", "Max_Size", nullptr));
        DataMethods->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        SizeMethods->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        CapacityMethods->setText(QCoreApplication::translate("MainWindow", "Capacity", nullptr));
        SwapMethods->setText(QCoreApplication::translate("MainWindow", "Swap", nullptr));
        Pop_BackMethods->setText(QCoreApplication::translate("MainWindow", "Pop_Back", nullptr));
        BackMethods->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        FrontMethods->setText(QCoreApplication::translate("MainWindow", "Front", nullptr));
        Push_BackMethods->setText(QCoreApplication::translate("MainWindow", "Push_Back", nullptr));
        AtMethods->setText(QCoreApplication::translate("MainWindow", "At", nullptr));
        ReserveMethods->setText(QCoreApplication::translate("MainWindow", "Reserve", nullptr));
        ResizeMethods->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        AssignMethods->setText(QCoreApplication::translate("MainWindow", "Assign", nullptr));
        InsertMethods->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        EraseMethods->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        EmplaceMethods->setText(QCoreApplication::translate("MainWindow", "Emplace", nullptr));
        Emplace_BackMethods->setText(QCoreApplication::translate("MainWindow", "Emplace_Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
