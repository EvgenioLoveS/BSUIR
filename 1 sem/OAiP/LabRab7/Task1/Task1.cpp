#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

void whoami() {
    std::cout << "Выполнил: Жгутов Евгений Дмитриевич" << "\n";
    std::cout << "Группа: 253505" << "\n";
    std::cout << "" << "\n";
}

void condition() {
    std::cout << "Перевести числа." << "\n";
    std::cout << "Предусмотреть ввод положительных и отрицательных чисел." << "\n";
    std::cout << "Из естественной формы в прямой код." << "\n";
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
void task1()
{
    std::string string;
    long long dlina = 0;
    //проверка на ввод
    while (true)
    {
        bool check = 1;
        long times = 0;
        std::cout << "Введите ваше число в естественной форме: " << "\n";
        std::cin >> string;
        std::cout << "\n";
        dlina = string.length();
        while (times < dlina)
        {
            if (!isdigit(string[times]) && (string[times] != '-' && times != 0))
            {
                check = 0;
                break;
            }
            times++;
        }
        if (check)
        {
            break;
        }
        std::cout << "\n";
        std::cout << "Ошибка ввода, повторите ввод!!!" << "\n";
        system("cls");
    }
    //знак
    std::string sign = "0";
    if (string[0] == '-')
    {
        sign = "1";
    }
    //перевод в двоичную систему
    long long number_from_string = std::stoi(string);
    number_from_string = fabs(number_from_string);
    int integer = 1, number;

    while (number_from_string != 0)
    {
        string.resize(integer);
        number = number_from_string % 2 + 48;
        string[integer - 1] = number;
        number_from_string /= 2;
        integer++;
    }
    std::reverse(string.begin(), string.end());
    string.insert(0, sign);
    dlina = string.length();
    std::cout << "Ваше число в прямом коде: ";
    std::cout << string;
    std::cout << "\n";
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
        system("cls");

        switch (n)
        {
        case 1:
        {
            condition();
        }
        break;
        case 2:
        {
            task1();
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