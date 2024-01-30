using _253504_zhgutov_Lab5.Contracts;

namespace _253504_zhgutov_Lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            var atsSystem = new AtsSystem();

            atsSystem.AddTariff("City1", 0.1m);
            atsSystem.AddTariff("City2", 0.2m);
            
            atsSystem.AddCustomer("Smith");
            atsSystem.AddCustomer("Johnson");
 
            atsSystem.RegisterCall("Smith", "City1", 10);
            atsSystem.RegisterCall("Smith", "City2", 15);
            atsSystem.RegisterCall("Johnson", "City1", 5);

            Console.WriteLine("Общая стоимость звонков для Smith: " + atsSystem.CalculateClientCost("Smith"));
            Console.WriteLine("Общая стоимость звонков для Johnson: " + atsSystem.CalculateClientCost("Johnson"));

            Console.WriteLine("Количество звонков в City1: " + atsSystem.GetCallCountToCity("City1"));
            Console.WriteLine("Количество звонков в City2: " + atsSystem.GetCallCountToCity("City2"));

            Console.WriteLine("Общая стоимость всех звонков: " + atsSystem.CalculateTotalCost());
        }
    }
}