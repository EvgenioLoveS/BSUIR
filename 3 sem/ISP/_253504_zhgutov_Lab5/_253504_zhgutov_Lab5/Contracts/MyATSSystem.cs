using _253504_zhgutov_Lab5.Interfaces;
using _253504_zhgutov_Lab5.Collections;
using _253504_zhgutov_Lab5.Entities;


namespace _253504_zhgutov_Lab5.Contracts
{
    public class AtsSystem : IATSSystem
    {
        private ICustomCollection<Tariff> _tariffs;
        private ICustomCollection<Client> _clients;
        private ICustomCollection<Call> _calls;

        public AtsSystem()
        {
            _tariffs = new MyCustomCollection<Tariff>();
            _clients = new MyCustomCollection<Client>();
            _calls = new MyCustomCollection<Call>();
        }

        public void AddTariff(string city, decimal ratePerMinute)
        {
            _tariffs.Add(new Tariff { City = city, RatePerMinute = ratePerMinute });
        }

        public void AddCustomer(string lastName)
        {
            _clients.Add(new Client { LastName = lastName });
        }

        public void RegisterCall(string clientLastName, string city, int minutes)
        {
            Call call = new Call { CustomerLastName = clientLastName, City = city, Minutes = minutes };
            _calls.Add(call);
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
