#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyQueue.h"
#include "QMessageBox"
#include <random>
#include <QRandomGenerator>
#include <QString>
#include <QListWidgetItem>
#include <sstream>
#include <QTextStream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_isEmpty_clicked();

    void on_pushButton_getSize_clicked();

    void on_pushButton_enqueue_clicked();

    void on_pushButton_dequeue_clicked();

    void on_pushButton_Front_clicked();

    void on_pushButton_Back_clicked();

    void on_pushButton_clear_clicked();


private:
    Ui::MainWindow *ui;
    MyQueue<int> queue;
};
#endif // MAINWINDOW_H
