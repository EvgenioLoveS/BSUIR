#include <iostream>
using namespace std;

int main() {
    int counter = 0;
    int sizek; //количество элементов массива
    cin >> sizek;
    int sizeg;
    cin >> sizeg;
    int arr[sizek][sizeg];//объявляем массив

    //считываем элементы массива
    for (int i = 0; i < sizek; i++) {
        for (int j = 0; j < sizeg; j++) {
            cin >> arr[i][j];
        }
    }
    //выводим
    for (int i = 0; i < sizek; i++) {
        for (int j = 0; j < sizeg; j++)
        {
            //левый верхний угол
            if (i == 0 && j == 0)
            {
                if (arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i + 1][j]
                    && arr[i][j] < arr[i + 1][j + 1])
                {
                    counter++;
                }
            }
            //правый угол
            else if (i == 0 && j == sizeg) {
                if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j]
                    && arr[i][j] < arr[i + 1][j - 1])
                {
                    counter++;
                }
            }
            //левый нижний угол
            else if (i == sizek && j == 0) {
                if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j + 1]
                    && arr[i][j] < arr[i][j + 1])
                {
                    counter++;
                }
            }
            //правый нижний угол
            else if (i == sizek && j == sizeg) {
                if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i - 1][j]
                    && arr[i][j] < arr[i - 1][j - 1])
                {
                    counter++;
                }
            }
            //первый ряд массива
            else if (i == 0 && j != 0) {
                if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i][j + 1]
                    && arr[i][j] < arr[i + 1][j - 1]
                    && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i + 1][j])
                {
                    counter++;
                }
            }
            //первый столбик массива
            else if (i != 0 && j == 0)
            {
                if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j + 1]
                    && arr[i][j] < arr[i][j + 1]
                    && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i + 1][j])
                {
                    counter++;
                }
            }
            //последний столбик массива
            else if (i != 0 && j == sizeg) {
                if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1]
                    && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i - 1][j - 1] &&
                    arr[i][j] < arr[i - 1][j]) {
                    counter++;
                }
            }
            //нижний ряд
            else if (i == sizek && j != 0)
            {
                if (arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i][j - 1] &&
                    arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j - 1] &&
                    arr[i][j] < arr[i - 1][j + 1]) {
                    counter++;
                }
            }
            //все остальное
            else if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i][j + 1]
                && arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j - 1]
                && arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i + 1][j - 1]
                && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i + 1][j])
            {
                counter++;
            }
        }
    }
    cout << counter;
    //i - строки
    //j - столбцы
    return 0;
}