#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"
#include <QTabWidget>
#include <QString>
#include <QTableWidgetItem>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

            ui->funcWidget->setRowCount(12);
            ui->funcWidget->setColumnCount(1);

            QString text1="memcpy";
            QTableWidgetItem* newitem1 = new QTableWidgetItem(text1);
            ui->funcWidget->setItem(0,0,newitem1);
            newitem1->setFlags(Qt::ItemIsEditable);

            QString text2="memmove";
            QTableWidgetItem* newitem2 = new QTableWidgetItem(text2);
            ui->funcWidget->setItem(1,0,newitem2);
            newitem2->setFlags(Qt::ItemIsEditable);

            QString text3="strcpy";
            QTableWidgetItem* newitem3 = new QTableWidgetItem(text3);
            ui->funcWidget->setItem(2,0,newitem3);
            newitem3->setFlags(Qt::ItemIsEditable);

            QString text4="strncpy";
            QTableWidgetItem* newitem4 = new QTableWidgetItem(text4);
            ui->funcWidget->setItem(3,0,newitem4);
            newitem4->setFlags(Qt::ItemIsEditable);

            QString text5="strcat";
            QTableWidgetItem* newitem5 = new QTableWidgetItem(text5);
            ui->funcWidget->setItem(4,0,newitem5);
            newitem5->setFlags(Qt::ItemIsEditable);

            QString text6="strncat";
            QTableWidgetItem* newitem6 = new QTableWidgetItem(text6);
            ui->funcWidget->setItem(5,0,newitem6);
            newitem6->setFlags(Qt::ItemIsEditable);

            QString text7="memcmp";
            QTableWidgetItem* newitem7 = new QTableWidgetItem(text7);
            ui->funcWidget->setItem(6,0,newitem7);
            newitem7->setFlags(Qt::ItemIsEditable);

            QString text8="strcmp";
            QTableWidgetItem* newitem8 = new QTableWidgetItem(text8);
            ui->funcWidget->setItem(7,0,newitem8);
            newitem8->setFlags(Qt::ItemIsEditable);

            QString text9="strncmp";
            QTableWidgetItem* newitem10 = new QTableWidgetItem(text9);
            ui->funcWidget->setItem(8,0,newitem10);
            newitem10->setFlags(Qt::ItemIsEditable);

            QString text10="strtok";
            QTableWidgetItem* newitem12 = new QTableWidgetItem(text10);
            ui->funcWidget->setItem(9,0,newitem12);
            newitem12->setFlags(Qt::ItemIsEditable);

            QString text11="memset";
            QTableWidgetItem* newitem13 = new QTableWidgetItem(text11);
            ui->funcWidget->setItem(10,0,newitem13);
            newitem13->setFlags(Qt::ItemIsEditable);

            QString text12="strlen";
            QTableWidgetItem* newitem14 = new QTableWidgetItem(text12);
            ui->funcWidget->setItem(11,0,newitem14);
            newitem14->setFlags(Qt::ItemIsEditable);
}

MyString string1_for_laba4 = "zhenya";
MyString string2_for_laba4 = "sasha";

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_output_answer_clicked()
{
    QTableWidgetItem * tbl = ui->funcWidget->currentItem();
    QString text = tbl->text();

    if(text=="memcpy"){

        void* a = reinterpret_cast<void*>(const_cast<char*>(string1_for_laba4.getData()));
        const void* s = reinterpret_cast<const void*>(string2_for_laba4.getData());
        MyString q;

        q.mymemcpy(a, s, 3);// c какой позиции указывает число

        QString wer = QString::fromStdString(static_cast<const char*>(a));

        QMessageBox::information(this,"Title",wer);
    }

    else if(text=="memmove"){
        QString ff=ui->input_string->text();
        void* a = reinterpret_cast<void*>(const_cast<char*>(string1_for_laba4.getData()));
        const void* s = reinterpret_cast<const void*>(string2_for_laba4.getData());
        MyString q;
        q.mymemmove(a, s, 3);// c какой позиции указывает число
        QString wer = QString::fromStdString(static_cast<const char*>(a));

        QMessageBox::information(this,"Title",wer);
    }
    else if(text=="strcpy"){
        char* a = reinterpret_cast<char*>(const_cast<char*>(string1_for_laba4.getData()));
        const char* s = reinterpret_cast<const char*>(string2_for_laba4.getData());
        MyString q;
        q.mystrcpy(a,s);
        QString wer = QString::fromStdString(static_cast<const char*>(a));
        QMessageBox::information(this,"Title",wer);
    }

    else if(text=="strncpy"){
        char* a = reinterpret_cast<char*>(const_cast<char*>(string1_for_laba4.getData()));
        const char* s = reinterpret_cast<const char*>(string2_for_laba4.getData());
        MyString q;
        q.mystrncpy(a,s,4);
        QString wer = QString::fromStdString(static_cast<const char*>(a));
        QMessageBox::information(this,"Title",wer);


    }

    else if(text=="strcat"){
        char* a = reinterpret_cast<char*>(const_cast<char*>(string1_for_laba4.getData()));
        const char* s = reinterpret_cast<const char*>(string2_for_laba4.getData());
        MyString q;
        q.mystrcat(a,s);
        QString wer = QString::fromStdString(static_cast<const char*>(a));
        QMessageBox::information(this,"Title",wer);


    }

    else if(text=="memcmp"){//тут инт должно быть так что мб ошибка

        void* a = reinterpret_cast<void*>(const_cast<char*>(string1_for_laba4.getData()));
        const void* s = reinterpret_cast<const void*>(string2_for_laba4.getData());
        MyString q;
        int falas = q.mymemcmp(a, s, 3);// c какой позиции указывает число
        QString wer = QString::number(falas);
        QMessageBox::information(this,"Title",wer);

    }

    else if(text=="strcmp"){
        char* a = reinterpret_cast<char*>(const_cast<char*>(string1_for_laba4.getData()));
        const char* s = reinterpret_cast<const char*>(string2_for_laba4.getData());
        MyString q;
        q.mystrcmp(a,s);
        QString wer = QString::fromStdString(static_cast<const char*>(a));
        QMessageBox::information(this,"Title",wer);
    }


    else if(text=="strncmp"){
        char* a = reinterpret_cast<char*>(const_cast<char*>(string1_for_laba4.getData()));
        const char* s = reinterpret_cast<const char*>(string2_for_laba4.getData());
        MyString q;
        q.mystrncmp(a,s,2);
        QString wer = QString::fromStdString(static_cast<const char*>(a));
        QMessageBox::information(this,"Title",wer);
    }

    else if(text=="strtok"){
        char* a = reinterpret_cast<char*>(const_cast<char*>(string1_for_laba4.getData()));
        const char* s = reinterpret_cast<const char*>(string2_for_laba4.getData());
        MyString q;
        char *piska = q.mystrtok(a,s);
        QString wer = QString::fromStdString(static_cast<const char*>(piska));
        QMessageBox::information(this,"Title",wer);
    }
    else if(text=="memset"){//хз поч непонятные символы
        void* a = reinterpret_cast<void*>(const_cast<char*>(string1_for_laba4.getData()));
        const void* s = reinterpret_cast<const void*>(string2_for_laba4.getData());
        MyString q;
        q.mymemset(a, 4, 3);// c какой позиции указывает число
        QString wer = QString::fromStdString(static_cast<const char*>(a));
        QMessageBox::information(this,"Title",wer);
    }
    else if(text=="strlen"){
        QString ff=ui->input_string->text();
        char* a= static_cast<char*>(ff.toUtf8().data());
        QString aa=string1_for_laba4.mystrcpy(string2_for_laba4,a);
        int len=ff.size();
        QMessageBox::information(this,"Title",QString::number(len));
    }

    else QMessageBox::information(this,"Title", "404:(");
}

