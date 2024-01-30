#include <iostream> 


int main()
{
    long long n, n1, n2; // n1 and n2 числа которые выносим, n это удлинители
    long long size = 50; // задаем размерность
    long long kol1 = 1, kol2 = 1; // 
    long long number1, number2;
    long long counter = 0;
    std::cin >> n;
    if (n % 2 == 0) {  // для четного
        n1 = n / 2;
        n2 = n - 1;
    }
    else { // для нечетного
        n1 = (n - 1) / 2;
        n2 = n;
    }
    long long* mass1 = new long long[size]();
    long long* mass2 = new long long[size]();
    long long* mass3 = new long long[size]();
    number1 = n1;
    number2 = n2;
    while (number1 /= 10) { // 1 цикл для подсчета элементов в массиве
        kol1++;
    }
    while (number2 /= 10) { // 2 цикл для подсчета элементов в массиве
        kol2++;
    }
    for (int i = size - 1; i >= size - 1 - kol1; i--) { // в обратном порядке выводим 1 число 
        mass1[i] = n1 % 10;
        n1 /= 10;
    }
    for (int i = size - 1; i >= size - 1 - kol2; i--) {  // в обратном порядке выводим 2 число
        mass2[i] = n2 % 10;
        n2 /= 10;
    }
    mass3[size - 1] = 1;
    for (int i = size - 1; i >= size - 1 - kol1; i--) {
        for (int j = size - 1; j >= size - 1 - kol2; j--) {
            mass3[j - counter] += mass1[i] * mass2[j]; // присваеваем произведение двух последних разрядов
            mass3[j - counter - 1] += mass3[j - counter] / 10; // элемент на разряд левее
            mass3[j - counter] %= 10; // 
        }
        counter++;
    }
    mass3[0] = -1; // 
    mass3[1] = -1; // 
    for (int i = 2; i < size; i++) { // если элемент массива равен нулю и предыдущий равен единице
        if (mass3[i] == 0 && mass3[i - 1] == -1) {
            mass3[i] = -1;
        }
    }
    for (int i = 0; i < size; i++) { // выводим все где нет единиц
        if (mass3[i] != -1) {
            std::cout << mass3[i];
        }
    }
            delete[] mass1;
        delete[] mass2;
    delete[] mass3;
    return 0;
}