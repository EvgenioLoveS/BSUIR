#include <iostream>

int main()
{
    long int gr;
    std::cin >> gr;
    if (gr < 0) {
        std::cout << "ERROR" << "\n";
    }
    else if (gr % 10 > 4 && gr % 10 < 10 || gr % 10 == 0 || gr % 100 > 10 && gr % 100 < 15) {
        std::cout << "mi nashli " << gr << " gribov v lesy" << "\n";
    }
    else if (gr == 1 || gr % 10 == 1) {
        std::cout << "mi nashli " << gr << " grib v lesy" << "\n";
    }
    else if (gr % 10 >= 2 && gr % 10 <= 4 || gr >= 2 && gr <= 4) {
        std::cout << "mi nashli " << gr << " griba v lesy" << "\n";
    }
    return 0;
}