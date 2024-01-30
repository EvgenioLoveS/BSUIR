#ifndef TASKRECORD_H
#define TASKRECORD_H
#include <QString>
#include <QDate>

class TaskRecord
{
public:
    TaskRecord() : projectName(QString()), taskName(QString()),
        employeeName(QString()), supervisorName(QString()),
        dateOfAssignment(QDate()), deadline(QDate()),
        dateOfCompletion(QDate())
    {}
    TaskRecord(const QString& projectName, const QString& taskName,
               const QString& employeeName, const QString& supervisorName,
               const QDate& dateOfAssignment, const QDate& deadline,
               const QDate& dateOfCompletion)
        : projectName(projectName), taskName(taskName),
          employeeName(employeeName), supervisorName(supervisorName),
          dateOfAssignment(dateOfAssignment), deadline(deadline),
          dateOfCompletion(dateOfCompletion)
    {}

    bool operator==(const TaskRecord& other) const {
        return projectName == other.projectName && taskName == other.taskName &&
               employeeName == other.employeeName && supervisorName == other.supervisorName &&
               dateOfAssignment == other.dateOfAssignment && deadline == other.deadline &&
               dateOfCompletion == other.dateOfCompletion;
    }

    QString projectName;
    QString taskName;
    QString employeeName;
    QString supervisorName;
    QDate dateOfAssignment;
    QDate deadline;
    QDate dateOfCompletion;
};

#endif // TASKRECORD_H
