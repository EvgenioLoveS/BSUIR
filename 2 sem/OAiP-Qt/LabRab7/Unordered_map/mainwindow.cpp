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

Unordered_map<int,int> mapp;

template<class KeyType, class ValueType>
std::string unorderedMapToString(const std::unordered_map<KeyType, ValueType>& map) {
    std::string result;
    for (const auto& pair : map) {
        result += "(" + std::to_string(pair.first) + ", " + std::to_string(pair.second) + ") ";
    }
    return result;
}

void MainWindow::on_pushButton_insert_clicked()
{
    ui->listWidget->clear();
    bool temp;
    int key = ui->lineEdit_key->text().toInt(&temp);
    if (!temp) {
        return;
    }
    int value = ui->lineEdit_value->text().toInt();
    map.insert({key, value});
    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
    std::string string = unorderedMapToString(map);
    QString qstring_temp = QString::fromStdString(string);
    ui->listWidget->addItem(qstring_temp);
}


void MainWindow::on_pushButton_find_clicked()
{
    ui->listWidget->clear();
    bool temp;
    int key = ui->lineEdit_key->text().toInt(&temp);
    if (!temp) {
        return;
    }
    std::string string_temp = "";
    if (auto search = map.find(key); search != map.end())
        string_temp = "Found " + std::to_string(search->first) + " " + std::to_string(search->second) + '\n';
    else
        string_temp = "Not found\n";

    QString qstring_temp = QString::fromStdString(string_temp);
    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
    ui->listWidget->addItem(qstring_temp);
}


void MainWindow::on_pushButton_erase_clicked()
{
    ui->listWidget->clear();
    bool temp;
    int key = ui->lineEdit_key->text().toInt(&temp);
    if (!temp) {
        return;
    }
    for (auto it = map.begin(); it != map.end();)
    {
        if (it->first == key)
            it = map.erase(it);
        else
            ++it;
    }
    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
    std::string string_temp = unorderedMapToString(map);
    QString qstring_temp = QString::fromStdString(string_temp);
    ui->listWidget->addItem(qstring_temp);
}


void MainWindow::on_pushButton_contains_clicked()
{
    ui->listWidget->clear();
    bool temp;
    int key = ui->lineEdit_key->text().toInt(&temp);
    if (!temp) {
        return;
    }
    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
    std::string string_temp = "";

    if (auto search = map.find(key); search != map.end())
        string_temp = "Found " + std::to_string(search->first) + " " + std::to_string(search->second) + '\n';
    else
        string_temp = "Not found\n";

    if(string_temp != "Not found\n")
    {
        ui->listWidget->addItem("YES");
    }
    else
    {
        ui->listWidget->addItem("NO");
    }
}


void MainWindow::on_pushButton_size_clicked()
{
    ui->listWidget->clear();
    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
    std::string string_temp = std::to_string(map.size());
    QString qstring_temp = QString::fromStdString(string_temp);
    ui->listWidget->addItem(qstring_temp);
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->listWidget->clear();
    map.clear();
    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
}

