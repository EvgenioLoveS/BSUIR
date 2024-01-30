#ifndef TASKRECORDMODEL_H
#define TASKRECORDMODEL_H

#include <QList>
#include "taskrecord.h"

class TaskRecordModel
{
public:
    TaskRecordModel() {}

    int rowCount() const { return m_records.size(); }
    int columnCount() const { return 7; }

    void addTaskRecord(const TaskRecord record);
    void removeTaskRecord(int row);
    void removeTaskRecord(const TaskRecord record);
    void replaceTaskRecord(const TaskRecord oldRecord, const TaskRecord newRecord);
    TaskRecord getTaskRecord(int row) const;
    void clear();

private:
    QList<TaskRecord> m_records;
};

#endif // TASKRECORDMODEL_H
