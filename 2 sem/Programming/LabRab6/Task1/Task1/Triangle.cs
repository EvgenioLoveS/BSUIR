namespace Task1;

public sealed class Triangle : GeometricFigure
{
    private double baseLength;
    private double height;

    public Triangle(double baseLength, double height)
    {
        this.baseLength = baseLength;
        this.height = height;
    }

    public override double CalculateArea()
    {
        area = 0.5 * baseLength * height;
        return area;
    }
}