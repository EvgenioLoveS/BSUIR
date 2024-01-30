#ifndef DATE_H
#define DATE_H


#include <QString>
#include <QDate>

class Date{

private:
    int year, month, day, days;
    static const short DAYS_IN_MONTH[12];
    static constexpr int SECONDS_IN_DAY = 3600 * 24;

public:
    QString *dates;
    Date nextDay();
    Date previousDay();
    bool isLeap();
    short weekNumber();
    int daysTillYourBithday(Date birthdaydate);
    int duration (Date date);
    Date();
    Date(int, int, int);
    QString str();
    QString boolToString(bool);
    QString shortToString(short);
    QString intToString(int);
    void input(QString text);
};
#endif // DATE_H
