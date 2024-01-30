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

void MainWindow::on_pushButton_isEmpty_clicked()
{
    if (deque.isEmpty()) {
        QMessageBox::information(this, "Empty", "Deque is empty");
    } else {
        QMessageBox::information(this, "Not Empty", "Deque is not empty");
    }
}

void MainWindow::on_pushButton_getSize_clicked()
{
    int size = deque.getSize();
    QMessageBox::information(this, "Size", "Deque size is: " + QString::number(size));
}

void MainWindow::on_pushButton_clear_clicked()
{
    // Очистка очереди myQueue
    deque.clear();

    // Очистка списка элементов listWidget
    ui->listWidget->clear();
}

void MainWindow::on_pushButton_push_back_clicked()
{
    // Получение значения из QLineEdit
    QString input = ui->lineEdit->text();
    // Преобразование QString в int
    int value = input.toInt();

    // Добавление элемента в конец дека
    deque.push_back(value);

    // Вывод элементов дека в QListWidget
    ui->listWidget->clear(); // Очистка списка элементов
    for (int i = 0; i < deque.getSize(); ++i) {
        QListWidgetItem *item = new QListWidgetItem(QString::number(deque[i]), ui->listWidget);
        ui->listWidget->addItem(item);
    }

    // Очистка QLineEdit
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_push_front_clicked()
{
    // Получение значения из QLineEdit
    QString input = ui->lineEdit_2->text();
    // Преобразование QString в int
    int value = input.toInt();

    // Добавление элемента в начало дека
    deque.push_front(value);

    // Вывод элементов дека в QListWidget
    ui->listWidget->clear(); // Очистка списка элементов
    for (int i = 0; i < deque.getSize(); ++i) {
        QListWidgetItem *item = new QListWidgetItem(QString::number(deque[i]), ui->listWidget);
        ui->listWidget->addItem(item);
    }

    // Очистка QLineEdit
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_pop_back_clicked()
{
    // Удаление последнего элемента из дека
    deque.pop_back();

    // Вывод элементов дека в QListWidget
    ui->listWidget->clear(); // Очистка списка элементов
    for (int i = 0; i < deque.getSize(); ++i) {
        QListWidgetItem *item = new QListWidgetItem(QString::number(deque[i]), ui->listWidget);
        ui->listWidget->addItem(item);
    }
}

void MainWindow::on_pushButton_pop_front_clicked()
{
    // Удаление первого элемента из дека
    deque.pop_front();

    // Вывод элементов дека в QListWidget
    ui->listWidget->clear(); // Очистка списка элементов
    for (int i = 0; i < deque.getSize(); ++i) {
        QListWidgetItem *item = new QListWidgetItem(QString::number(deque[i]), ui->listWidget);
        ui->listWidget->addItem(item);
    }
}
