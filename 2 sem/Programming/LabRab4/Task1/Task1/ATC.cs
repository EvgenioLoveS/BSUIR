namespace Task1;
public class ATCTariff // контейнеризируемый класс
{
    private double callRate; // скорость вызова
    private double smsRate; // скорость смс
    private double internetRate; //скорость интернета

    public double CallRate
    {
        get { return callRate; }
        set { callRate = value; }
    }

    public double SmsRate
    {
        get { return smsRate; }
        set { smsRate = value; }
    }

    public double InternetRate
    {
        get { return internetRate; }
        set { internetRate = value; }
    }

    public double CalculateBill(int numberOfCalls, int numberOfSms, double internetUsage)
    {
        return (numberOfCalls * callRate) + (numberOfSms * smsRate) + (internetUsage * internetRate);
    }
}
