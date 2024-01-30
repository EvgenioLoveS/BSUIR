#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DATE.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QSaveFile>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDate>
#include <QLineEdit>
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
    bool CheckFile(QString date);

    void on_OpenFile_clicked();

    void on_SaveFile_clicked();

    void on_addDate_clicked();

    void on_changeDate_clicked();

    void on_Date_Birthday_Text_userDateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    Date ss = *new Date;
};
#endif // MAINWINDOW_H
