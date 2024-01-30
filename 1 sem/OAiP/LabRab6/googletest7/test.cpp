#include "pch.h"
#include <iostream>

int task7() {
    unsigned long long count = 0;
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] == str[str.size() - 1 - i]) {
            count = count + 1;
        }
    }
    int count2 = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[0] == str[str.size() - 1 - i]) {
            count2++;
        }
    }
    if (count2 == str.size()) {
        return -1;
    }
    unsigned long long temp = str.size() - 1;
    if (count == str.size() / 2) {
        return temp;
    }
    else {
        std::cout << str.size();
        return str.size();
    }
    return 0;
}

TEST(Test1) {
    //bbbbbbbbbb
    EXPECT_EQ(task7(), -1);
}
TEST(Test2) {
    //SAIPPUAKIVIKAUPPIAS
    EXPECT_EQ(task7(), 18);
}