#include <DATE.h>
#include <ctime>
#include <cmath>

const short Date::DAYS_IN_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int temp_year, int temp_month, int temp_day)
    : year(temp_year)
    , month(temp_month)
    , day(temp_day)
    , days(0)
{
    for (int i = 1; i < month; i++) // индекс месяца должен начинаться с 1
    {
        days += DAYS_IN_MONTH[i];
    }
    if (isLeap() && month == 2) // проверка на високосный год и февраль
    {
        days++;
    }
}

void Date::input(QString text)
{
    int size_of_dates = dates->length();
    QString* arr2 = new QString[size_of_dates + 1];
    for (int i = 0; i < size_of_dates; i++)
    {
        arr2[i] = dates[i];
    }
    dates[size_of_dates] = text;
    dates = arr2;
}

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
    days = 0;
}

Date Date::nextDay()
{
   if((month % 12 == 0) && (day == 31))
   {
       return Date(year+1, 1, 1);
   }
   if((day == 29) && (month == 2))
   {
       return Date(year, 3, 1);
   }
   if(day==DAYS_IN_MONTH[month-1])
   {
       return Date(year, month+1, 1);
   }
   return Date(year, month, day+1);
}

bool Date::isLeap()
{
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    return false;
}

    Date Date::previousDay()
    {
        if((month == 1)&&(day == 1))
        {
            return Date(year - 1, 12, 31);
        }
        if (day == 1)
        {
            if (month == 3 && isLeap())
            {
                return Date(year, 2, 29);
            }
            return Date(year, month - 1, DAYS_IN_MONTH[month-2]);
        }
        return Date(year, month, day-1);
    }

short Date::weekNumber()
{
    return ((days + day) / 7 + 1);
}


int Date::daysTillYourBithday(Date birthdaydate)
{
    QDate currentDate = QDate::currentDate();
    QDate birthdayThisYear = QDate(currentDate.year(), birthdaydate.month, birthdaydate.day);
    QDate nextBirthday = (birthdayThisYear < currentDate) ? birthdayThisYear.addYears(1) : birthdayThisYear;
    return currentDate.daysTo(nextBirthday);
}

int Date::duration(Date date)
{
    QDate currentDate = QDate::currentDate();
    int curDay = currentDate.day();
    int curMonth = currentDate.month();
    int curYear = currentDate.year();

    QDate dt1(date.year, date.month, date.day);
    QDate dt2(curYear, curMonth, curDay);

    int diff1 = dt1.toJulianDay();
    int diff2 = dt2.toJulianDay();
    int result = qAbs(diff1 - diff2);

    return result;
}


QString Date::str()
{
    return QDate(year,month,day).toString("dd.MM.yyyy");
}

QString Date::boolToString(bool temp)
{
    return temp ? "Yes" : "No";
}

QString Date::shortToString(short temp)
{
    return QString::number(temp);
}

QString Date::intToString(int temp)
{
    return QString::number(temp);
}

