#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyStack.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <string>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("D:/обои/animeshka_komnata_kniga_chitat_vecher_92289_1920x1080.jpg");
            bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            QPalette palette;
            palette.setBrush(QPalette::Background, bkgnd);
            this->setPalette(palette);
}
MainWindow::~MainWindow()
{
    delete ui;
}

int balanced(const std::string& s) {
    MyStack <char> stack;
    int i=0;
    for(char c : s) //Синтаксис такой: слева идентификатор для работы с элементом контейнера, справа контейнер
   {
        switch (c) {
        case '(': stack.push(')'); break;
        case '[': stack.push(']'); break;
        case '{': stack.push('}'); break;

        case ')':
        case ']':
        case '}':
            if (stack.empty() || stack.top() != c) {
                return i;
            }
            stack.pop();
            break;
        default:
            break;
        }
        i++;
    }
    if(stack.empty()){
    return 100;
    }
    else return i-1;
}
void MainWindow::on_pushButton_clicked()
{
    QString filter = "Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "D://253505//OAiP//2sem//C++//LabRab2//Task2", filter);
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(this, "Title", "Не удалось открыть файл");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    if(text.isEmpty()) {
        QMessageBox::information(this, "Title", "Файл пуст");
        return;
    }
    ui->plainTextEdit->setPlainText(text);
}
void MainWindow::on_pushButton_2_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();
    if (text.isEmpty() || text.length() > 50000) {
        QMessageBox::information(this, "Title", "Повторите ввод");
        return;
    }
    int lineCount = ui->plainTextEdit->document()->blockCount();
    int bracketIndex = balanced(text.toStdString());
    QLabel *label = new QLabel();
    label->resize(500, 50);
    if (bracketIndex == 100) {
        label->setText("Success");
    } else {
        label->setText(QString("Неверная скобка: %1 %2").arg(bracketIndex /*+ 1*/).arg(lineCount));
    }
    label->show();
    ui->plainTextEdit->clear();
}
