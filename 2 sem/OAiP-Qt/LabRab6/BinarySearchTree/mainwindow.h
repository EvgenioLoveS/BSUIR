#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <BinarySearchTree.h>
#include <count_nodes.h>
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

    void on_pushButton_balanced_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_deleter_clicked();

    void on_pushButton_printStraight_clicked();

    void on_pushButton_printBackward_clicked();

    void on_pushButton_printAscending_clicked();

    void on_pushButton_countNodesWithOneChild_clicked();

private:
    Ui::MainWindow *ui;

    BinarySearchTree bst;

    void updateTreeWidget();
    void updatePlainTextEdit(const QStringList& list);
};
#endif // MAINWINDOW_H
