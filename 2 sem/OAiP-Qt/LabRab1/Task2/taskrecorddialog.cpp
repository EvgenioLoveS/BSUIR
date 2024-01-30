#include "taskrecorddialog.h"

TaskRecordDialog::TaskRecordDialog(TaskRecord record, QWidget *parent)
    : QDialog(parent)
{
    projectNameEdit = new QLineEdit(record.projectName);
    taskNameEdit = new QLineEdit(record.taskName);
    employeeNameEdit = new QLineEdit(record.employeeName);
    supervisorNameEdit = new QLineEdit(record.supervisorName);
    dateOfAssignmentEdit = new QDateEdit(record.dateOfAssignment);
//    dateOfCompletionEdit->setDisplayFormat("dd.MM.yyyy");
    deadlineEdit = new QDateEdit(record.deadline);
//    deadlineEdit->setDisplayFormat("dd.MM.yyyy");
    dateOfCompletionEdit = new QDateEdit(record.dateOfCompletion);
//    dateOfCompletionEdit->setDisplayFormat("dd.MM.yyyy");

    acceptButton = new QPushButton(tr("OK"));
    rejectButton = new QPushButton(tr("Cancel"));

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow(tr("Project Name:"), projectNameEdit);
    formLayout->addRow(tr("Task Name:"), taskNameEdit);
    formLayout->addRow(tr("Employee Name:"), employeeNameEdit);
    formLayout->addRow(tr("Supervisor Name:"), supervisorNameEdit);
    formLayout->addRow(tr("Date of Assignment:"), dateOfAssignmentEdit);
    formLayout->addRow(tr("Deadline:"), deadlineEdit);
    formLayout->addRow(tr("Date of Completion:"), dateOfCompletionEdit);
    formLayout->addRow(rejectButton, acceptButton);

    setLayout(formLayout);

    connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(reject()));
}

TaskRecord TaskRecordDialog::getTaskRecord() {
    return TaskRecord(projectNameEdit->text(), taskNameEdit->text(),
                      employeeNameEdit->text(), supervisorNameEdit->text(),
                      dateOfAssignmentEdit->date(), deadlineEdit->date(),
                      dateOfCompletionEdit->date());
}
