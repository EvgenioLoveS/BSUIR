#include <iostream>
int main() {
    double x, y;
    std::cout << "Input x: " << "\n";
    std::cin >> x;
    std::cout << "Input y: " << "\n";
    std::cin >> y;
    std::cout << (x > y ? x : y) << "\n";
    return 0;
}