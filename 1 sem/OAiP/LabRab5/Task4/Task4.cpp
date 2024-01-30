#include <iostream>

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
double elcheck()
{
    double x;
    while (scanf_s("%lf", &x) != 1.0 || x < INT_MIN || x > INT_MAX || getchar() != '\n')
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
    std::cout << "Создать двумерный динамический массив вещественных чисел." << "\n";
    std::cout << "Определить, встречаются ли среди них элементы с нулевым значением." << "\n";
    std::cout << "Если встречаются такие элементы, то определить их индексы и общее количество." << "\n";
    std::cout << "Переставить элементы этого массива в обратном порядке и вывести на экран." << "\n";
}
void vvodmassiva(float* mass[], float* size_of_rows, float* size_of_collums) {
    float rows = *(size_of_rows);
    float collums = *(size_of_collums);
    std::cout << "Введите элементы массива: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            mass[i][j] = elcheck();
        }
    }
    std::cout << "\n";
}
void massiv(float* mass[], float* size_of_rows, float* size_of_collums) {
    float rows = *(size_of_rows);
    float collums = *(size_of_collums);
    float count = 0;
    std::cout << "Индексы: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            if (mass[i][j] == 0) {
                std::cout << "arr[" << i << "]" << "[" << j << "]" << " ";
                count++;
            }
        }
    }
    std::cout << "\n\n";
    std::cout << "Общее количество элементов с нулевым значением: " << count << "\n";
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = collums - 1; j >= 0; j--) {
            std::cout << mass[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void vivodmassiva(float* mass[], float* size_of_rows, float* size_of_collums) {
    float rows = *(size_of_rows);
    float collums = *(size_of_collums);
    std::cout << "Изначальный массив: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            std::cout << mass[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
void task4()
{
    setlocale(LC_ALL, "russian");
    condition();
    float size_of_rows;
    float size_of_collums;
    std::cout << "Введите размеры массива: " << "\n";
    size_of_rows = arrcheck();
    size_of_collums = arrcheck();
    float** mass = new float* [size_of_rows];
    for (int i = 0; i < size_of_rows; i++) {
        mass[i] = new float[size_of_collums];
    }
    vvodmassiva(mass, &size_of_rows, &size_of_collums);
    vivodmassiva(mass, &size_of_rows, &size_of_collums);
    massiv(mass, &size_of_rows, &size_of_collums);
    for (int i = 0; i < size_of_rows; i++) {
        delete[] mass[i];
    }
    delete[] mass;
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
            task4();
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