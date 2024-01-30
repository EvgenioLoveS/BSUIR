#include "choosedialog.h"
#include <QGridLayout>

ChooseDialog::ChooseDialog(const TaskRecordModel &model, const ChooseParam param, QWidget *parent)
    : QDialog(parent), m_model(model)
{
    taskRecordsComboBox = new QComboBox;
    switch (param) {
    case projectName: {
        for (int i = 0; i < m_model.rowCount(); i++) {
            taskRecordsComboBox->addItem(m_model.getTaskRecord(i).projectName);
        }
    } break;
    case taskName: {
        for (int i = 0; i < m_model.rowCount(); i++) {
            taskRecordsComboBox->addItem(m_model.getTaskRecord(i).taskName);
        }
    } break;
    case employeeName: {
        for (int i = 0; i < m_model.rowCount(); i++) {
            taskRecordsComboBox->addItem(m_model.getTaskRecord(i).employeeName);
        }
    } break;
    case supervisorName: {
        for (int i = 0; i < m_model.rowCount(); i++) {
            taskRecordsComboBox->addItem(m_model.getTaskRecord(i).supervisorName);
        }
    } break;
    case dateOfAssignment: {
        for (int i = 0; i < m_model.rowCount(); i++) {
            taskRecordsComboBox->addItem(m_model.getTaskRecord(i).dateOfAssignment.toString());
        }
    } break;
    case deadline: {
        for (int i = 0; i < m_model.rowCount(); i++) {
            taskRecordsComboBox->addItem(m_model.getTaskRecord(i).deadline.toString());
        }
    } break;
    case dateOfCompletion: {
        for (int i = 0; i < m_model.rowCount(); i++) {
            taskRecordsComboBox->addItem(m_model.getTaskRecord(i).dateOfCompletion.toString());
        }
    } break;
    }

    acceptButton = new QPushButton(tr("OK"));
    rejectButton = new QPushButton(tr("Cancel"));

    QGridLayout *formLayout = new QGridLayout();
    formLayout->addWidget(taskRecordsComboBox, 0, 0, 1, 2);
    formLayout->addWidget(rejectButton, 1, 0, 1, 1);
    formLayout->addWidget(acceptButton, 1, 1, 1, 1);

    setLayout(formLayout);

    connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(reject()));
}

TaskRecord ChooseDialog::getTaskRecord() const {
    int selected = taskRecordsComboBox->currentIndex();
    return m_model.getTaskRecord(selected);
}
