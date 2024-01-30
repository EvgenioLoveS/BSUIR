#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Unordered_map.h>
#include <unordered_map>
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
    void on_pushButton_insert_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_erase_clicked();

    void on_pushButton_contains_clicked();

    void on_pushButton_size_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;
    std::unordered_map<int,int> map;
};
#endif // MAINWINDOW_H
