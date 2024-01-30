// See https://aka.ms/new-console-template for more information


internal class Program
{
    private static void Main(string[] args)
    {
        int temp = 1;
        int resume;
        
        
        
        do
        {
            switch (temp)
            {
                case 1:
                    Console.WriteLine("Enter the x coordinate of the point:");
                    double x = Convert.ToDouble(Console.ReadLine());

                    Console.WriteLine("Enter the y coordinate of the point:");
                    double y = Convert.ToDouble(Console.ReadLine());

                    if (x >= -40 && x <= 40 && y >= -40 && y <= 40)
                    {
                        if ((x == 40 && (y >= -40 || y <= 40)) ||
                            (x == -40 && (y >= -40 || y <= 40)) ||
                            (y == -40 && (x >= -40 || x <= 40)) ||
                            (y == 40 && (x >= -40 || x <= 40)))
                        {
                            Console.WriteLine("On the border");
                        }
                        else
                        {
                            Console.WriteLine("YES");
                        }
                    }
                    else if (x >= -40 && x <= 40 && (y > 40 || y < -40))
                    {
                        Console.WriteLine("NO");
                    }
                    else if ((x > 40 || x < -40) && y >= -40 && y <= 40)
                    {
                        Console.WriteLine("NO");
                    }
                    else if ((x > 40 || x < -40) && (y > 40 || y < -40))
                    {
                        Console.WriteLine("NO");
                    }

                    Console.WriteLine("1 - YES");
                    Console.WriteLine("2 - NO");
                    resume = Convert.ToInt32(Console.ReadLine());
                    break;
                case 0:
                default:
                    return;
                    break;
            }
        } while (resume == 1);
    }
}