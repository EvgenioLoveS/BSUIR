#include "pch.h"

int massiv()
{
    setlocale(LC_ALL, "russian");
    int size_of_rows;
    int size_of_collums;
    std::cout << "Введите размеры массива: " << "\n";
    std::cin >> size_of_rows;
    std::cin >> size_of_collums;
    int** mass = new int* [size_of_rows];
    for (int i = 0; i < size_of_rows; i++) {
        mass[i] = new int[size_of_collums];
    }
    std::cout << "Введите элементы массива: " << "\n";
    for (int i = 0; i < size_of_rows; i++) {
        for (int j = 0; j < size_of_collums; j++) {
            std::cin >> mass[i][j];
        }
    }
    int sum = 0;
    int counter = 0;
    int o = 0;
    int num;
    int* mass2 = new int[size_of_collums];
    for (int i = 0; i < size_of_rows; i++) {
        for (int j = 0; j < size_of_collums; j++) {
            if ((i == j) && (mass[i][j] % 2 == 0)) {
                mass2[i] = mass[i][j];
                counter++;
            }
        }
    }
    if (counter == 0) {
        std::cout << "Четные значения на диагонали отсутствуют\n" << "Произведение: 0 ";
        return 0;
    }
    for (int i = 0; i < size_of_collums; i++) {
        if (mass2[i] > 0) {
            std::cout << "Четные значения на главной диагонали: " << mass2[i] << "\n";
            num = i;
            o++;
        }
    }
    if (o == 1) {
        std::cout << "Произведение: ";
        return mass2[num];
        return 0;
    }

    for (int i = 1; i < size_of_collums; i++) {
        if (i > size_of_collums - 1) {
            return 0;
        }

        return sum += mass2[i] * mass2[i - 1];
    }
    std::cout << "Произведение четных элементов на главной диагонали: " << sum;
    delete[] mass2;
    for (int i = 0; i < size_of_rows; i++) {
        delete[] mass[i];
    }
    delete[] mass;
}

TEST(test_ordinary_1)
{
    //  2 2    2  8  9  12
    ASSERT_EQ(massiv(), 24);
}
TEST(test_ordinary_2)
{
    //  2 2   2  7  8  8
    ASSERT_EQ(massiv(), 16);
}
TEST(test_ordinary_3)
{
    //  2 2   0  0  0  0
    ASSERT_EQ(massiv(), 0);
}