#include<iostream>
#include<cmath>

int main()
{
    long long a1, an, d, result, a = 1, n;
    std::cout << "Enter a1, an, d:\n";
    std::cin >> a1 >> an >> d;

    if ((an - a1) % d == 0) {

        result = a1;
        n = (an - a1 + d) / d;

        for (int i = 1; i < abs(n); i++) {
            a *= (-2);
            a1 += d;
            result += a * a1;
        }
        std::cout << result << '\n';
    }

    else {
        std::cout << "error\n";
    }

    return 0;
}