
public class MyClass
{ 
    public static int Min(int a, int b)
    {
        return a < b ? a : b;
    }
    public static int Calculate(int x, int y)
    {
        int z = Min(x, 2 * y + x) - Min(7 * x + 2 * y, y);
        return z;
    }
}