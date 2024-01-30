#include <iostream>

int main() {
    long long t, count, n;

    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        if (n == 1) {
            std::cout << 0 << "\n";
        }
        /*else if (n < 10) {
            std::cout << 1 << "\n";
        }*/
        else {
            count = ((n + 1) / 10);
            std::cout << count << "\n";
        }
    }
    return 0;
}