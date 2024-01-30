#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MyDeque.h>
#include <QMessageBox>
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

    void on_pushButton_clear_clicked();

    void on_pushButton_push_back_clicked();

    void on_pushButton_push_front_clicked();

    void on_pushButton_pop_back_clicked();

    void on_pushButton_pop_front_clicked();


private:
    Ui::MainWindow *ui;
    Deque<int> deque;
};
#endif // MAINWINDOW_H
