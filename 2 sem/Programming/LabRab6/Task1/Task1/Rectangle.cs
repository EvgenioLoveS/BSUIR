namespace Task1;

public class Rectangle : GeometricFigure
{
    private double length;
    private double width;

    public Rectangle(double length, double width)
    {
        this.length = length;
        this.width = width;
    }

    public override double CalculateArea()
    {
        area = length * width;
        return area;
    }
}