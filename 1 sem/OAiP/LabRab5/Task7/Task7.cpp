#include <iostream>


long int myintpow(long int x, unsigned int n)
{
    if (n == 0) {
        return 1;
    }

    else if (n == 1) {
        return x;
    }

    else if (n % 2 == 0) {
        return myintpow(x * x, n / 2);
    }

    else {
        return myintpow(x * x, n / 2) * x;
    }
}

unsigned long long F(unsigned long long chis, unsigned long long vkot, unsigned long long n) {

    if (vkot == 0) {
        return 1;
    }

    if (vkot % 2 != 0) {
        return (chis * F((chis * chis) % n, vkot / 2, n)) % n;
    }

    return F((chis * chis) % n, vkot / 2, n);
}

int main() {
    unsigned long long i = 1;
    unsigned long long k;
    unsigned long long n;
    unsigned long long t;
    unsigned long long m;
    do {
        std::cin >> k >> n >> t;
        m = myintpow(10, t);
        if (k == 0 && n == 0 && t == 0) {
            return 0;
        }
        std::cout << "Case #" << i << ": " << F(k % m, n, m) << "\n";
        i++;
    } while (k != 0 && n != 0 && t != 0);
    return 0;
}