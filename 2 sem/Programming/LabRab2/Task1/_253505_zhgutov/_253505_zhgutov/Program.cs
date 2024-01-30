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
                    Console.WriteLine("Enter a three-digit number: ");
                    int number = Convert.ToInt32(Console.ReadLine());

                    int firstDigit = number / 100;
                    int secondDigit = (number / 10) % 10;

                    if (firstDigit > secondDigit)
                    {
                        Console.WriteLine("The first  digit"  firstDigit  "is greater than the second digit.");
                    }
                    else if (firstDigit < secondDigit)
                    {
                        Console.WriteLine("The second digit is greater than the first digit.");
                    }
                    else
                    {
                        Console.WriteLine("The first digit and the second digit are equal.");
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