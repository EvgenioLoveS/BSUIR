namespace Task1;

// класс билета
public class Ticket
{
    public Tariff Tariff { get; set; } // тариф
    public Passenger Passenger { get; set; } // пассажир

    public decimal Cost // стоимость билета
    {
        get { return Tariff.Cost; }
    }

    public Ticket(Tariff tariff, Passenger passenger)
    {
        Tariff = tariff;
        Passenger = passenger;
    }
}