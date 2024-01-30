#include <iostream>

int main()
{
    short* arr = new short[100000];
    char x;
    int result = 0;
    int count = 0;
    while (std::cin.peek() != '\n')
    {
        std::cin >> x;
        arr[result] = x - 48;
        result++;
    }
    int ind = 0;
    std::cin >> ind;
    bool poisk = false;
    for (int i = 0; i < result; i++) {
        for (int j = i + 1; j < result; j++) {
            if (arr[i] == arr[j]) {
                poisk = true;
                break;
            }
        }
        if (!poisk) {
            count++;
        }
        poisk = false;
    }
    std::cout << count << "\n";
    for (int i = result - 1; i > -1; i--)
    {
        if (arr[i] == arr[ind - 1])
        {
            std::cout << result - i - 1 << " ";
        }
    }
    delete[] arr;
    return 0;
}