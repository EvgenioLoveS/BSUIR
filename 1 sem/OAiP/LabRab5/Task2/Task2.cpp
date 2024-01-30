#include <iostream>
#include <Windows.h>

long long proverka()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < 1 || x > 3 || getchar() != '\n')
    {
        printf("Error\n");
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
        printf("Ошибка ввода, повторите ввод!!!\n");
        printf("Хотите ли вы продолжить?\n");
        rewind(stdin);
    }
    return x;
}
long long elcheck()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < INT_MIN || x > INT_MAX || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}
long long arrcheck()
{
    long long x;
    while (scanf_s("%lld", &x) != 1 || x < 1 || x > INT_MAX || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}
void whoami() {
    std::cout << "Выполнил: Жгутов Евгений Дмитриевич" << "\n";
    std::cout << "Группа: 253505" << "\n";
    std::cout << "" << "\n";
}
void condition() {
    std::cout << "Для заданного одномерного массива A из N элементов найти значение максимального элемента массива." << "\n";
    std::cout << "Рекурсивную функцию применять каждый раз отдельно для первой трети массива и для остальной части(2 / 3) массива." << "\n";
    std::cout << "Рекурсивные вызовы заканчивать, когда останется только один или два элемента." << "\n";
}
void printArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int(*Max)(int*, int, int) = (int(*)(int*, int, int))GetProcAddress(LoadLibrary(L"D:/253505/OAiP/LabRab555/x64/Debug/Dynamiclib.dll"), "max");
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
            std::cout << "Введите размер массива : ";
            int n;
            n = arrcheck();

            std::cout << "Введите элементы массива :\n";
            int* arr = new int[n];
            for (int i = 0; i < n; i++)
            {   
                arr[i] = elcheck();
            }

            printArr(arr, n);

            std::cout << "максимальный элемент : " << Max(arr, 0, n - 1) << std::endl;

            delete[] arr;
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