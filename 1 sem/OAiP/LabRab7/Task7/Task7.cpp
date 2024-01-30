#include<iostream>


bool Check_OF_Number(int* massiv_of_numbers) {
    long long  bank_of_numbers[175];
    for (int i = 1; i < 170; i++) {
        bank_of_numbers[i] = massiv_of_numbers[i];
    }
    for (int size = 170 - massiv_of_numbers[0]; size > 0; size--) {
        for (int i = massiv_of_numbers[0]; i < 170; i++) {
            bank_of_numbers[i + 1] += (bank_of_numbers[i] % 2) * 10;
            bank_of_numbers[i] >>= 1;
        }
    }
    return !(bank_of_numbers[169] % 2);
}

int main()
{
    int** massiv_of_numbers = new int* [12000];
    long long  index_of_numbers = 1;
    long long  start_of_numbers = 0;
    long long  end_of_numbers = 0;
    for (int i = 0; i < 12000; i++) {
        massiv_of_numbers[i] = new int[170];
    }
    long long number;
    std::cin >> number;
    massiv_of_numbers[0][169] = 1;
    massiv_of_numbers[0][0] = 169;

    while (index_of_numbers <= number) {

        for (int i = start_of_numbers; i <= end_of_numbers; i++) {
            for (int j = 0; j < 170; j++) {
                massiv_of_numbers[index_of_numbers][j] = massiv_of_numbers[i][j];
            }
            int k = massiv_of_numbers[index_of_numbers][0];
            massiv_of_numbers[index_of_numbers][k - 1] = 1;
            massiv_of_numbers[index_of_numbers][k] = 0;
            massiv_of_numbers[index_of_numbers][0]--;
            if (Check_OF_Number(massiv_of_numbers[i])) {
                index_of_numbers++;
            }
        }

        for (int i = start_of_numbers; i <= end_of_numbers; i++) {
            for (int j = 0; j < 170; j++) {
                massiv_of_numbers[index_of_numbers][j] = massiv_of_numbers[i][j];
            }
            int k = massiv_of_numbers[index_of_numbers][0];
            massiv_of_numbers[index_of_numbers][k - 1] = 1;
            massiv_of_numbers[index_of_numbers][0]--;
            if (Check_OF_Number(massiv_of_numbers[i])) {
                index_of_numbers++;
            }
        }
        start_of_numbers = end_of_numbers + 1;
        end_of_numbers = index_of_numbers - 1;
    }

    for (int i = massiv_of_numbers[number - 1][0]; i < 170; i++) {
        std::cout << massiv_of_numbers[number - 1][i];
    }

    for (int i = 0; i < 12000; i++) {
        delete massiv_of_numbers[i];
    }
    delete[] massiv_of_numbers;
}