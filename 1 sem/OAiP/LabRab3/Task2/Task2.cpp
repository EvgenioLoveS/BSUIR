#include <iostream>
#include <cmath>

int main()
{
    int n = 1;
    double d, e, sum = 0;
    e = pow(10, -3);
    do {
        d = (1 / pow(2, n)) + (1 / pow(3, n));
        std::cout << d << std::endl;
        sum += d;
        n++;
    } while (d >= e);
    std::cout << sum;
    return 0;
}
