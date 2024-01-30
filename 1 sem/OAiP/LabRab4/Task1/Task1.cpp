#include <iostream>
#include <ctime>
#include <cmath>

long long int vvod()
{
    const int MIN = 1;
    bool isIncorrect;
    long long int n;
    do
    {
        isIncorrect = false;
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            isIncorrect = true;
            std::cout << "Неверный тип данных" << '\n';
        }
        if (!isIncorrect && std::cin.get() != '\n')
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;

            std::cout << "Ошибка" << '\n';
            isIncorrect = true;
        }
    } while (isIncorrect);
    return n;
}

int main()
{
        std::string s;
        setlocale(LC_ALL, "Russian");
        std::cout << "Ввести одномерный статический массив из k чисел." << "\n";
        std::cout << "Найти количество элементов массива,отличающихся от среднего значения элементов массива не более чем на 3." << "\n";
        std::cout << "Выполнил: Жгутов Евгений" << "\n";
        std::cout << "Номер варианта: 11";
        std::cout << "\n";
        do
        { 
        srand(time(NULL));
        const int k = 20; // ВВОДИМ КОЛИЧЕСТВО ЭЛЕМЕНТОВ 
        int sum = 0;
        int sra = 0;
        int num = 0;
        int arr[k];

        for (int i = 0; i < k; i++) {
            arr[i] = vvod();
        }
        for (int i = 0; i < k; i++) {
            std::cout << arr[i] << " ";
            sum = sum + arr[i];
        }
        sra = sum / k;
        for (int i = 0; i < k; i++) {
            if (abs(arr[i] - sra) <= 3) {
                num++;
            }
        }
        std::cout << "\n" << "Среднее значение: " << sra;
        std::cout << "\n" << "Количество: " << num << "\n\n";
        std::cout << "для повторного ввода введите что угодно,для выхода введите 0\n";
        bool incorrectinput = false;
        do {
            {
                std::cin >> s;
                if (std::cin.peek() != ' ' && std::cin.peek() != '\n' || s == "0")
                {
                    if (s == "0") {
                        return 0;
                    }
                    std::cin.clear();
                    std::cin.ignore(80, '\n');
                    incorrectinput = true;
                    std::cout << "неверный ввод.Введите еще раз ";
                }
            }
        } while (incorrectinput == true);
        } while (s != "0");
    return 0;
}