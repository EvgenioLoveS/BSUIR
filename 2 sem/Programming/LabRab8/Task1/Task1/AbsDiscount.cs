namespace Task1;

public class AbsDiscount : IPrice
{
    private int discount;
    private int price;

    public AbsDiscount(int price, int discount)
    {
        this.price = price;
        this.discount = discount;
    }

    public int GetPrice()
    {
        return (price * (100 - discount)) / 100;
    }
}