

namespace _253504_zhgutov_Lab7.Contracts
{
    public interface IAtsSystem
    {
        // Добавляет новый тариф для заданного города с указанной стоимостью за минуту.
        void AddTariff(string city, decimal ratePerMinute);

        // Добавляет нового клиента с указанной фамилией в систему.
        void AddCustomer(string lastName);

        // Регистрирует звонок клиента с указанной фамилией в заданный город на указанную продолжительность в минутах.
        void RegisterCall(string clientLastName, string city, int minutes);

        // Вычисляет общую стоимость всех звонков для клиента с указанной фамилией.
        decimal CalculateClientCost(string clientLastName);

        // Вычисляет общую стоимость всех звонков в системе.
        decimal CalculateTotalCost();

        // Возвращает имя клиента, который заплатил максимальную сумму. Если таких клиентов несколько, возвращает имя первого в списке.
        string GetClientWithMaxPayment();

        // Возвращает количество клиентов, заплативших сумму больше заданной.
        int GetClientsCountWithPaymentAbove(decimal amount);

        // Возвращает словарь, в котором ключи - это фамилии клиентов, а значения - общая стоимость всех звонков для каждого клиента, разбитая по тарифам.
        Dictionary<string, decimal> GetClientPaymentsByTariff();

        // Возвращает отсортированный список названий тарифов по их стоимости.
        List<string> GetSortedTariffNamesByRate();

        // Вычисляет общую стоимость всех звонков клиента с учетом тарифов.
        decimal CalculateClientCostByTariff(string clientLastName);
    }
}