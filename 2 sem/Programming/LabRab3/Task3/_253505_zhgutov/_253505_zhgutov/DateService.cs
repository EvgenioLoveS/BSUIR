namespace _253505_zhgutov;

public class DateService
{
    // Метод определяет день недели произвольной даты, передаваемой методу в качестве строки
    public static string GetDay(string date)
    {
        DateTime dt;
        if (DateTime.TryParse(date, out dt))
        {
            return dt.ToString("dddd");
        }
        else
        {
            throw new ArgumentException("Неверный формат даты");
        }
    }

    // Метод определяет, сколько дней пройдет между текущей датой и датой, передаваемой методу в качестве числовых параметров: день, месяц, год
    public static int GetDaysSpan(int day, int month, int year)
    {
        DateTime dt = new DateTime(year, month, day);
        TimeSpan span = dt - DateTime.Now;
        return span.Days;
    }
}