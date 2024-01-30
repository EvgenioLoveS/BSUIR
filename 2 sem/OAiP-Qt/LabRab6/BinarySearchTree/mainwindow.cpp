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

void MainWindow::updateTreeWidget()
{
    // Очистить содержимое QTreeWidget
    ui->treeWidget->clear();

    // Получить данные для отображения
    std::vector<std::pair<int, std::string>> data = bst.printAscending();

    // Добавить каждый элемент в QTreeWidget
    for (const auto& pair : data)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0, QString::number(pair.first));
        item->setText(1, QString::fromStdString(pair.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);

    if (!ok) {
        return;
    }

    std::string value = ui->valueLineEdit->text().toStdString();

    bst.add(key, value);
    updateTreeWidget();
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
}

void MainWindow::on_pushButton_balanced_clicked()
{
    bst.balanced();
    updateTreeWidget();
}

void MainWindow::on_pushButton_find_clicked()
{
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);

    if (!ok)
    {
        return;
    }

    std::string value = bst.find(key);

    if (!value.empty())
    {
        ui->valueLineEdit->setText(QString::fromStdString(value));
    }

    else
    {
        ui->valueLineEdit->clear();
    }
}

void MainWindow::on_pushButton_deleter_clicked()
{
    bool ok;
    int key = ui->keyLineEdit->text().toInt(&ok);

    if (!ok)
    {
        return;
    }

    bst.deleter(key);
    updateTreeWidget();
    ui->keyLineEdit->clear();
    ui->valueLineEdit->clear();
}

void MainWindow::on_pushButton_printStraight_clicked()
{
    std::vector<std::pair<int, std::string>> temp_vec = bst.printStraight();
    ui->treeWidget->clear();
    for (const auto& p : temp_vec)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(p.first));
        item->setText(1, QString::fromStdString(p.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}

void MainWindow::on_pushButton_printBackward_clicked()
{
    std::vector<std::pair<int, std::string>> temp_vec = bst.printBackward();
    ui->treeWidget->clear();
    for (const auto& p : temp_vec)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(p.first));
        item->setText(1, QString::fromStdString(p.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}

void MainWindow::on_pushButton_printAscending_clicked()
{
    std::vector<std::pair<int, std::string>> temp_vec = bst.printAscending();
    ui->treeWidget->clear();
    for (const auto& p : temp_vec)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(p.first));
        item->setText(1, QString::fromStdString(p.second));
        ui->treeWidget->addTopLevelItem(item);
    }
}

void MainWindow::on_pushButton_countNodesWithOneChild_clicked()
{
    std::vector<std::pair<int, std::string>> temp_vec = bst.printAscending();
    variant9 helper(temp_vec);
    int leaves = helper.countNodesWithOneChild();
    ui->label->setText(QString::number(leaves));
}
