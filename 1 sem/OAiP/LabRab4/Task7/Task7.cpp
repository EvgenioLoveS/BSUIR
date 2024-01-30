#include <iostream>
#include <ctime>

int main()
{
    int indmax, indmin, max, min;
    int arr[100];
    int n = 0;
    int k;
    while (std::cin >> k) {
        arr[n] = k;
        n++;
    }
    indmax = 0;
    max = arr[indmax];
    for (int i = 0; i < n; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            indmax = i;
        }
    }
    indmin = 0;
    min = arr[indmin];
    for (int i = 0; i < n; i++) {
        if (arr[i] <= min) {
            min = arr[i];
            indmin = i;
        }
    }
    if (indmin < indmax) {
        for (int i = (indmin + 1); i <= (indmax - 1); i++) {
            arr[i] = 0;
        }
    }
    else {
        for (int i = (indmax + 1); i <= (indmin - 1); i++)
            arr[i] = 0;
    }
    int countnul = 0;
    int countnenul = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            countnul++;
        }
        if (arr[i] != 0) {
            countnenul++;
        }
    }
    if (countnenul > countnul) {
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                std::cout << arr[i] << " ";
            }
        }
    }
    return 0;
}