namespace Task1;

    // класс кассы аэропорта
public class Airport
{
    private List<Tariff> tariffs = new List<Tariff>(); // список тарифов
    private List<Ticket> tickets = new List<Ticket>(); // список проданных билетов

    // метод для добавления тарифа
    public void AddTariff(Tariff tariff)
    {
        tariffs.Add(tariff);
    }

    // метод для регистрации покупки билета
    public void RegisterTicketPurchase(Ticket ticket)
    {
        tickets.Add(ticket);
    }

    // метод для расчета стоимости билетов, купленных пассажиром
    public decimal CalculatePassengerTicketsCost(Passenger passenger)
    {
        decimal cost = 0;
        foreach (Ticket ticket in tickets)
        {
            if (ticket.Passenger == passenger)
            {
                cost += ticket.Cost;
            }
        }

        return cost;
    }

    // метод для расчета стоимости всех проданных билетов
    public decimal CalculateAllTicketsCost()
    {
        decimal cost = 0;
        foreach (Ticket ticket in tickets)
        {
            cost += ticket.Cost;
        }

        return cost;
    }

    // метод для получения списка тарифов
    public List<Tariff> GetTariffs()
    {
        return tariffs;
    }
}