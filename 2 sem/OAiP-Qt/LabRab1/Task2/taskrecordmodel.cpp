#include "taskrecordmodel.h"

void TaskRecordModel::addTaskRecord(const TaskRecord record)
{
    m_records.append(record);
}

void TaskRecordModel::removeTaskRecord(int row)
{
    if (row >= 0 && row < m_records.size()) {
        m_records.removeAt(row);
    }
}

void TaskRecordModel::removeTaskRecord(const TaskRecord record) {
    m_records.removeAll(record);
}

void TaskRecordModel::replaceTaskRecord(const TaskRecord oldRecord, const TaskRecord newRecord) {
    m_records.replace(m_records.indexOf(oldRecord), newRecord);
}

TaskRecord TaskRecordModel::getTaskRecord(int row) const
{
    if (row >= 0 && row < m_records.size()) {
        return m_records.at(row);
    }
    return TaskRecord();
}

void TaskRecordModel::clear()
{
    m_records.clear();
}
