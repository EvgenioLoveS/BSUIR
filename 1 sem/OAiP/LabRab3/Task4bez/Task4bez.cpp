#include <iostream>


int main()
{
    int a1, n, d, S, N;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n;
    a1 = 2;
    d = 2;
    N = n / 2;
    S = N * (2 * a1 + (N - 1) * d) / 2;
    std::cout << "Symma 4etnix: " << S;
    return 0;
}