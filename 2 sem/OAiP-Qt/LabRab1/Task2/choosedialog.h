#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include "taskrecordmodel.h"

class ChooseDialog : public QDialog
{
    Q_OBJECT
public:
    enum ChooseParam { projectName, taskName, employeeName,
                        supervisorName, dateOfAssignment,
                        deadline, dateOfCompletion };

    ChooseDialog(const TaskRecordModel &model, const ChooseParam param, QWidget *parent = nullptr);
    TaskRecord getTaskRecord() const;

private:
    const TaskRecordModel m_model;
    QComboBox *taskRecordsComboBox;
    QPushButton *acceptButton, *rejectButton;
};

#endif // CHOOSEDIALOG_H
