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


void MainWindow::on_pushButton_isEmpty_clicked() {
    if (queue.isEmpty()) {
        QMessageBox::information(this, "Empty", "Queue is empty");
    } else {
        QMessageBox::information(this, "Not Empty", "Queue is not empty");
    }
}

void MainWindow::on_pushButton_getSize_clicked()
{
    int size = queue.getSize();
    QMessageBox::information(this, "Size", "Queue size is: " + QString::number(size));
}

void MainWindow::on_pushButton_enqueue_clicked() {
    // Read input from QLineEdit
    QString input = ui->lineEdit->text();
    int value = input.toInt(); // Convert input to integer

    // Enqueue the value to the queue
    queue.push(value);

    // Clear input in QLineEdit
    ui->lineEdit->clear();

    // Update the ListWidget
    QListWidgetItem *item = new QListWidgetItem(QString::number(value));
    ui->listWidget->addItem(item);
}

void MainWindow::on_pushButton_dequeue_clicked() {
    // Dequeue an item from the queue
    queue.pop();

    // Remove the first item from the ListWidget
    if (ui->listWidget->count() > 0) {
        QListWidgetItem *item = ui->listWidget->takeItem(0);
        delete item;
    }
}

void MainWindow::on_pushButton_Front_clicked() {
    // Get the front item from the queue
    int front = queue.front();

    // Display the front item in a QMessageBox
    QMessageBox::information(this, "Front", "Front item is: " + QString::number(front));
}

void MainWindow::on_pushButton_Back_clicked() {
    // Get the back item from the queue
    int back = queue.back();

    // Display the back item in a QMessageBox
    QMessageBox::information(this, "Back", "Back item is: " + QString::number(back));
}

void MainWindow::on_pushButton_clear_clicked()
{
    // Очистка очереди myQueue
    queue.clear();

    // Очистка списка элементов listWidget
    ui->listWidget->clear();
}

