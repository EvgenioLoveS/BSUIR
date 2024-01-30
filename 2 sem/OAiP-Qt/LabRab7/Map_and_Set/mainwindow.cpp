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

std::string setToString(const std::set<int>& mySet) {
    std::string result = "{";

    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        result += std::to_string(*it);
        if (std::next(it) != mySet.end()) {
            result += ", ";
        }
    }

    result += "}";
    return result;
}

template<typename Key, typename Value>
std::string mapToString(const std::map<Key, Value>& myMap) {
    std::string result = "{";

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        result += std::to_string(it->first) + ": " + std::to_string(it->second);
        if (std::next(it) != myMap.end()) {
            result += ", ";
        }
    }

    result += "}";
    return result;
}

void MainWindow::on_pushButton_insert_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    bool temp;
    int key = ui->lineEdit_key->text().toInt(&temp);
    if (!temp) {
        return;
    }

    int value = ui->lineEdit_value->text().toInt();

    mySet.insert(value);
    myMap.insert(std::pair<int, int>(key, value));
    std::string str1 = setToString(mySet);
    std::string str2 = mapToString(myMap);

    ui->listWidget->addItem(QString::fromStdString(str1));
    ui->listWidget_2->addItem(QString::fromStdString(str2));

    ui->lineEdit_value->clear();
    ui->lineEdit_key->clear();
}


void MainWindow::on_pushButton_erase_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    bool temp;
    int key = ui->lineEdit_value->text().toInt(&temp);
    if (!temp) {
        return;
    }

    int value = ui->lineEdit_key->text().toInt();

    mySet.erase(value);
    myMap.erase(key);
    std::string str1 = setToString(mySet);
    std::string str2 = mapToString(myMap);

    ui->listWidget->addItem(QString::fromStdString(str1));
    ui->listWidget_2->addItem(QString::fromStdString(str2));

    ui->lineEdit_value->clear();
    ui->lineEdit_key->clear();
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    mySet.clear();
    myMap.clear();

    ui->lineEdit_value->clear();
    ui->lineEdit_key->clear();
}


void MainWindow::on_pushButton_find_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    bool temp;
    int key = ui->lineEdit_key->text().toInt(&temp);
    if (!temp) {
        return;
    }
    std::string string_temp = "";
    if (auto search = myMap.find(key); search != myMap.end())
        string_temp = "Found " + std::to_string(search->first) + " " + std::to_string(search->second) + '\n';
    else
        string_temp = "Not found\n";

    QString qstring_temp = QString::fromStdString(string_temp);
    ui->lineEdit_value->clear();
    ui->lineEdit_key->clear();
    ui->listWidget->addItem(qstring_temp);
}
