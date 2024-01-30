#include "pch.h"

int massiv()
{
    setlocale(LC_ALL, "russian");
    float size_of_rows;
    float size_of_collums;
    std::cout << "¬ведите размеры массива: " << "\n";
    std::cin >> size_of_rows;
    std::cin >> size_of_collums;
    float** mass = new float* [size_of_rows];
    for (int i = 0; i < size_of_rows; i++) {
        mass[i] = new float[size_of_collums];
    }
    for (int i = 0; i < size_of_rows; i++) {
        for (int j = 0; j < size_of_collums; j++) {
            std::cin >> mass[i][j];
        }
    }
    std::cout << "\n";
    float count = 0;
    for (int i = 0; i < size_of_rows; i++) {
        for (int j = 0; j < size_of_collums; j++) {
            if (mass[i][j] == 0) {
                return i;
                return j;
                count++;
            }
        }
    }
    return count;
    std::cout << "\n\n";
    for (int i = size_of_rows - 1; i >= 0; i--) {
        for (int j = size_of_collums - 1; j >= 0; j--) {
            return mass[i][j];
        }
        std::cout << "\n";
    }
    for (int i = 0; i < size_of_rows; i++) {
        delete[] mass[i];
    }
    delete[] mass;
}

// 2 2   5.5 3 0 7
TEST(test_ordinary_1) {
    ASSERT_EQ(massiv(), 1, 0, 1, 7, 0, 3, 5.5);
}
TEST(test_ordinary_2) {
    // 2 2  2.5 0 1 2
    ASSERT_EQ(massiv(), 0, 1, 1, 2, 1, 0, 2.5);
}
TEST(test_ordinary_3) {
    // 2 2  1.5 3 2 0
    ASSERT_EQ(massiv(), 1, 1, 1, 0, 2, 1.5, 3);
}