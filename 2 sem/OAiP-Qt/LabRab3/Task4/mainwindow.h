#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QMessageBox>
#include "vector.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void output_of_vec1(vector<int>& temp_vec);
    void output_of_vec2(vector<int>& temp_vec);

private slots:
    void on_generationVec1_clicked();

    void on_generationVec2_clicked();

    void on_EmptyMethods_clicked();

    void on_ClearMethods_clicked();

    void on_SizeMethods_clicked();

    void on_CapacityMethods_clicked();

    void on_DataMethods_clicked();

    void on_Max_SizeMethods_clicked();

    void on_SwapMethods_clicked();

    void on_BackMethods_clicked();

    void on_FrontMethods_clicked();

    void on_Pop_BackMethods_clicked();

    void on_Push_BackMethods_clicked();

    void on_AtMethods_clicked();

    void on_ReserveMethods_clicked();

    void on_ResizeMethods_clicked();

    void on_AssignMethods_clicked();

    void on_InsertMethods_clicked();

    void on_EraseMethods_clicked();

    void on_EmplaceMethods_clicked();

    void on_Emplace_BackMethods_clicked();

private:
    Ui::MainWindow *ui;
    vector<int> vec1;
    vector<int> vec2;
};
#endif // MAINWINDOW_H
