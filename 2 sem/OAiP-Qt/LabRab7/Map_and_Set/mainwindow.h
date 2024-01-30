#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <set>
#include <map>
#include "RB_MAP.h"
#include "RB_SET.h"
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
    void on_pushButton_insert_clicked();

    void on_pushButton_erase_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_find_clicked();

private:
    Ui::MainWindow *ui;
    std::set<int> mySet;
    std::map<int, int> myMap;
    std::pair<int,int> p;
};
#endif // MAINWINDOW_H
