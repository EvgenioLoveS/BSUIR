namespace Task1;

public class Airport
{
    public List<Rate> lstProd = new List<Rate>();

    public void AddAbsDiscount(string name, int price, int discount)
    {
        AbsDiscount ip = new AbsDiscount(price, discount);
        lstProd.Add(new Rate(name, ip));
    }

    public void AddNoDiscount(string name, int price)
    {
        NoDiscount ip = new NoDiscount(price);
        lstProd.Add(new Rate(name, ip));
    }

    public Rate GetMaxPriceDirection()
    {
        return lstProd.OrderByDescending(x => x.GetPrice()).FirstOrDefault();
    }
    public int GetTotalPrice()
    {
        return lstProd.Sum(product => product.GetPrice());
    }
}