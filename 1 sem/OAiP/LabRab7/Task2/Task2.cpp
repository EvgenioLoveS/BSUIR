#include <iostream>
#include <string>
#include <cmath>

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
void whoami() {
    std::cout << "\n";
    std::cout << "Выполнил: Жгутов Евгений Дмитриевич" << "\n";
    std::cout << "Группа: 253505" << "\n";
    std::cout << "\n";
}

void condition() {
    std::cout << "\n";
    std::cout << "Осуществить сложение чисел." << "\n";
    std::cout << "Разработать функции для выполнения операции сложения." << "\n";
    std::cout << "Предусмотреть ввод положительных и отрицательных чисел." << "\n";
    std::cout << "Найдите сумму двоичных чисел, заданных в естественной форме." << "\n";
    std::cout << "Сложение выполните в дополнительном коде." << "\n";
    std::cout << "Ответ выразите в естественной форме." << "\n";
    std::cout << "\n";
}
void input_number(std::string& string, long long& length);
void konvertation(std::string& string, long long length);
void count_konvertation(std::string number1, std::string number2, std::string& numberOutput, long long length);
void endresult(std::string& numberOutput, std::string& sign, long long length);

void task2()
{
    long long index = 0;
    long long length1 = 0;
    long long length2 = 0;
    std::string output, number1, number2, numberOutput;
    std::string sign = "-";

    input_number(number1, length1);
    input_number(number2, length2);

    if (length1 == length2)
    {
        number2.insert(1, "0");
        number1.insert(1, "0");
        std::cout << "Ваши числа в двоичной форме: " << "\n";
        std::cout << "Число 1: " << number1 << "\n";
        std::cout << "Число 2: " << number2 << "\n";
    }
    else if (length1 > length2)
    {
        number1.insert(1, "0");
        length1++;
        while (length1 > length2)
        {
            number2.insert(1, "0");
            length2 = number2.length();
        }
        std::cout << "Ваши числа в двоичной форме: " << "\n";
        std::cout << "Число 1: " << number1 << "\n";
        std::cout << "Число 2: " << number2 << "\n";
    }
    else
    {
        number2.insert(1, "0");
        length2++;
        while (length1 < length2)
        {
            number1.insert(1, "0");
            length1 = number1.length();
        }
        std::cout << "Ваши числа в двоичной форме: " << "\n";
        std::cout << "Число 1: " << number1 << "\n";
        std::cout << "Число 2: " << number2 << "\n";
    }
    numberOutput.resize(length1);

    //translate to editional code
    konvertation(number1, length1);
    konvertation(number2, length2);
    std::cout << "Ваши числа в дополнительном коде: " << "\n";
    std::cout << "Число 1: " << number1 << "\n";
    std::cout << "Число 2: " << number2 << "\n";

    //summing
    count_konvertation(number1, number2, numberOutput, length1);

    //end
    endresult(numberOutput, sign, length1);

}

void input_number(std::string& string, long long& length)
{
    //проверка на ввод
    while (true)
    {
        bool check = 1;
        long times = 0;
        std::cout << "Введите ваше число в естественной форме: ";
        std::cout << "\n";
        std::cin >> string;
        length = string.length();
        while (times < length)
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
        std::cout << "Неккоректный ввод!!!" << "\n";
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
    length = string.length();
}
void konvertation(std::string& code, long long length)
{
    if (code[0] != '0')
    {
        long long index = -1, times = 0;
        while (times < length)
        {
            index++;
            if (index == 0)
            {
                continue;
            }
            else if (code[index] == '0')
            {
                code[index] = '1';
            }
            else if (code[index] == '1')
            {
                code[index] = '0';
            }
            else
            {
                break;
            }
            times++;
        }
        //code after +1
        index = length;
        while (times > 0)
        {
            index--;
            if (code[index] == '0')
            {
                code[index] = '1';
                break;
            }
            else if (code[index] == '1')
            {
                code[index] = '0';
            }
        }
    }
}
void count_konvertation(std::string number1, std::string number2, std::string& numberOutput, long long length)
{
    length = number1.length();
    numberOutput.resize(length);
    int times = length - 1;
    int centre = 0;
    while (times >= 0)
    {
        if (number1[times] == '0' && number2[times] == '0')
        {
            if (centre == 0)
            {
                numberOutput[times] = '0';
            }
            else
            {
                numberOutput[times] = '1';
                centre = 0;
            }
        }
        else if ((number1[times] == '0' && number2[times] == '1') || (number1[times] == '1' && number2[times] == '0'))
        {
            if (centre == 0)
            {
                numberOutput[times] = '1';
            }
            else
            {
                numberOutput[times] = '0';
                centre = 1;
            }
        }
        else
        {
            if (centre == 0)
            {
                centre = 1;
                numberOutput[times] = '0';
            }
            else
            {
                numberOutput[times] = '1';
                centre = 1;
            }
        }
        times--;
    }
    std::cout << "\n";
    std::cout << "Наше число в дополнительном коде: " << numberOutput;
    //after summ
    if (numberOutput[0] != '0')
    {
        long long index = -1;
        times = 0;
        while (times < length)
        {
            index++;
            if (index == 0)
            {
                continue;
            }
            else if (numberOutput[index] == '0')
            {
                numberOutput[index] = '1';
            }
            else if (numberOutput[index] == '1')
            {
                numberOutput[index] = '0';
            }
            else
            {
                break;
            }
            times++;
        }
        if (centre == 1 || centre == 0)
        {
            index = length;
            while (times > 0)
            {
                index--;
                if (index == 0)
                {

                }
                if (numberOutput[index] == '0')
                {
                    numberOutput[index] = '1';
                    break;
                }
                else if (numberOutput[index] == '1')
                {
                    numberOutput[index] = '0';
                }
            }
        }
        else
        {
            return;
        }
    }
}
void endresult(std::string& numberOutput, std::string& sign, long long length)
{
    long long summ = 0, index = 0, times = -1;
    std::string translate;
    length = numberOutput.length();
    index = length;
    while (times < length - 1)
    {
        if (index == length)
        {
            if (numberOutput[0] == '0')
            {
                sign.clear();
            }
            times++;
            index--;
            continue;
        }
        else if (numberOutput[index] == '0')
        {
            times++;
            index--;
            continue;
        }
        else
        {
            summ += powl(2, times);
        }
        times++;
        index--;
    }
    translate = std::to_string(summ);
    std::cout << "\n";
    std::cout << "Число после всех манипуляций:" << sign + translate;
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
            task2();
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