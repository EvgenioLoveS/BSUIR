#include <iostream>
#include <cmath>



int main()
{
    long double X, H, y;
    const long double PI = acos(-1);
    const int A = 0;
    const long double B = PI / 2;
    const int M = 20;
    X = 0;
    for (int i = 0; X < B; i++)
    {

        H = (B - A) / M;

        X = A + i * H;

        y = sin(X) - cos(X);

        std::cout << "y = " << y << std::endl;

    }
    return 0;
}