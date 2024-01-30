#include "pch.h"
#include <iostream>

int task5() {
    long long t, count, n;

    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        if (n == 1) {
            return 0;
        }
        else {
            count = ((n + 1) / 10);
            return count;
        }
    }
}

TEST(Test1) {
    //1 1000000000 // 9 нулей
    EXPECT_EQ(task5(), 100000000);
}

TEST(Test2) {
    //1 100000000 // 8 нулей
    EXPECT_EQ(task5(), 10000000);
}