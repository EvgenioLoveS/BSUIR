#include <iostream>
#include <cmath>

int main()
{
    int x, count, i, sum, digit, num; // x - до какого числа , count - количество цифр
    std::cout << "Input value: " << std::endl;
    std::cin >> x;
    for (i = 1; i < x; i++)
    {
        count = 0;
        num = i;
        while (num > 0)
        {
            count++;
            num = num / 10;
        }
        sum = 0;
        num = i;
        while (num > 0) {
            digit = num % 10;
            sum = sum + pow(digit, count);
            num /= 10;
        }
        if (sum == i) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}