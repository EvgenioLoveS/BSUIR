// See https://aka.ms/new-console-template for more information

using System;

namespace Task1;

class Program
{
    static void Main(string[] args)
    {
        // Создаем объекты класса Complex
        Complex c1 = new Complex(1, 2);
        Complex c2 = new Complex(3, 4);

        // Демонстрируем работу конструкторов и свойств
        Console.WriteLine($"Complex number 1: {c1}");
        Console.WriteLine($"Complex number 2: {c2}");

        // Демонстрируем работу индексирования
        Console.WriteLine($"Real part of c1: {c1[0]}");
        Console.WriteLine($"Imaginary part of c2: {c2[1]}");

        // Демонстрируем работу перегруженных операторов
        Complex sum = c1 + c2;
        Complex difference = c1 - c2;
        Complex product = c1 * c2;
        Complex quotient = c1 / c2;
        double modulus = (double)c1; //явное
        double realNumber = 3.14; 
        Complex complexNumber = realNumber; // неявное

        Console.WriteLine($"Sum: {sum}");
        Console.WriteLine($"Difference: {difference}");
        Console.WriteLine($"Product: {product}");
        Console.WriteLine($"Quotient: {quotient}");
        Console.WriteLine($"Modulus of c1: {modulus}");
        Console.WriteLine($"Complex number from double: {complexNumber}");

        // Демонстрируем работу перегруженных операторов инкремента и декремента
        c1++;
        c2--;
        Console.WriteLine($"After incrementing c1 and decrementing c2: {c1}, {c2}");

        // Демонстрируем работу перегруженных операторов отношений
        Console.WriteLine($"c1 == c2: {c1 == c2}");
        Console.WriteLine($"c1 != c2: {c1 != c2}");
        Console.WriteLine($"c1 > c2: {c1 > c2}");
        Console.WriteLine($"c1 < c2: {c1 < c2}");

        // Демонстрируем работу перегруженных операторов true и false
        Console.WriteLine($"Is c1 true? {c1}");
        Console.WriteLine($"Is c2 false? {!c2}");
        
    }
}
