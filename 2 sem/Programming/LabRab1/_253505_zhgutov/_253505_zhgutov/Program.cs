// See https://aka.ms/new-console-template for more information


internal class Program
{
    private static void Main(string[] args)
    {
        Console.WriteLine("Enter the first number: ");
        double num1 = Convert.ToDouble(Console.ReadLine());
            
        Console.WriteLine("Enter the second number: ");
        double num2 = Convert.ToDouble(Console.ReadLine());

        double result = num1 / num2;
        Console.WriteLine("The result of division is: " + result);
    }
}