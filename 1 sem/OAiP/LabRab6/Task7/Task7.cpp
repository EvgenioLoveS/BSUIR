#include <iostream>

int main() {
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
        std::cout << "-1";
        return 0;
    }
    unsigned long long temp = str.size() - 1;
    if (count == str.size() / 2) {
        std::cout << temp;
    }
    else {
        std::cout << str.size();
    }
    return 0;
}