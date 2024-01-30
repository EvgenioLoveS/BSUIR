#include <iostream>
#include <algorithm>
#include <locale.h>


void whoami() {
    std::cout << "\n";
    std::cout << "Выполнил: Жгутов Евгений Дмитриевич" << "\n";
    std::cout << "Группа: 253505" << "\n";
    std::cout << "\n";
}

void condition() {
    std::cout << "\n";
    std::cout << "Необходимо разработать программу, которая проверяет, делится ли введенное пользователем число на заданное простое." << "\n";
    std::cout << "Программа не должна содержать операций умножения, деления, вычитания(в том числе взятия остатка от деления)." << "\n";
    std::cout << "Рекомендуется использовать побитовые операции." << "\n";
    std::cout << "Для каждого варианта нужно проверить делимость на 3 простых числа." << "\n";
    std::cout << "Проверять можно по отдельности(сначала получить ответ для первого, затем для второго, затем для третьего)." << "\n";
    std::cout << "Первое число - 3" << "\n";
    std::cout << "Второе число - 47" << "\n";
    std::cout << "Третье число 197" << "\n";
    std::cout << "\n";
}
long long proverka0()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < INT_MIN || x > INT_MAX || getchar() != '\n')
    {
        printf("\n");
        printf("Ошибка ввода, повторите ввод!!!\n");
        rewind(stdin);
    }
    return x;
}

long long proverka()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < 1 || x > 3 || getchar() != '\n')
    {
        printf("\n");
        printf("Ошибка ввода, повторите ввод!!!\n");
        printf("Выберите вариант:\n");
        rewind(stdin);
    }
    return x;
}

long long proverka2()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < 1 || x > 2 || getchar() != '\n')
    {
        printf("\n");
        printf("Ошибка ввода, повторите ввод!!!\n");
        printf("Хотите ли вы продолжить?\n");
        rewind(stdin);
    }
    return x;
}

void task6() {
    std::cout << "\n";
    std::cout << "Введите число";
    std::cout << "\n";

    long long number;
    number = proverka0();
    std::cout << "\n";

    long long coefficient_of_number3 = number;
    long long coefficient_of_number47 = number;
    long long coefficient_of_number197 = number;
    long long r = 0;
    bool check = false;

    while (coefficient_of_number3 > 5) { // (3 * 2) - 1
        if (coefficient_of_number3 & 1) {
            r = 5;
        }
        else {
            r = 0;
        }
        coefficient_of_number3 >>= 1;
        if (coefficient_of_number3 + r == 3) {
            check = true;
            break;
        }
        coefficient_of_number3 = coefficient_of_number3 + r;
    }
    if (check) {
        std::cout << "\n";
        std::cout << "Да оно делится на 3";
        std::cout << "\n";

    }
    else {

        std::cout << "Нет оно не делится на 3";
        std::cout << "\n";
    }

    check = false;
    while (coefficient_of_number47 > 93) { // (47 * 2) - 1
        if (coefficient_of_number47 & 1) {
            r = 24;
        }
        else {
            r = 0;
        }
        coefficient_of_number47 >>= 1;
        if (coefficient_of_number47 + r == 47) {
            check = true;
            break;
        }
        coefficient_of_number47 = coefficient_of_number47 + r;
    }
    if (check) {
        std::cout << "Да оно делится на 47";
        std::cout << "\n";

    }
    else {

        std::cout << "Нет оно не делится на 47";
        std::cout << "\n";
    }
    check = false;
    while (coefficient_of_number197 > 393) { //(197 * 2) - 1
        if (coefficient_of_number197 & 1) {
            r = 99;
        }
        else {
            r = 0;
        }
        coefficient_of_number197 >>= 1;
        if (coefficient_of_number197 + r == 197) {
            check = true;
            break;
        }
        coefficient_of_number197 = coefficient_of_number197 + r;
    }
    if (check) {
        std::cout << "Да оно делится на 197";
        std::cout << "\n";

    }
    else {
        std::cout << "Нет оно не делится на 197";
        std::cout << "\n";
    }
    check = false;
}

int main() {
    setlocale(LC_ALL, "russian");
    int resume;

    do
    {

        int n;
        std::cout << "Выберите вариант: " << "\n";
        std::cout << "1 - условие задания " << "\n";
        std::cout << "2 - запуск функции самого задания " << "\n";
        std::cout << "3 - информация о студенте, выполнившим задание. " << "\n";

        n = proverka();

        switch (n)
        {
        case 1:
        {
            condition();
        }
        break;
        case 2:
        {
            task6();
        }
        break;
        case 3:
        {
            whoami();
        }
        break;
        }

        std::cout << "\nХотите ли вы продолжить?" << "\n";
        std::cout << "1 - Да" << "\n";
        std::cout << "2 - Нет" << "\n";
        resume = proverka2();
        system("cls");

    } while (resume == 1);
    return 0;
}