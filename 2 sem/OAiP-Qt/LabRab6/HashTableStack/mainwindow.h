#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <HashTable.h>
#include <task.h>
#include <QString>
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
    void on_pushButton_add_clicked();

    void on_pushButton_get_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_size_clicked();

    void on_pushButton_task_clicked();

private:
    Ui::MainWindow *ui;
    HashTable table;
};
#endif // MAINWINDOW_H
