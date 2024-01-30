#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>
#include "taskrecordmodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString _fileName;
    TaskRecordModel* m_model;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFileSlot();
    void addRecordSlot();
    void editRecordSlot();
    void deleteRecordSlot();
    void showAllSupervisorsProjectsSlot();
    void showAllEmployeesTasksSlot();
    void showAllEmployeesInProjectSlot();
    void showEmployeesMissedDeadlineSlot();

private:
    void createTable();
    void createObjects();
    void createActions();
    void createMenus();
    void createStatusBar();
    void drawTable();
    void writeFile();

    QAction *openFileAction, *quitAction, // fileMenu actions
            *addRecordAction, *deleteRecordAction, *editRecordAction,
            *showAllSupervisorsProjectsAction, *showAllEmployeesTasksAction,
            *showAllEmployeesInProjectAction, *showEmployeesMissedDeadlineAction; // editMenu actions

    QMenu *fileMenu, *editMenu, *showSubMenu; //, *viewMenu, *selectViewSubMenu;

    QLabel *filePathLabel;

    QTableWidget* table;
};

#endif // MAINWINDOW_H
