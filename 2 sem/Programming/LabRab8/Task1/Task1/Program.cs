// See https://aka.ms/new-console-template for more information


namespace Task1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Airport airport = new Airport();
            airport.AddAbsDiscount("Moscow-New York", 3200, 20);
            airport.AddNoDiscount("London-Paris", 1200);
            Console.WriteLine(airport.GetMaxPriceDirection());
            //Вызов метода интерфейса через интерфейсную ссылку
            AbsDiscount absD = new AbsDiscount(1000, 50);

            IPrice ip;
            ip = absD;

            Console.WriteLine(ip.GetPrice());
            
            Rate maxPriceDirection = airport.GetMaxPriceDirection();
            Console.WriteLine($"Направление с максимальной стоимостью: {maxPriceDirection.Direction}, стоимость: {maxPriceDirection.GetPrice()}");
            Console.WriteLine($"Всего потрачено : {airport.GetTotalPrice()}");

        }
    }
}