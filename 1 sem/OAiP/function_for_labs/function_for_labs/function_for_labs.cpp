#include <iostream>
using namespace std;

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

// функция степени
long int intpow(long int x, unsigned int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else if (n % 2 == 0)
        return intpow(x * x, n / 2);
    else
        return intpow(x * x, n / 2) * x;
}

// Функция корня
long double mySqrt(long double a)
{
    long double x = 0.5;
    for (int i = 0; i < 50; i++)
    {
        x = x / 2 + a / (2 * x);
    }
    return x;
}

// функция факториала
long int factorial(long int N)
{
    long int  N2, fact = 1;
    if (N == 0 || N == 1)
    {
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        N2 = (N - i);
        fact = N2 * fact;
    }
    return fact;
}

// Функция модуля
long double myAbs(long double x)
{
    return (x > 0 ? x : -x);
}
//проверка на ввод 1-4 лабы
long long int vvod()
{
    const int MIN = 1;
    bool isIncorrect;
    long long int n;
    do
    {
        isIncorrect = false;
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            isIncorrect = true;
            std::cout << "Неверный тип данных" << '\n';
        }
        if (!isIncorrect && std::cin.get() != '\n')
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;

            std::cout << "Ошибка" << '\n';
            isIncorrect = true;
        }
        if (!isIncorrect && n < MIN)
        {
            isIncorrect = true;
            std::cout << "Неверный диапозон" << '\n';
        }
    } while (isIncorrect);
    return n;
}
// проверка на ввод размера матрицы
long long proverkarazmer()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < 1 || x > INT_MAX || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}
// проверка на ввод элементов матрицы тип: int 
long long proverkaelementovint()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < INT_MIN || x > INT_MAX || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}
// проверка на ввод элементов матрицы тип: double
double proverkaelementovdouble()
{
    double x;
    while (scanf_s("%lf", &x) != 1.0 || x < INT_MIN || x > INT_MAX || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}
//проверка на меню
long long proverkamenu()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < 1 || x > 3 || getchar() != '\n')
    {
        printf("Error\n");
        printf("Ошибка ввода, повторите ввод!!!\n");
        printf("Выберите вариант:\n");
        rewind(stdin);
    }
    return x;
}
//проверка на продолжение
long long proverkacontinue()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < 1 || x > 2 || getchar() != '\n')
    {
        printf("Ошибка ввода, повторите ввод!!!\n");
        printf("Хотите ли вы продолжить?\n");
        rewind(stdin);
    }
    return x;
}
// сортировка QuickSort
void QuickSort(int mass[], int start, int end) {
    int s = start, e = end;
    int middle = mass[(s + e) / 2];
    while (s <= e)
    {
        while (mass[s] < middle) s++;
        while (mass[e] > middle) e--;
        if (s <= e) {
            int temp = mass[s];
            mass[s] = mass[e];
            mass[e] = temp;
            s++;
            e--;
        }
    }
    if (start < e) QuickSort(mass, start, e);
    if (end > s) QuickSort(mass, s, end);
}
// бинарное  возведение в степень
long long binpow(long long a, long long n)
{
    long long res = 1;

    while (n > 0)
    {
        if (n & 1) //b % 2
        {
            res = res * a;
        }

        a = a * a;

        n >>= 1; //b / 2
    }

    return res;
}