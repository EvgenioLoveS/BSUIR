using System;
using System.Collections.Generic;
using _253504_zhgutov_Lab7.Contracts;
using _253504_zhgutov_Lab7.Entities;

namespace _253504_zhgutov_Lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            Journal journal = new Journal();
            
            AtsSystem atsSystem = new AtsSystem(); 
            
            atsSystem.TariffChanged += journal.RegisterTariffChange;
            atsSystem.ClientListChanged += journal.RegisterClientListChange;

            atsSystem.CallEvent += (sender, e) =>
            {
                Console.WriteLine($"[New Call Event] Caller: {e.Caller}, Destination City: {e.DestinationCity}");
            };

            atsSystem.AddTariff("City1", 0.1m);
            atsSystem.AddTariff("City2", 0.2m);

            atsSystem.AddCustomer("Smith");
            atsSystem.AddCustomer("Johnson");
            
            atsSystem.RegisterCall("Smith", "City1", 10);
            atsSystem.RegisterCall("Smith", "City2", 15);
            atsSystem.RegisterCall("Johnson", "City1", 5);
            
            decimal totalCost = atsSystem.CalculateTotalCost();
            Console.WriteLine($"Общая стоимость всех звонков: {totalCost}");

            string maxPayingClient = atsSystem.GetClientWithMaxPayment();
            Console.WriteLine($"Клиент, заплативший максимальную сумму: {maxPayingClient}");

            int clientsAboveAmount = atsSystem.GetClientsCountWithPaymentAbove(10);
            Console.WriteLine($"Количество клиентов, заплативших больше 10: {clientsAboveAmount}");

            Dictionary<string, decimal> clientPaymentsByTariff = atsSystem.GetClientPaymentsByTariff();
            Console.WriteLine("Суммы, заплаченные клиентами по каждому тарифу:");
            foreach (var kvp in clientPaymentsByTariff)
            {
                Console.WriteLine($"{kvp.Key}: {kvp.Value}");
            }

            List<string> sortedTariffNames = atsSystem.GetSortedTariffNamesByRate();
            Console.WriteLine("Отсортированный список названий тарифов по стоимости:");
            foreach (var tariffName in sortedTariffNames)
            {
                Console.WriteLine(tariffName);
            }

            journal.PrintEventLog();
        }
    }
}
