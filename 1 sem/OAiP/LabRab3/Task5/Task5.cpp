#include <iostream>
#include <cmath>


const long double PI = acos(-1);

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

int main()
{
    long double S, Y, x, S2;
    int num_n, num_x;
    int g;
    std::cout << "Enter koli4estvo raydov: " << "\n";
    std::cin >> num_n;
    std::cout << "Enter koli4estvo 4icel, ot kotorix nyzno pos4itatb funkciy: " << "\n";
    std::cin >> num_x;

    for (int i = 1; i <= num_x; i++)
    {
        g = 0;
        S = 0;
        Y = 0;
        S2 = 0;
        std::cout << "Enter x [0.1;1] " << "\n";
        std::cin >> x;



        while (g <= num_n)
        {
            S2 = (powl(-1, g)) * (2 * powl(g, 2) + 1) * (powl(x, 2 * g)) / factorial(2 * g);
            S += S2;
            g++;
        }

        Y = ((1 - (pow(x, 2) / 2)) * cos(x)) - ((x / 2) * sin(x));

        std::cout << "S(x) = " << S << "\n";
        std::cout << "Y(x) = " << Y << "\n";
    }
}