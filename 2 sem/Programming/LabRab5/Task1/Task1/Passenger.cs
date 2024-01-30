namespace Task1;

// класс пассажира
public class Passenger
{
    public string PassportData { get; set; } // паспортные данные

    public Passenger(string passportData)
    {
        PassportData = passportData;
    }
}