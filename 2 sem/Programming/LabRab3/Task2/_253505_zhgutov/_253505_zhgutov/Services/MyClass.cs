namespace _253505_zhgutov.Services;

public class MyClass
{
    public static double Answer(double b, double z)
    {
        double x = 0;
        if (z < 1)
        {
            x = (double)(z / b);
            //return x;
        }

        if (z >= 1)
        {
            x = (double)Math.Sqrt(Math.Pow(z * b, 3));
            //return x;
        }

        double y = (double)(-Math.PI) + (Math.Pow(Math.Cos(Math.Pow(x, 3)), 2)) + (Math.Pow(Math.Sin(Math.Pow(x, 2)), 3));
        return y;
    }
}