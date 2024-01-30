namespace _253504_zhgutov_Lab5.Contracts
{
    public interface IATSSystem
    {
        void AddTariff(string city, decimal ratePerMinute);
        void AddCustomer(string lastName);
        void RegisterCall(string clientLastName, string city, int minutes);
        decimal CalculateClientCost(string clientLastName);
        decimal CalculateTotalCost();
        int GetCallCountToCity(string city);
    }
}