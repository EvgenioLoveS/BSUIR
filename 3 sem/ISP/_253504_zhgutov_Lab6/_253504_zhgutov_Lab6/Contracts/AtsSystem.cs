using _253504_zhgutov_Lab6.Interfaces;
using _253504_zhgutov_Lab6.Collections;
using _253504_zhgutov_Lab6.Entities;


namespace _253504_zhgutov_Lab6.Contracts
{
    internal class AtsSystem : IATSSystem
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

        void MakeCall(string caller, string destinationCity)
        { 
            CallEvent?.Invoke(this, new CallEventArgs(caller, destinationCity));
        }
        
        private ICustomCollection<Tariff> _tariffs;
        private ICustomCollection<Client> _clients;
        private ICustomCollection<Call> _calls;

        public AtsSystem()
        {
            // Инициализация коллекций тарифов, клиентов и звонков
            _tariffs = new MyCustomCollection<Tariff>();
            _clients = new MyCustomCollection<Client>();
            _calls = new MyCustomCollection<Call>();
        }

        public void AddTariff(string city, decimal ratePerMinute)
        {
            // Добавление тарифа в коллекцию тарифов
            _tariffs.Add(new Tariff { City = city, RatePerMinute = ratePerMinute });
            OnTariffChanged($"Tariff added for city: {city}");
        }

        public void AddCustomer(string lastName)
        {
            // Добавление клиента в коллекцию клиентов
            _clients.Add(new Client { LastName = lastName });
            OnClientListChanged($"Client added: {lastName}");
        }

        public void RegisterCall(string clientLastName, string city, int minutes)
        {
            // Регистрация звонка
            Call call = new Call { CustomerLastName = clientLastName, City = city, Minutes = minutes };
            _calls.Add(call);
            MakeCall(clientLastName, city);
        }

        public decimal CalculateClientCost(string clientLastName)
        {
            decimal totalCost = 0;

            // Перебор всех звонков для клиента с заданной фамилией
            for (int i = 0; i < _calls.Count; i++)
            {
                Call call = _calls[i];
                if (call.CustomerLastName == clientLastName)
                {
                    // Поиск тарифа для города звонка
                    for (int j = 0; j < _tariffs.Count; j++)
                    {
                        Tariff tariff = _tariffs[j];
                        if (tariff.City == call.City)
                        {
                            // Вычисление стоимости звонка и добавление к общей стоимости
                            totalCost += MyMath.Multiply(tariff.RatePerMinute, call.Minutes);
                            break;
                        }
                    }
                }
            }

            return totalCost;
        }

        public decimal CalculateTotalCost()
        {
            decimal totalCost = 0;

            // Перебор всех звонков и вычисление общей стоимости
            for (int i = 0; i < _calls.Count; i++)
            {
                Call call = _calls[i];
                for (int j = 0; j < _tariffs.Count; j++)
                {
                    Tariff tariff = _tariffs[j];
                    if (tariff.City == call.City)
                    {
                        totalCost += MyMath.Multiply(tariff.RatePerMinute, call.Minutes);
                        break;
                    }
                }
            }

            return totalCost;
        }

        public int GetCallCountToCity(string city)
        {
            int callCount = 0;

            // Перебор всех звонков и подсчет звонков в заданный город
            for (int i = 0; i < _calls.Count; i++)
            {
                Call call = _calls[i];
                if (call.City == city)
                {
                    callCount++;
                }
            }

            return callCount;
        }
    }
}