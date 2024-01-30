#include <iostream>
#include <stdio.h>
#include <cstring>

bool isVowel(char c) {
    static const char VOWELS[] = { 'a', 'e','i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };

    for (int i = 0; i < 12; i++) {
        if (c == VOWELS[i]) {
            return true;
        }
    }

    return false;
}

void processString(const char* str, int& begin, int& end, const int SIZE) {
    int i = 0;

    while (str[i] == ' ' && i < SIZE)
        i++;

    begin = i;

    i = strlen(str) - 1;

    while (str[i] == ' ' && i >= 0)
        i--;

    end = i;
}

void task(const char* str, const int begin, const int end) {
    static const int WORD_SIZE = 256;
    char word[WORD_SIZE] = {};
    int wordSize = 0;

    for (int i = begin; i < end; i++) {
        if (str[i] != ' ') {
            word[wordSize] = str[i];
            wordSize++;
        }
        else {
            word[wordSize] = '\0';
            if (isVowel(word[0]) && isVowel(word[wordSize - 1])) {
                std::cout << word << " ";
            }
            wordSize = 0;
        }
    }

    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "");
    const int SIZE = 1024;
    char str[SIZE];
    std::cout << "Введите строку, после строки пробел,потом enter " << "\n";
    fgets(str, SIZE, stdin);
    int begin, end;
    processString(str, begin, end, SIZE);
    task(str, begin, end);

    return 0;
}