#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_task_clicked()
{
    ui->listWidget->clear();
    task tempHT = task(10);
    tempHT.deleteNodesWithEvenKeys();
    std::string temp_string = "";
    tempHT.print(temp_string);
    QString tempQString = QString::fromStdString(temp_string);
    ui->listWidget->addItem(tempQString);
}

void MainWindow::on_pushButton_add_clicked() {
    std::string temp_string = "";
    ui->listWidget->clear();
    bool temp;
    int key = ui->keyLineEdit->text().toInt(&temp);
    if (!temp) {
        return;
    }
    int value = ui->valueLineEdit->text().toInt(&temp);
    table.put(key, value);
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();

    table.print(temp_string);
    QString temp_QString = QString::fromStdString(temp_string);
    ui->listWidget->addItem(temp_QString);
}

void MainWindow::on_pushButton_get_clicked()
{
    ui->listWidget->clear();
    bool temp;
    int key = ui->keyLineEdit->text().toInt(&temp);
    if (!temp)
    {
        return;
    }
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();

    int value = table.get(key);
    QString temp_QString = QString::number(value);
    ui->listWidget->addItem(temp_QString);
}

void MainWindow::on_pushButton_remove_clicked()
{
    std::string temp_string = "";
    ui->listWidget->clear();
    bool temp;
    int key = ui->keyLineEdit->text().toInt(&temp);
    if (!temp)
    {
        return;
    }

    table.remove(key);
    table.print(temp_string);
    QString temp_QString = QString::fromStdString(temp_string);
    ui->listWidget->addItem(temp_QString);
}

void MainWindow::on_pushButton_size_clicked()
{
    ui->listWidget->clear();
    int value = table.size();
    QString temp_QString = QString::number(value);
    ui->listWidget->addItem(temp_QString);
}
