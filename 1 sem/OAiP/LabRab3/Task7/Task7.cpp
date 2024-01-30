#include <iostream>

const long double e = 2.7182818284590452353602874713527L;

// Синус
long double mySin(long double x)
{
    long double answ = x;
    long double fact = 6;
    long double curNum = 4;
    long double pow = -x * x * x;
    for (int i = 0; i < 30; i++)
    {
        answ += pow / fact;
        fact *= curNum * (curNum + 1);
        curNum += 2;
        pow *= -x * x;
    }
    return answ;
}

// Косинус
long double myCos(long double x)
{
    long double answ = 1;
    long double fact = 2;
    long double curNum = 3;
    long double pow = -x * x;
    for (int i = 0; i < 30; i++)
    {
        answ += pow / fact;
        fact *= curNum * (curNum + 1);
        curNum += 2;
        pow *= -x * x;
    }
    return answ;
}

// Натуральный логарифм
long double logE(long double x)
{
    long double answ = 0;
    while (x >= 1)
    {
        x /= e;
        answ++;
    }
    while (x < 0.1L)
    {
        x *= e;
        answ--;
    }
    long double tempX = x - 1;
    long double curNum = 1;
    for (int i = 0; i < 60; i++)
    {
        answ += tempX / curNum;
        tempX *= -(x - 1);
        curNum++;
    }
    return answ;
}

// Функция модуля
long double myAbs(long double x)
{
    return (x > 0 ? x : -x);
}

int main()
{
    long double a, b, c;
    long double X;
    std::cout << "Input X " << "\n";
    std::cin >> X;
    a = myCos(X);
    b = mySin(X);
    c = logE(myAbs(X));

    if (a < b && a < c)
    {
        std::cout << "Min = sin(x) " << a;
    }
    if (b < a && b < c)
    {
        std::cout << "Min = cos(x) " << b;
    }
    if (c < a && c < b)
    {
        std::cout << "Min = ln|x| " << c;
    }
    if (a == b && b == c)
    {
        std::cout << "Min = sin(x) " << a << "\n" << "Min = cos(x) " << b << "\n" << "Min = ln|x| " << c;
    }
    if (a == b)
    {
        if (a < c && b < c)
        {
            std::cout << "Min = sin(x) " << a << "\n" << "Min = cos(x) " << b;
        }
    }
    if (a == c)
    {
        if (a < b && c < b)
        {
            std::cout << "Min = sin(x) " << a << "\n" << "Min = ln|x| " << c;
        }
    }
    if (b == c)
    {
        if (b < c && c < a)
        {
            std::cout << "Min = cos(x) " << b << "\n" << "Min = ln|x| " << c;
        }
    }
    std::cout << "\n" << "sin(x): " << a << "\n";
    std::cout << "\n" << "cos(x): " << b << "\n";
    std::cout << "\n" << "ln|x|: " << c << "\n";
    return 0;
}