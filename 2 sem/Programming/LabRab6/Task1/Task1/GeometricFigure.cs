namespace Task1;

public abstract class GeometricFigure
{
    protected double area;

    public abstract double CalculateArea();

    public void PrintArea()
    {
        Console.WriteLine($"The area of this {GetType().Name} is {area}");
    }
}