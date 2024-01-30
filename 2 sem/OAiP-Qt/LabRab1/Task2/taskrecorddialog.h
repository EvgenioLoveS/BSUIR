#ifndef TASKRECORDDIALOG_H
#define TASKRECORDDIALOG_H

#include <QDialog>
#include <QDateEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include "taskrecord.h"

class TaskRecordDialog : public QDialog
{
    Q_OBJECT

public:
    TaskRecordDialog(TaskRecord record = TaskRecord(), QWidget *parent = nullptr);
    TaskRecord getTaskRecord();

private:
    QLineEdit *projectNameEdit;
    QLineEdit *taskNameEdit;
    QLineEdit *employeeNameEdit;
    QLineEdit *supervisorNameEdit;
    QDateEdit *dateOfAssignmentEdit;
    QDateEdit *deadlineEdit;
    QDateEdit *dateOfCompletionEdit;
    QPushButton *acceptButton, *rejectButton;
};

#endif // TASKRECORDDIALOG_H
