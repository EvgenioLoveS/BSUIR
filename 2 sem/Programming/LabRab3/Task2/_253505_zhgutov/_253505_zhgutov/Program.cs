// See https://aka.ms/new-console-template for more information

using _253505_zhgutov.Services;
public class Program
{
    public static double IncorrectInput(string text)
    {
        double temp = 0;
        bool flag = true;

        while (flag)
        {
            Console.WriteLine(text);
            if (!double.TryParse(Console.ReadLine(), out temp))
            {
                Console.WriteLine("Вы ввели некорректные данные,попробуйте снова!!!");
            }
            else
            {
                flag = false;
            }
        }
        return temp;
    }

    static void Main(string[] args)
    {
        int resume;
        do
        {
            double b, z;
            b = IncorrectInput("Введите b:");
            z = IncorrectInput("Введите z:");
            Console.WriteLine(MyClass.Answer(b, z));
            Console.WriteLine("1 - YES");
            Console.WriteLine("2 - NO");
            resume = Convert.ToInt32(Console.ReadLine());
        } while (resume == 1);
    }
}