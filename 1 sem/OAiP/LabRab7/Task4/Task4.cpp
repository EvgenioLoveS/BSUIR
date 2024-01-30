#include <iostream>

int main() {
    long long number;
    std::cin >> number;
    unsigned long long thousands;
    unsigned long long hundreds;
    unsigned long long tens;
    unsigned long long units;
    thousands = (number / 1000);
    hundreds = (number % 1000) / 100;
    tens = (number % 100) / 10;
    units = (number % 10);
    //работа с тысячами
    for (thousands; thousands >= 1 && thousands <= 3; thousands--) {
        std::cout << "M";
    }
    //работа с сотнями
    for (hundreds; hundreds >= 1 && hundreds <= 3; hundreds--) {
        std::cout << "C";
    }
    if (hundreds == 4) {
        std::cout << "CD";
    }
    for (hundreds; hundreds <= 8 && hundreds >= 5; hundreds--) {
        std::cout << "D";
        for (hundreds; hundreds >= 6;hundreds--) {
            std::cout << "C";
        }
    }
    if (hundreds == 9) {
        std::cout << "CM";
    }
    if (hundreds == 10) {
        std::cout << "M";
    }
    //работа с десятками
    for (tens; tens >= 1 && tens <= 3; tens--) {
        std::cout << "X";
    }
    if (tens == 4) {
        std::cout << "XL";
    }
    for (tens; tens <= 8 && tens >= 5; tens--) {
        std::cout << "L";
        for (tens; tens >= 6; tens--) {
            std::cout << "X";
        }
    }
    if (tens == 9) {
        std::cout << "XC";
    }
    if (tens == 10) {
        std::cout << "C";
    }
    //работа с единицами
    for (units; units >= 1 && units <= 3; units--) {
        std::cout << "I";
    }
    if (units == 4) {
        std::cout << "IV";
    }
    for (units; units <= 8 && units >= 5; units--) {
        std::cout << "V";
        for (units; units >= 6; units--) {
            std::cout << "I";
        }
    }
    if (units == 9) {
        std::cout << "IX";
    }
    if (units == 10) {
        std::cout << "X";
    }
    return 0;
}