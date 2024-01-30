#include <iostream>
int main()
{
    double x, y;
    std::cout << "Enter x: " << "\n";
    std::cin >> x;
    std::cout << "Enter y: " << "\n";
    std::cin >> y;
    bool a = x > y;
    std::cout << (a ? x : y) << "\n";
    return 0;
}