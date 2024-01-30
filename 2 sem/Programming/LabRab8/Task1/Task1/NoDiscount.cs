namespace Task1;

public class NoDiscount : IPrice
{
    private int price;

    public NoDiscount(int price)
    {
        this.price = price;
    }

    public int GetPrice()
    {
        return price;
    }
}