namespace Task1;

public class Rate
{
    public string Direction { get; set; }
    public IPrice Price { get; set; }

    public Rate(string name, IPrice ip)
    {
        Direction = name;
        Price = ip;
    }

    public int GetPrice()
    {
        return Price.GetPrice();
    }
}