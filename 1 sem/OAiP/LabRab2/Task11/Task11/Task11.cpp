#include <iostream>
#include <cmath>

int main()
{   
    # define M_PI           3.14159265358979323846
    long double R, P, Q, r;
    std::cout << "Input radius shara: " << "\n";
    std::cin >> R;
    std::cout << "Input storona romba: " << "\n";
    std::cin >> P;
    std::cout << "Input ygol ostriy v gradysax: " << "\n";
    std::cin >> Q;

    r = (P * sin(Q * M_PI / 180) / 2); // радиус вписанной окружности в ромб
    std::cout << "r:" << r;
    if (R <= 0 || P <= 0 || Q <= 0) {
        std::cout << " Incorrect input " << "\n";
    }
    else if (R <= r) {
        std::cout << " YES " << "\n";
    }
    else {
        std::cout << " NO " << "\n";
    }
    return 0;
}