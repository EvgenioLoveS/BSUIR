#include <iostream> 
#include <ctime>

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
        if (!isIncorrect && n < MIN)
        {
            isIncorrect = true;
            std::cout << "Неверный диапозон" << '\n';
        }
    } while (isIncorrect);
    return n;
}
long long int vvod2()
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
    long long sum1 = 0;
    long long sum2 = 0;
    long long sum3 = 0;
    long long N;
    std::cout << "Память для массива выделить динамически." << "\n";
    std::cout << "Дана действительная матрица порядка N." << "\n";
    std::cout << "Рассмотрим те элементы,которые расположены в строках,начинающихся с отрицательного элемента." << "\n";
    std::cout << "Найти сумму тех из них,которые расположены соответственно ниже,выше, и на главной диагонали матрицы." << "\n";
    std::cout << "Выполнил: Жгутов Евгений" << "\n";
    std::cout << "Номер варианта: 11" << "\n";
    do
    {
    std::cout << "Введите ранг матрицы: " << "\n";
    N = vvod();
    std::cout << "\n";
    long long** arr = new long long* [N];
    for (int i = 0; i < N; i++) {
        arr[i] = new long long[N];
    }
    std::cout << "Введите элементы массива: " << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; ++j)
            arr[i][j] = vvod2();
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i][0] < 0)
            for (int j = 0; j < N; j++)
            {

                if (i < j)
                    sum1 = sum1 + arr[i][j];
                if (i == j)
                    sum2 = sum2 + arr[i][j];
                if (i > j)
                    sum3 = sum3 + arr[i][j];
            }
    }
    std::cout << "\n" << "Сумма элементов выше диагонали: " << sum1;
    std::cout << "\n" << "Сумма элементов на диагонали: " << sum2;
    std::cout << "\n" << "Сумма элементов ниже диагонали: " << sum3 << "\n";
    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    std::cout << "для повторного ввода введите что угогдно,для выхода введите 0\n\n";
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