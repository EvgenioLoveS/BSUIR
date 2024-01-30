using _253504_zhgutov_Lab6.Contracts;
using _253504_zhgutov_Lab6.Entities;

namespace _253504_zhgutov_Lab5
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
            
            atsSystem.AddTariff("New York", 0.1m);
            atsSystem.AddTariff("Los Angeles", 0.08m);
            atsSystem.AddCustomer("Smith");
            atsSystem.AddCustomer("Johnson");
            
            atsSystem.RegisterCall("Smith", "New York", 10);
            atsSystem.RegisterCall("Johnson", "Los Angeles", 15);

            journal.PrintEventLog();
        }
    }
}