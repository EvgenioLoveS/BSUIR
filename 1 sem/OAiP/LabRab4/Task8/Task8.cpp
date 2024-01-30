#include <iostream>


int main()
{
    int N;
    int M;

    std::cin >> N;
    //выделяем память на массив A
    int** A = new int* [N];
    for (int i = 0; i < N; i++)
        A[i] = new int[N];

    // вводим элементры матрицы A
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            std::cin >> A[i][j];
        }
    }
    std::cin >> M;
    //выделяем память на массив B
    int** B = new int* [M];
    for (int i = 0; i < M; i++)
        B[i] = new int[M];

    // вводим элементры матрицы B
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++)
        {
            std::cin >> B[i][j];
        }
    }
    //выделяем память на массив C
    int** C = new int* [N];
    for (int i = 0; i < N; i++)
        C[i] = new int[N];

    //подсчёт произведения матриц A and B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    //вывод результирующей матрицы
    int X = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[i][j];
            if (i == X && j == N - 1) {
                continue;
            }
            std::cout << " ";
        }
        X++;
        if (i == N - 1) {
            continue;
        }
        std::cout << std::endl;
    }
    // очистка массива B
    for (int i = 0; i < M; i++) {
        delete[] B[i];
    }
    delete[] B;
    // очистка массива A
    for (int i = 0; i < N; i++) {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}