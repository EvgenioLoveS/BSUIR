using System;
using System.Collections.Generic;
using System.Linq;
using _253504_zhgutov_Lab7.Entities;

namespace _253504_zhgutov_Lab7.Contracts
{
    internal class AtsSystem : IAtsSystem
    {
        public delegate void TariffChangedEventHandler(object sender, TariffChangedEventArgs e);
        public delegate void ClientListChangedEventHandler(object sender, ClientListChangedEventArgs e);
        public delegate void CallEventHandler(object sender, CallEventArgs e);

        public event TariffChangedEventHandler TariffChanged;
        public event ClientListChangedEventHandler ClientListChanged;
        public event CallEventHandler CallEvent;    
        
        public class TariffChangedEventArgs : EventArgs
        {
            public string Description { get; set; }

            public TariffChangedEventArgs(string description)
            {
                Description = description;
            }
        }

        public class ClientListChangedEventArgs : EventArgs
        {
            public string Description { get; set; }

            public ClientListChangedEventArgs(string description)
            {
                Description = description;
            }
        }
        public class CallEventArgs : EventArgs
        {
            public string Caller { get; set; }
            public string DestinationCity { get; set; }

            public CallEventArgs(string caller, string destinationCity)
            {
                Caller = caller;
                DestinationCity = destinationCity;
            }
        }
        protected virtual void OnTariffChanged(string description)
        {
            TariffChanged?.Invoke(this, new TariffChangedEventArgs(description));
        }

        protected virtual void OnClientListChanged(string description)
        {
            ClientListChanged?.Invoke(this, new ClientListChangedEventArgs(description));
        }

        protected virtual void MakeCall(string caller, string destinationCity)
        {
            CallEvent?.Invoke(this, new CallEventArgs(caller, destinationCity));
        }
        
        private Dictionary<string, Tariff> _tariffs;
        private List<Client> _clients;
        private List<Call> _calls;

        public AtsSystem()
        {
            _tariffs = new Dictionary<string, Tariff>();
            _clients = new List<Client>();
            _calls = new List<Call>();
        }

        public void AddTariff(string city, decimal ratePerMinute)
        {
            _tariffs[city] = new Tariff { City = city, RatePerMinute = ratePerMinute };
            OnTariffChanged($"Tariff added for city: {city}");
        }

        public void AddCustomer(string lastName)
        {
            _clients.Add(new Client { LastName = lastName });
            OnClientListChanged($"Client added: {lastName}");
        }

        public void RegisterCall(string clientLastName, string city, int minutes)
        {
            Call call = new Call { CustomerLastName = clientLastName, City = city, Minutes = minutes };
            _calls.Add(call);
            MakeCall(clientLastName, city);
        }

        public decimal CalculateClientCost(string clientLastName)
        {
            return _calls
                .Where(call => call.CustomerLastName == clientLastName)
                .Sum(call => CalculateCallCost(call));
        }

        public decimal CalculateTotalCost()
        {
            return _calls.Sum(call => CalculateCallCost(call));
        }

        public string GetClientWithMaxPayment()
        {
            var clientPayments = _clients.ToDictionary(client => client.LastName,
                                                       client => CalculateClientCost(client.LastName));
            return clientPayments.OrderByDescending(pair => pair.Value).FirstOrDefault().Key;
        }

        public int GetClientsCountWithPaymentAbove(decimal amount)
        {
            //return _clients.Count(client => CalculateClientCost(client.LastName) > amount);
            return _clients
                .Where(client => CalculateClientCost(client.LastName) > amount)
                .Aggregate(0, (count, client) => count + 1);
        }

        public Dictionary<string, decimal> GetClientPaymentsByTariff()
        {
            return _calls.GroupBy(call => call.CustomerLastName)
                         .ToDictionary(group => group.Key,
                                       group => group.Sum(call => CalculateCallCost(call)));
        }

        public List<string> GetSortedTariffNamesByRate()
        {
            return _tariffs.OrderBy(kv => kv.Value.RatePerMinute)
                            .Select(kv => kv.Key)
                            .ToList();
        }

        public decimal CalculateClientCostByTariff(string clientLastName)
        {
            return _calls
                .Where(call => call.CustomerLastName == clientLastName)
                .Sum(call => CalculateCallCostByTariff(call));
        }

        private decimal CalculateCallCost(Call call)
        {
            if (_tariffs.TryGetValue(call.City, out Tariff tariff))
            {
                return MyMath.Multiply(tariff.RatePerMinute, call.Minutes);
            }
            return 0;
        }

        private decimal CalculateCallCostByTariff(Call call)
        {
            if (_tariffs.TryGetValue(call.City, out Tariff tariff))
            {
                return MyMath.Multiply(tariff.RatePerMinute, call.Minutes);
            }
            return 0;
        }
    }
}