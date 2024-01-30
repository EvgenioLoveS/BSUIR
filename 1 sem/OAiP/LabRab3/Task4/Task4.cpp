#include <iostream>


int main()
{
    int i, n, sum;
    i = 1;
    sum = 0;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n;
    while (i <= n)
    {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }
    std::cout << "Symma: " << sum;
    return 0;
}