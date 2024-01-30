#include "pch.h"
#include <iostream>
#include <algorithm>

long long fact(long long n) {
    if (n == 0 || n == 1) return 1;
    else return n * fact(n - 1);
}

int task6() {
    std::string str, str_copy;
    std::cin >> str;
    str_copy = str;
    long long ans = fact(str.size());

    std::sort(str.begin(), str.end());
    auto border = std::unique(str.begin(), str.end());
    for (auto iter = str.begin(); iter != border; iter++) {
        long long temp = count(str_copy.begin(), str_copy.end(), *iter);
        if (temp > 1) {
            ans /= fact(temp);
        }
    }
    return ans;
}

TEST(Test1) {
    // zzzzzzzzzzzzzz
    ASSERT_EQ(task6(), 1);
}
