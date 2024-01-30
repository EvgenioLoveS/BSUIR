#include <iostream>

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

long long reshenie(long long);

void condition() {
    std::cout << "Составить программу для вычисления значений элементов одномерного динамического массива(вектора) Z = z1, z2,..., zn." << "\n";
    std::cout << "По формуле zk = xk + myk." << "\n";
    std::cout << "Где xk и yk – компоненты одномерных динамических массивов" << "\n";
    std::cout << "X = x1, x2, ..., xn и" << "\n";
    std::cout << "Y = y1, y2, ..., yn." << "\n";
    std::cout << "Размерность массивов n ввести с клавиатуры; величину m вычислить по формулам : " << "\n";
    std::cout << " m =" << "\n";
    std::cout << "{" << "\n";
    std::cout << " k, eсли fabs(sin k) <= 0, 2;" << "\n";
    std::cout << " sqrt(k), eсли 0, 2 <= fabs(sin k) < 0, 9;" << "\n";
    std::cout << " sqrt(sqrt(k)), eсли fabs(sin k) >= 0, 9;" << "\n";
    std::cout << " где k = 0, 1, ..., n." << "\n";
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
        system("cls");

        switch (n)
        {
        case 1:
        {
            condition();
        }
        break;
        case 2:
        {
            int k, m;
            std::cout << "Введите количество элементов:" << "\n";
            k = arrcheck();

            int* Z = new int[k];
            int* X = new int[k];
            int* Y = new int[k];
            std::cout << "Введите элементы X[i]: " << "\n";
            for (int i = 0; i < k; i++)
            {
                X[i] = elcheck();
            }
            for (int i = 0; i < k; i++)
            {
                std::cout << "X[" << i + 1 << "]" << X[i] << "\n";
            }
            std::cout << "\n";
            std::cout << "Введите элементы Y[i]: " << "\n";
            for (int i = 0; i < k; i++)
            {
                Y[i] = elcheck();
            }

            for (int i = 0; i < k; i++)
            {
                std::cout << "Y[" << i + 1 << "]" << Y[i] << "\n";
            }
            std::cout << "\n";

            for (int i = 0; i < k; i++)
            {
                Z[i] = X[i] + reshenie(i) * Y[i];
            }
            std::cout << std::endl;

            for (int i = 0; i < k; i++)
            {
                std::cout << "Z[" << i + 1 << "]" << Z[i] << '\t';
                std::cout << std::endl;
            }
            std::cout << std::endl;

            delete[] Y;
            delete[] X;
            delete[] Z;
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