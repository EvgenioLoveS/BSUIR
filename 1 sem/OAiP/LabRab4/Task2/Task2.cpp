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
    } while (isIncorrect);
    return n;
}
int main()
{
    std::string s;
    setlocale(LC_ALL, "Russian");
    std::cout << "Инициализировать при объявлении статический двумерный массив целых чисел размером NxM." << "\n";
    std::cout << "Найти в каждой строке матрицы максимальный элемент." << "\n";
    std::cout << "Выполнил: Жгутов Евгений" << "\n";
    std::cout << "Номер варианта: 11" << "\n";
    do
    { 
    const int n = 3;
    const int m = 3;
    int arr[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            arr[i][j] = vvod();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }
    for (int i = 0; i < n; ++i) {
        int max = arr[i][0];
        for (int j = 1; j < m; ++j)
            if (arr[i][j] > max)
                max = arr[i][j];
        std::cout << "максимальное значение в  " << i + 1 << " строке = " << max << "\n";
    }
    std::cout << "для повторного ввода введите что угогдно,для выхода введите 0\n";
    bool incorrectinput = false;
    do
    {
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