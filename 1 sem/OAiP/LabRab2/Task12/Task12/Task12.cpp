#include <iostream>

int main()
{
    long double a, b, c, x, y, S1, S2, S3, S4;
    std::cin >> a >> b >> c >> x >> y;
    S1 = a * c;
    S2 = c * b;
    S3 = a * b;
    S4 = x * y;
    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0)
    {
        std::cout << "Incorrect input";
        return 0;
    }
    if (S1 <= S4 || S2 <= S4 || S3 <= S4)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}
