namespace Task1;

public class Circle : GeometricFigure
{
    private double radius;

    public Circle(double radius)
    {
        this.radius = radius;
    }

    public override double CalculateArea()
    {
        area = Math.PI * Math.Pow(radius, 2);
        return area;
    }
}