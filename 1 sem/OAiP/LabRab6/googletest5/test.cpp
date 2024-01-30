#include "pch.h"
#include <iostream>
#include <cmath>

bool check(std::string s1, std::string s2, unsigned long long delta) {
    for (int i = 0; i < delta; i++) {
        if (s1[i] != s2[s2.size() - delta + i]) {
            return false;
        }
    }
    return true;
}

long long binarypow(long long number, long long stepenb, long long m)
{
    long long ans = 1;
    while (stepenb) {
        if (stepenb & 1) {
            ans = (ans * number) % m;
            stepenb--;
        }
        else {
            stepenb >>= 1;
            number = (number * number) % m;
        }
    }
    return ans % m;
}

unsigned long long stringsCount(unsigned long long L, unsigned long long m, std::string s1, std::string s2) {
    long long  delta = L - s1.size() - s2.size();
    unsigned long long ans = 0;
    if (delta >= 0) {
        ans = binarypow(26, delta, m);
        if (s1 != s2) {
            ans = (ans * 2) % m;
        }
    }
    else {
        ans += check(s1, s2, abs(delta)) ? 1 : 0;
        ans += check(s2, s1, abs(delta)) ? 1 : 0;
    }
    return ans;
}

int task5() {
    unsigned long long t, L, m;
    std::string s1, s2;

    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> L >> m >> s1 >> s2;
        std::cout << stringsCount(L, m, s1, s2) << std::endl;
    }

    return 0;
}


TEST(Test3) {
    // 1 3 1000 555 555
    EXPECT_EQ(task5(), 0);
}