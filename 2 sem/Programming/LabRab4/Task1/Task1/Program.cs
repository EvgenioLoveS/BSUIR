// See https://aka.ms/new-console-template for more information
using System;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            // Получаем экземпляр класса-контейнера
            ATCTariffContainer container = ATCTariffContainer.GetInstance();

            // Устанавливаем данные
            container.Address = "123 Main St.";
            container.NumberOfSubscribers = 1000;
            container.SubscriptionFee = 10.00;

            // Выводим информацию о контейнере
            Console.WriteLine("ATC Address: {0}", container.Address);
            Console.WriteLine("Number of Subscribers: {0}", container.NumberOfSubscribers);
            Console.WriteLine("Subscription Fee: {0:C}", container.SubscriptionFee);

            // Получаем экземпляр контейнеризируемого класса
            ATCTariff tariff = new ATCTariff();

            // Устанавливаем тарифы
            tariff.CallRate = 0.1;
            tariff.SmsRate = 0.05;
            tariff.InternetRate = 0.02;

            // Вычисляем сумму счета для клиента
            double bill = tariff.CalculateBill(50, 20, 10.5);
            Console.WriteLine("Bill for the client: {0:C}", bill);

            // Увеличиваем тариф и выводим общую абонентскую плату
            container.IncreaseTariff(1.00);
            Console.WriteLine("Total Subscription Fee: {0:C}", container.GetTotalSubscriptionFee());

            // Уменьшаем тариф и выводим общую абонентскую плату
            container.DecreaseTariff(0.50);
            Console.WriteLine("Total Subscription Fee: {0:C}", container.GetTotalSubscriptionFee());

            // Ожидание нажатия клавиши перед завершением программы
            Console.ReadKey();
        }
    }
}