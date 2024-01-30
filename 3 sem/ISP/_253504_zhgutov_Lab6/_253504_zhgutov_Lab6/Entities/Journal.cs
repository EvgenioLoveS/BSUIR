using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _253504_zhgutov_Lab6.Collections;
using _253504_zhgutov_Lab6.Contracts;

namespace _253504_zhgutov_Lab6.Entities
{
    internal class Journal
    {
        private MyCustomCollection<string> eventsLog = new MyCustomCollection<string>();

        public void RegisterTariffChange(object sender, AtsSystem.TariffChangedEventArgs e)
        {
            string logEntry = $"[Tariff Changed] {e.Description}";
            eventsLog.Add(logEntry);
            //Console.WriteLine(logEntry);
        }

        public void RegisterClientListChange(object sender,AtsSystem.ClientListChangedEventArgs e)
        {
            string logEntry = $"[Client List Changed] {e.Description}";
            eventsLog.Add(logEntry);
            //Console.WriteLine(logEntry);
        }

        public void RegisterCall(object sender, AtsSystem.CallEventArgs e)
        {
            string logEntry = $"[New Call From:] {e.Caller} {e.DestinationCity}";
            eventsLog.Add(logEntry);
            //Console.WriteLine(logEntry);
        }

        public void PrintEventLog()
        {
            Console.WriteLine("Event Log:");
            foreach (string logEntry in eventsLog)
            {
                Console.WriteLine(logEntry);
            }
        }
    }
}