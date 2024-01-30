﻿#include <iostream>

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
    std::cout << "Создать динамический массив из элементов, расположенных на главной диагонали матрицы и имеющих четное значение. " << "\n";
    std::cout << "Вычислить произведение элементов динамического массива." << "\n";
    std::cout << "Созданный массив и результат произведения вывести на экран." << "\n";
}
void vvodmassiva(int* mass[], int* size_of_rows, int* size_of_collums) {
    int rows = *(size_of_rows);
    int collums = *(size_of_collums);
    std::cout << "Введите элементы массива: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            mass[i][j] = elcheck();
        }
    }
}
void massiv(int* mass[], int* size_of_rows, int* size_of_collums) {
    int rows = *(size_of_rows);
    int collums = *(size_of_collums);
    int sum = 0;
    int counter = 0;
    int o = 0;
    int num;
    int* mass2 = new int[collums];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            if ((i == j) && (mass[i][j] % 2 == 0)) {
                mass2[i] = mass[i][j];
                counter++;
            }
        }
    }
    if (counter == 0) {
        std::cout << "Четные значения на диагонали отсутствуют\n" << "Произведение: 0 ";
        return;
    }
    for (int i = 0; i < collums; i++) {
        if (mass2[i] > 0) {
            std::cout << "Четные значения на главной диагонали: " << mass2[i] << "\n";
            num = i;
            o++;
        }
    }
    if (o == 1) {
        std::cout << "Произведение: " << mass2[num];
        return;
    }
    for (int i = 1; i < collums; i++) {
        if (i > collums - 1) {
            return;
        }
        sum += mass2[i] * mass2[i - 1];
    }
    std::cout << "Произведение четных элементов на главной диагонали: " << sum;
    delete[] mass2;
}
void task3()
{
    setlocale(LC_ALL, "russian");
    condition();
    int size_of_rows;
    int size_of_collums;
    std::cout << "Введите размеры массива: " << "\n";
    size_of_rows = arrcheck();
    size_of_collums = arrcheck();
    int** mass = new int* [size_of_rows];
    for (int i = 0; i < size_of_rows; i++) {
        mass[i] = new int[size_of_collums];
    }
    vvodmassiva(mass, &size_of_rows, &size_of_collums);
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
            task3();
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