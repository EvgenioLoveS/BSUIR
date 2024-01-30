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
            std::cout << "Неверный диапазон" << '\n';
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
        if (!isIncorrect && n < MIN)
        {
            isIncorrect = true;
            std::cout << "Неверный диапозон" << '\n';
        }
    } while (isIncorrect);
    return n;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    std::string s;
    std::cout << "Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел." << "\n";
    std::cout << "Необходимо определить диагональ с наибольшей суммой чисел." << "\n";
    std::cout << "Для обхода диагоналей нельзя использовать вложенные циклы." << "\n";
    std::cout << "Выделение памяти через функции языка С." << "\n";
    std::cout << "Выполнил: Жгутов Евгений" << "\n";
    std::cout << "\n";
    bool proga = false;
    do
    {
    int n; // ВВОДИМ РАЗМЕР МАССИВА
    int sumdiag1 = 0;
    int sumdiag2 = 0;
    int sumdiag3 = 0;
    int sumdiag4 = 0;
    std::cout << "Введите размер(n): " << "\n";
    n = vvod();
    int*** arr = (int***)malloc(n * sizeof(int**));
    for (int i = 0; i < n; i++) {
        arr[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            arr[i][j] = (int*)malloc(n * sizeof(int));
        }
    }
    std::cout << "Введите элементы массива: " << "\n";
    for (int z = 0; z < n; z++)
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; x++)
                arr[z][y][x] = vvod2();
    std::cout << "\n";
    for (int z = 0; z < n; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                std::cout << arr[z][y][x] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "Элементы на 1 диагонали: " << "\t";
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i][i][i] << " ";
    }
    std::cout << "\n" << "Элементы на 2 диагонали: " << "\t";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[n - i - 1][i][i] << " ";
    }
    std::cout << "\n" << "Элементы на 3 диагонали: " << "\t";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i][n - i - 1][i] << " ";
    }
    std::cout << "\n" << "Элементы на 4 диагонали: " << "\t";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i][i][n - i - 1] << " ";
    }
    for (int i = 0; i < n; ++i)
    {
        sumdiag1 += arr[i][i][i];
        sumdiag2 += arr[n - i - 1][i][i];
        sumdiag3 += arr[i][n - i - 1][i];
        sumdiag4 += arr[i][i][n - i - 1];
    }
    std::cout << "\n\n" << "Сумма элементов на 1 диагонали: " << sumdiag1 << "\n";
    std::cout << "Сумма элементов на 2 диагонали: " << sumdiag2 << "\n";
    std::cout << "Сумма элементов на 3 диагонали: " << sumdiag3 << "\n";
    std::cout << "Сумма элементов на 4 диагонали: " << sumdiag4 << "\n";
    if (sumdiag1 > sumdiag2 && sumdiag1 > sumdiag3 && sumdiag1 > sumdiag4) {
        std::cout << "Наибольшая диагональ 1" << "\n";
    }
    if (sumdiag2 > sumdiag1 && sumdiag2 > sumdiag3 && sumdiag2 > sumdiag4) {
        std::cout << "Наибольшая диагональ 2" << "\n";
    }
    if (sumdiag3 > sumdiag1 && sumdiag3 > sumdiag2 && sumdiag3 > sumdiag4) {
        std::cout << "Наибольшая диагональ 3" << "\n";
    }
    if (sumdiag4 > sumdiag1 && sumdiag4 > sumdiag2 && sumdiag4 > sumdiag3) {
        std::cout << "Наибольшая диагональ 4" << "\n";
    }
    if (sumdiag1 == sumdiag2 && sumdiag2 == sumdiag3 && sumdiag3 == sumdiag4) {
        std::cout << "Диагонали равны" << "\n";
    }
    else {
        std::cout << "Нельзя выделить наибольшую" << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            free(arr[i][j]);
        free(arr[i]);
    }
    free(arr);
    std::cout << "для повторного ввода введите что угогдно,для выхода введите 0\n";
    bool proga = false;
    do
    {
        {
            std::cin >> s;
            if (std::cin.peek() != ' ' && std::cin.peek() != '\n' || s == "0")
            {
                if (s == "0")
                {
                    return 0;
                }
                std::cin.clear();
                std::cin.ignore(80, '\n');
                proga = true;
                std::cout << "неверный ввод.Введите еще раз ";
            }
        }
    } while (proga == true);
} while (s != "0");
    return 0;
}