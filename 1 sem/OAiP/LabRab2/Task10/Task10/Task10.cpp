#include <iostream>
#include <cmath>

int main()
{
    long double x1, y1, r, x2, y2, R, L;
    std::cout << "Enter x1: " << "\n";
    std::cin >> x1;
    std::cout << "Enter y1: " << "\n";
    std::cin >> y1;
    std::cout << "Enter r: " << "\n";
    std::cin >> r;
    if (r <= 0)
    {
        std::cout << "Oshibka vvoda " << "\n";
        return 0;
    }
    std::cout << "Enter x2: " << "\n";
    std::cin >> x2;
    std::cout << "Enter y2: " << "\n";
    std::cin >> y2;
    std::cout << "Enter R: " << "\n";
    std::cin >> R;
    if (R <= 0)
    {
        std::cout << "Oshibka vvoda " << "\n";
        return 0;
    }
    L = sqrt(pow(x1 - x2, 2) + pow(y1 - y1, 2));
    if (R >= (L + r))
    {
        std::cout << "Da" << "\n";
    }
    else if (r >= (L + R))
    {
        std::cout << "Da,no spravedlivo obratnoe dlya 2 figyr" << "\n";
    }
    else if (L <= (R + r))
    {
        std::cout << "Peresikaytsa " << "\n";
    }
    else {
        std::cout << "Ni odno yslovie ne vipolneno" << "\n";
    }
    return 0;
}