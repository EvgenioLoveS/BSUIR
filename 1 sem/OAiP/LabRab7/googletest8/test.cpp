#include "pch.h"
#include <iostream>

std::string task8() {
    std::string str = "";
    unsigned long long n;
    std::cin >> n;
    while (n > 0) {
        str.insert(str.begin(), (n % 3) + '0');
        n = n / 3;
    }
    long long position;
    while ((position = str.find("10")) != std::string::npos) {
        str.replace(position, 2, "03");
    }
    long long position2;
    while ((position2 = str.find("20")) != std::string::npos) {
        str.replace(position2, 2, "13");
    }
    long long position3;
    while ((position3 = str.find("30")) != std::string::npos) {
        str.replace(position3, 2, "23");
    }
    while (str[0] == '0' && str.size() > 0) {
        str.erase(str.begin());
    }
    return str;
}

TEST(Test1) {
    // 2000000000 // 9 �����
    EXPECT_EQ(task8(), "11233323323111312232");
}

TEST(Test2) {
    // 2000000000 // 8 �����
    EXPECT_EQ(task8(), "111213322223331332");
}