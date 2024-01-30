#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int i;
    long double  a, b, N = 0;
    i = 1;
    while (i <= 30)
    {
        if (i % 2 == 0)
        {
            a = i / 2;
            b = pow(i, 3);
        }
        else
        {
            a = i;
            b = pow(i, 2);
        }
        N += pow(a - b, 2);
        i++;
    }
    std::cout << std::setprecision(10) << N;
    return 0;
}