namespace Task1;

public enum ServiceClass
{
    Economy,
    Business
}
// класс тарифа
public class Tariff
{
    public string Direction { get; set; } // направление
    public decimal Cost { get; set; } // стоимость
    public ServiceClass ServiceClass { get; set; } // класс обслуживания
}