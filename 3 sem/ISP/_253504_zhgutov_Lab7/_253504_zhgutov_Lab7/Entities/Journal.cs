using _253504_zhgutov_Lab7.Contracts;

namespace _253504_zhgutov_Lab7.Entities
{
    internal class Journal
    {
        private List<string> eventsLog = new List<string>();

        public void RegisterTariffChange(object sender, AtsSystem.TariffChangedEventArgs e)
        {
            string logEntry = $"[Tariff Changed] {e.Description}";
            eventsLog.Add(logEntry);
        }

        public void RegisterClientListChange(object sender, AtsSystem.ClientListChangedEventArgs e)
        {
            string logEntry = $"[Client List Changed] {e.Description}";
            eventsLog.Add(logEntry);
        }

        public void RegisterCall(object sender, AtsSystem.CallEventArgs e)
        {
            string logEntry = $"[New Call From:] {e.Caller} {e.DestinationCity}";
            eventsLog.Add(logEntry);
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