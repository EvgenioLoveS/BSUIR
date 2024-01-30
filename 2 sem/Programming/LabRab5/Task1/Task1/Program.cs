// See https://aka.ms/new-console-template for more information

using System;
using System.Collections.Generic;

namespace Task1;

internal class program
{
    // перечисление для класса обслуживания (эконом, бизнес и т.д.)
    static void Main(string[] args)
    {
        Airport airport = new();
        airport.AddTariff(new Tariff { Direction = "Moscow", Cost = 10000, ServiceClass = ServiceClass.Economy });
        airport.AddTariff(new Tariff { Direction = "New York", Cost = 5000, ServiceClass = ServiceClass.Business });
        airport.AddTariff(new Tariff { Direction = "Paris", Cost = 2000, ServiceClass = ServiceClass.Economy });

        // выводим список тарифов на экран
        Console.WriteLine("Tariffs:");
        foreach (Tariff tariff in airport.GetTariffs())
        {
            Console.WriteLine(
                $"Direction: {tariff.Direction}, Cost: {tariff.Cost}, Service class: {tariff.ServiceClass}");
        }

        // регистрируем покупку билетов
        Passenger passenger1 = new Passenger("Zhenya");
        airport.RegisterTicketPurchase(new Ticket(airport.GetTariffs()[0], passenger1));
        airport.RegisterTicketPurchase(new Ticket(airport.GetTariffs()[2], passenger1));

        // расчет стоимости купленных билетов пассажиром
        Console.WriteLine($"Passenger1 ticket cost: {airport.CalculatePassengerTicketsCost(passenger1)}");

        // расчет стоимости всех проданных билетов
        Console.WriteLine($"All tickets cost: {airport.CalculateAllTicketsCost()}");

        Console.ReadKey();
    }
}