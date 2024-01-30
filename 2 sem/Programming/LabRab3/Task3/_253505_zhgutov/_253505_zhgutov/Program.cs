// See https://aka.ms/new-console-template for more information

using System;

namespace _253505_zhgutov;

class Program
{
    static void Main(string[] args)
    {
        // Получение дня недели для произвольной даты
        string dayOfWeek = DateService.GetDay("2023-03-10");
        Console.WriteLine("День недели: " + dayOfWeek);

        // Получение количества дней между текущей датой и указанной датой
        int daysSpan = DateService.GetDaysSpan(25, 12, 2023);
        Console.WriteLine("Количество дней между текущей датой и указанной: " + daysSpan);
    }
}