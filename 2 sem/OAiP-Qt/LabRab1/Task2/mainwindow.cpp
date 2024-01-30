#include "mainwindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTableWidget>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "errordialog.h"
#include "taskrecorddialog.h"
#include "choosedialog.h"
#include "showlistdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_model = new TaskRecordModel();
    _fileName = QString();

    createObjects();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createObjects() {
    createTable();
    createActions();
    createMenus();
    createStatusBar();
}

void MainWindow::createTable() {
    table = new QTableWidget();
    table->setRowCount(64);
    table->setColumnCount(32);
    setCentralWidget(table);
    table->setEditTriggers(0);//
    table->setColumnWidth(0, 200);
    table->setColumnWidth(1, 200);
    table->setColumnWidth(2, 200);
    table->setColumnWidth(2, 200);
    table->setColumnWidth(4, 200);
    table->setColumnWidth(5, 200);
    table->setColumnWidth(6, 200);
    table->setItem(0, 0, new QTableWidgetItem("Project name")); //Название проекта
    table->setItem(0, 1, new QTableWidgetItem("Task Name")); // Название задачи
    table->setItem(0, 2, new QTableWidgetItem("Employee Name"));//Имя сотрудника
    table->setItem(0, 3, new QTableWidgetItem("Supervisor Name")); // Имя руководителя
    table->setItem(0, 4, new QTableWidgetItem("Date of Assignment")); // дата присвоения
    table->setItem(0, 5, new QTableWidgetItem("Deadline")); // Крайний срок
    table->setItem(0, 6, new QTableWidgetItem("Date of Completion")); // Дата завершения
}

void MainWindow::createActions() {
    openFileAction = new QAction(tr("Open"));
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("Open file with dates"));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(openFileSlot()));

    quitAction = new QAction(tr("Quit"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Quit app"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    addRecordAction = new QAction(tr("Add record"));
    connect(addRecordAction, SIGNAL(triggered()), this, SLOT(addRecordSlot()));

    deleteRecordAction = new QAction(tr("Delete selected record"));
    connect(deleteRecordAction, SIGNAL(triggered()), this, SLOT(deleteRecordSlot()));

    editRecordAction = new QAction(tr("Edit selected record"));
    connect(editRecordAction, SIGNAL(triggered()), this, SLOT(editRecordSlot()));

    showAllSupervisorsProjectsAction = new QAction(tr("Show all projects of selected supervisor"));
    connect(showAllSupervisorsProjectsAction, SIGNAL(triggered()),
            this, SLOT(showAllSupervisorsProjectsSlot()));

    showAllEmployeesTasksAction = new QAction(tr("Show all tasks of selected employee"));
    connect(showAllEmployeesTasksAction, SIGNAL(triggered()),
            this, SLOT(showAllEmployeesTasksAction()));

    showAllEmployeesInProjectAction = new QAction(tr("Show all employees of selected projects"));
    connect(showAllEmployeesInProjectAction, SIGNAL(triggered()),
            this, SLOT(showAllEmployeesInProjectSlot()));

    showEmployeesMissedDeadlineAction = new QAction(tr("Show all employees missed deadline"));
    connect(showEmployeesMissedDeadlineAction, SIGNAL(triggered()),
            this, SLOT(showEmployeesMissedDeadlineSlot()));
}

void MainWindow::createMenus() {
    fileMenu = new QMenu(tr("&File"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(quitAction);
    menuBar()->addMenu(fileMenu);

    showSubMenu = new QMenu(tr("Show ..."));
    showSubMenu->addAction(showAllSupervisorsProjectsAction);
    showSubMenu->addAction(showAllEmployeesTasksAction);
    showSubMenu->addAction(showAllEmployeesInProjectAction);
    showSubMenu->addAction(showEmployeesMissedDeadlineAction);

    editMenu = new QMenu(tr("&Edit"));
    editMenu->addAction(addRecordAction);
    editMenu->addAction(deleteRecordAction);
    editMenu->addAction(editRecordAction);
    editMenu->addMenu(showSubMenu);
    menuBar()->addMenu(editMenu);
}

void MainWindow::createStatusBar() {
    filePathLabel = new QLabel(tr("File not opened"));
    statusBar()->addWidget(filePathLabel);
}

void MainWindow::openFileSlot() {
    m_model->clear();
    drawTable();

    QString rootPath;
#ifdef MSDOS
    rootPath = "C:\";
#else
    rootPath = "/home";
#endif
    _fileName = QFileDialog::getOpenFileName(this, tr("Open file"), rootPath);
    QFile file(_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ErrorDialog errorDialog(tr("Can't open file"));
        errorDialog.exec();
        _fileName = QString();
        filePathLabel->setText("File not opened");
        return;
    }

    filePathLabel->setText(_fileName);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(",");
        if (values.size() != 7)
            continue;

        QString projectName = values[0].trimmed();
        QString taskName = values[1].trimmed();
        QString employeeName = values[2].trimmed();
        QString supervisorName = values[3].trimmed();
        QDate dateOfAssignment = QDate::fromString(values[4].trimmed(), "dd.MM.yyyy");
        QDate deadline = QDate::fromString(values[5].trimmed(), "dd.MM.yyyy");
        QDate dateOfCompletion = QDate::fromString(values[6].trimmed(), "dd.MM.yyyy");

        TaskRecord record(projectName, taskName, employeeName, supervisorName,
                          dateOfAssignment, deadline, dateOfCompletion);
        m_model->addTaskRecord(record);
    }

    file.close();
    drawTable();
}

void MainWindow::addRecordSlot() {
    TaskRecordDialog taskRecordDialog;
    int result = taskRecordDialog.exec();

    if (result == QDialog::Accepted)
        m_model->addTaskRecord(taskRecordDialog.getTaskRecord());

    drawTable();
    writeFile();
}

void MainWindow::editRecordSlot() {
    ChooseDialog chooseTaskRecordDialog(*m_model, ChooseDialog::projectName);
    int result = chooseTaskRecordDialog.exec();

    if (result == QDialog::Accepted) {
        TaskRecordDialog taskRecordDialog(chooseTaskRecordDialog.getTaskRecord());
        result = taskRecordDialog.exec();

        if (result == QDialog::Accepted)
            m_model->replaceTaskRecord(chooseTaskRecordDialog.getTaskRecord(), taskRecordDialog.getTaskRecord());
    }

    drawTable();
    writeFile();
}

void MainWindow::deleteRecordSlot() {
    ChooseDialog chooseTaskRecordDialog(*m_model, ChooseDialog::projectName);
    int result = chooseTaskRecordDialog.exec();

    if (result == QDialog::Accepted) {
        m_model->removeTaskRecord(chooseTaskRecordDialog.getTaskRecord());
    }

    drawTable();
    writeFile();
}

void MainWindow::drawTable() {
    int rowCount = m_model->rowCount();
    if (rowCount != 0) {
        table->setRowCount(rowCount + 1);
        table->setColumnCount(m_model->columnCount());
    }
    else {
        table->setRowCount(64);
        table->setColumnCount(32);
    }

    for (int i = 0; i < rowCount; i++) {
        table->setItem(i + 1, 0, new QTableWidgetItem(m_model->getTaskRecord(i).projectName));
        table->setItem(i + 1, 1, new QTableWidgetItem(m_model->getTaskRecord(i).taskName));
        table->setItem(i + 1, 2, new QTableWidgetItem(m_model->getTaskRecord(i).employeeName));
        table->setItem(i + 1, 3, new QTableWidgetItem(m_model->getTaskRecord(i).supervisorName));
        table->setItem(i + 1, 4, new QTableWidgetItem(m_model->getTaskRecord(i).dateOfAssignment.toString("dd.MM.yyyy")));
        table->setItem(i + 1, 5, new QTableWidgetItem(m_model->getTaskRecord(i).deadline.toString("dd.MM.yyyy")));
        table->setItem(i + 1, 6, new QTableWidgetItem(m_model->getTaskRecord(i).dateOfCompletion.toString("dd.MM.yyyy")));
    }
}

void MainWindow::writeFile() {
    QFile file(_fileName);
    QTextStream out(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ErrorDialog errorDialog(tr("Can't open file"));
        errorDialog.exec();
        return;
    }

    for(int i = 0; i < m_model->rowCount(); i++) {
        TaskRecord record = m_model->getTaskRecord(i);
        out << record.projectName << ',' << record.taskName << ','
            << record.employeeName << ',' << record.supervisorName << ','
            << record.dateOfAssignment.toString("dd.MM.yyyy") << ','
            << record.deadline.toString("dd.MM.yyyy") << ','
            << record.dateOfCompletion.toString("dd.MM.yyyy") << "\n";
    }

    file.close();
}

void MainWindow::showAllSupervisorsProjectsSlot() {
    ChooseDialog chooseTaskRecordDialog(*m_model, ChooseDialog::supervisorName);
    int result = chooseTaskRecordDialog.exec();

    if (result == QDialog::Accepted) {
        QList<QString> list;
        for (int i = 0; i < m_model->rowCount(); i++) {
            if (m_model->getTaskRecord(i).supervisorName == chooseTaskRecordDialog.getTaskRecord().supervisorName)
                list.append(m_model->getTaskRecord(i).projectName);
        }

        ShowListDialog showListDialog(list);
        showListDialog.exec();
    }
}

void MainWindow::showAllEmployeesTasksSlot() {
    ChooseDialog chooseTaskRecordDialog(*m_model, ChooseDialog::employeeName);
    int result = chooseTaskRecordDialog.exec();

    if (result == QDialog::Accepted) {
        QList<QString> list;
        for (int i = 0; i < m_model->rowCount(); i++) {
            if (m_model->getTaskRecord(i).employeeName == chooseTaskRecordDialog.getTaskRecord().employeeName)
                list.append(m_model->getTaskRecord(i).taskName);
        }

        ShowListDialog showListDialog(list);
        showListDialog.exec();
    }
}

void MainWindow::showAllEmployeesInProjectSlot() {
    ChooseDialog chooseTaskRecordDialog(*m_model, ChooseDialog::projectName);
    int result = chooseTaskRecordDialog.exec();

    if (result == QDialog::Accepted) {
        QList<QString> list;
        for (int i = 0; i < m_model->rowCount(); i++) {
            if (m_model->getTaskRecord(i).projectName == chooseTaskRecordDialog.getTaskRecord().projectName)
                list.append(m_model->getTaskRecord(i).employeeName);
        }

        ShowListDialog showListDialog(list);
        showListDialog.exec();
    }
}

void MainWindow::showEmployeesMissedDeadlineSlot() {
    QList<QString> list;
    for (int i = 0; i < m_model->rowCount(); i++) {
        if (m_model->getTaskRecord(i).dateOfCompletion == m_model->getTaskRecord(i).deadline)
            list.append(m_model->getTaskRecord(i).employeeName);
    }

    ShowListDialog showListDialog(list);
    showListDialog.exec();
}
