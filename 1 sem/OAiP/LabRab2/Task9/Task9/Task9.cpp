#include <iostream>
#include <cmath>

int main()
{
    double x, z, a, c, y, f;
    int N;
    std::cout << "Enter N: " << "\n";
    std::cin >> N;
    std::cout << "Enter a: " << "\n";
    std::cin >> a;
    std::cout << "Enter c: " << "\n";
    std::cin >> c;
    std::cout << "Enter z: " << "\n";
    std::cin >> z;
    if (z <= 1) {
        x = z * z + 1;
    }
    if (z > 1) {
        x = 1 / sqrt(z - 1);
    }
    switch (N)
    {
    case 1:
        f = 2 * x;
        y = a * sin(f * f - 1) * sin(f * f - 1) * sin(f * f - 1) + c * log(fabs(x)) + exp(x);
        break;
    case 2:
        f = pow(x, 3);
        y = a * sin(f * f - 1) * sin(f * f - 1) * sin(f * f - 1) + c * log(fabs(x)) + exp(x);
        break;
    case 3:
        f = x / 3;
        y = a * sin(f * f - 1) * sin(f * f - 1) * sin(f * f - 1) + c * log(fabs(x)) + exp(x);
        break;
    }
    std::cout << "y: " << y << "\n";
    return 0;
}