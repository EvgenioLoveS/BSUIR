#include "pch.h"


int massiv()
{
    setlocale(LC_ALL, "russian");
    int size_of_rows;
    int size_of_collums;
    std::cout << "¬ведите размеры массива: " << "\n";
    std::cin >> size_of_rows;
    std::cin >> size_of_collums;
    int** mass = new int* [size_of_rows];
    for (int i = 0; i < size_of_rows; i++) {
        mass[i] = new int[size_of_collums];
    }
    std::cout << "¬ведите элементы массива: " << "\n";
    for (int i = 0; i < size_of_rows; i++) {
        for (int j = 0; j < size_of_collums; j++) {
            std::cin >> mass[i][j];
        }
    }
    int sum = 0;
    int count = 0;
    int** mass2 = new int* [size_of_rows]();
    for (int i = 0; i < size_of_rows; i++) {
        mass2[i] = new int[size_of_collums]();
    }
    for (int i = 0; i < size_of_rows; i++) {
        for (int j = 1; j < size_of_collums; j += 2) {
            if (mass[i][j] % 2 != 0) {
                mass2[i][j] = mass[i][j];
            }
        }
    }
    for (int i = 0; i < size_of_rows; i++) {
        for (int j = 0; j < size_of_collums; j++) {
            if (mass2[i][j] != 0) {
                sum += mass2[i][j];
                count++;
            }
        }
    }
    if (count == 0) {
        std::cout << "0";
    }
    else {
        return double(sum / count);
    }
    std::cout << "—реднее арифмитическое: " << double(sum / count);
    for (int i = 0; i < size_of_rows; i++) {
        delete[] mass2[i];
    }
    delete[] mass2;
    for (int i = 0; i < size_of_rows; i++) {
        delete[] mass[i];
    }
    delete[] mass;
}

TEST(test_ordinary_1) {
    //3 3 3 6 7 8 9 10 2 3 4
    ASSERT_EQ(massiv(), 6);
}
TEST(test_ordinary_2) {
    //2 2 8 2 7 7 
    ASSERT_EQ(massiv(), 7);
}
TEST(test_ordinary_3) {
    //2 2 7 9 8 1
    ASSERT_EQ(massiv(), 5);
}