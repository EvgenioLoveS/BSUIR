// See https://aka.ms/new-console-template for more information
using System;
namespace Task1;

internal class program
{
    static void Main(string[] args)
    {
        Rectangle rect = new Rectangle(4, 5);
        double rectArea = rect.CalculateArea();
        rect.PrintArea();  // Output: The area of this Rectangle is 20

        Circle circle = new Circle(3);
        double circleArea = circle.CalculateArea();
        circle.PrintArea();  // Output: The area of this Circle is 28.2743338823081

        Triangle tri = new Triangle(6, 4);
        double triArea = tri.CalculateArea();
        tri.PrintArea();  // Output: The area of this Triangle is 12
    }
}
