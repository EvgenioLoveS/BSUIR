namespace Task1;

public class Complex
{
    private double real;
    private double imaginary;

    public Complex(double real, double imaginary)
    {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double Real
    {
        get { return real; }
        set { real = value; }
    }

    public double Imaginary
    {
        get { return imaginary; }
        set { imaginary = value; }
    }

    public override string ToString()
    {
        return $"{real} + {imaginary}i";
    }

    public double Modulus()
    {
        return Math.Sqrt(real * real + imaginary * imaginary);
    }

    public static Complex operator +(Complex a, Complex b)
    {
        return new Complex(a.real + b.real, a.imaginary + b.imaginary);
    }

    public static Complex operator -(Complex a, Complex b)
    {
        return new Complex(a.real - b.real, a.imaginary - b.imaginary);
    }

    public static Complex operator *(Complex a, Complex b)
    {
        return new Complex(a.real * b.real - a.imaginary * b.imaginary, a.real * b.imaginary + a.imaginary * b.real);
    }

    public static Complex operator /(Complex a, Complex b)
    {
        double modulusSquared = b.real * b.real + b.imaginary * b.imaginary;
        return new Complex((a.real * b.real + a.imaginary * b.imaginary) / modulusSquared,
                           (a.imaginary * b.real - a.real * b.imaginary) / modulusSquared);
    }

    public static Complex operator +(Complex a, double b)
    {
        return new Complex(a.real + b, a.imaginary);
    }

    public static Complex operator +(double b, Complex a)
    {
        return new Complex(a.real + b, a.imaginary);
    }

    public static Complex operator -(Complex a, double b)
    {
        return new Complex(a.real - b, a.imaginary);
    }

    public static Complex operator -(double b, Complex a)
    {
        return new Complex(b - a.real, -a.imaginary);
    }

    public static Complex operator *(Complex a, double b)
    {
        return new Complex(a.real * b, a.imaginary * b);
    }

    public static Complex operator *(double b, Complex a)
    {
        return new Complex(a.real * b, a.imaginary * b);
    }

    public static Complex operator /(Complex a, double b)
    {
        if (b == 0)
        {
            throw new DivideByZeroException("Divide by zero error: cannot divide by zero.");
        }
        return new Complex(a.real / b, a.imaginary / b);
    }
    
    public static Complex operator /(double a, Complex b)
    {
        double modulusSquared = b.real * b.real + b.imaginary * b.imaginary;
        if (modulusSquared == 0)
        {
            throw new DivideByZeroException("Divide by zero error: cannot divide by zero.");
        }
        return new Complex((a * b.real) / modulusSquared, (-a * b.imaginary) / modulusSquared);
    }
    
    public static Complex operator ++(Complex a)
    {
        return new Complex(a.Real + 1, a.Imaginary + 1);
    }

    public static Complex operator --(Complex a)
    {
        return new Complex(a.Real - 1, a.Imaginary - 1);
    }
    
    public static bool operator !(Complex a)
    {
        return a.real != 0 || a.imaginary != 0;
    }

    
    public static bool operator ==(Complex a, Complex b)
    {
        if (a is null || b is null)
        {
            return false;
        }
        return a.real == b.real && a.imaginary == b.imaginary;
    }

    public static bool operator !=(Complex a, Complex b)
    {
        return a.Modulus() != b.Modulus();
    }

    public static bool operator <(Complex a, Complex b)
    {
        return a.Modulus() < b.Modulus();
    }

    public static bool operator >(Complex a, Complex b)
    {
        return a.Modulus() > b.Modulus();
    }

    public static bool operator true(Complex a)
    {
        return a.real != 0 || a.imaginary != 0;
    }

    public static bool operator false(Complex a)
    {
        return a.real == 0 && a.imaginary == 0;
    }
    //позволяет явно преобразовывать объекты типа Complex в тип double.
    public static explicit operator double(Complex a)
    {
        return a.Modulus();
    }
    //позволяет неявно преобразовывать объекты типа double в тип Complex. 
    public static implicit operator Complex(double a)
    {
        return new Complex(a, 0);
    }
    
    public double this[int index]
    {
        get
        {
            if (index == 0)
            {
                return real;
            }
            else if (index == 1)
            {
                return imaginary;
            }
            else
            {
                throw new IndexOutOfRangeException();
            }
        }
        set
        {
            if (index == 0)
            {
                real = value;
            }
            else if (index == 1)
            {
                imaginary = value;
            }
            else
            {
                throw new IndexOutOfRangeException();
            }
        }
    }

}