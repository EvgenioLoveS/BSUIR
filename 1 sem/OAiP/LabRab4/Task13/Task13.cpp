#include<iostream>
#include<cstdio>
#include<iomanip>
#include <fstream>
#define MAX 5000
int** magic;

void Nechetnoye(int n)
{
    int rows = 0, columns = n / 2;
    for (int i = 1; i <= n * n; i++)
    {
        magic[rows][columns] = i;
        rows--;
        columns++;
        if (rows<0 && columns>n - 1)
        {
            rows = rows + 2; columns = columns - 1;
        }
        else if (rows < 0)
        {
            rows = rows + n;
        }
        else if (columns > n - 1)
        {
            columns = columns - n;
        }
        else if (magic[rows][columns] != 0)
        {
            rows = rows + 2; columns = columns - 1;
        }
    }
}

void KratnyChetyry(int n)
{
    for (int i = 1, rows = 0, columns = 0; i <= n * n; i++)
    {
        magic[rows][columns] = i;
        columns++;
        if (columns > n - 1)
        {
            rows++; columns -= n;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 4 == 0 && j % 4 == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    magic[i + k][j + k] = (n * n + 1) - magic[i + k][j + k];
                }
            }
            else if (i % 4 == 3 && j % 4 == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    magic[i - k][j + k] = (n * n + 1) - magic[i - k][j + k];
                }
            }
        }
    }
}
void KratnyDwa(int n)
{
    int n0 = n / 2;
    Nechetnoye(n0);
    for (int i = 0; i < n0; i++)
    {
        for (int j = 0; j < n0; j++)
        {
            magic[i + n0][j + n0] = magic[i][j] + n0 * n0;
            magic[i][j + n0] = magic[i + n0][j + n0] + n0 * n0;
            magic[i + n0][j] = magic[i][j + n0] + n0 * n0;
        }
    }
    int k = (n - 2) / 4;
    for (int i = 0; i < n0; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == n0 / 2)
            {
                std::swap(magic[i][i + j], magic[i + n0][i + j]);
            }
            else
            {
                std::swap(magic[i][j], magic[i + n0][j]);
            }
        }
    }
    for (int i = 0; i < n0; i++)
    {
        for (int j = n0 + n0 / 2; j > n0 + n0 / 2 - (k - 1); j--)
        {
            std::swap(magic[i][j], magic[i + n0][j]);
        }
    }
}

bool prov(int n)
{
    int cnt = n * (n * n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        int sum_row = 0, sum_line = 0;
        for (int j = 0; j < n; j++)
        {
            sum_row += magic[i][j];
            sum_line += magic[j][i];
        }
        if (sum_row != cnt || sum_line != cnt) return false;
    }
    int sum_left = 0, sum_right = 0;
    for (int i = 0; i < n; i++)
    {
        sum_left += magic[i][i];
        sum_right += magic[n - i - 1][i];
    }
    if (sum_left != cnt || sum_right != cnt)
    {
        return false;
    }
    return true;
}

void vivod(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                printf_s("%4d ", magic[i][j]);
                
            }
            else
            {
                printf_s("%4d ", magic[i][j]);

                
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::setlocale(LC_ALL, "rus");
    std::string s;
    std::cout << "Построить магический квадрат." << "\n";
    std::cout << "Порядок квадрата задаётся пользователем." << "\n";
    std::cout << "Максимальный размер магического квадрата не превышает 2 ^ 32 - 1" << "\n";
    std::cout << "Выполнил: Жгутов Евгений" << "\n";
    do
    {
        std::cout << "Введите порядок магического квадрата:" << std::endl;
        int n;
        bool inin;
        do
        {
            std::cin >> n;
            inin = false;
            if (std::cin.peek() != ' ' && std::cin.peek() != '\n' || n < 1)
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                inin = true;
                std::cout << "\nНекорректный ввод!\nПопробуйте ещё раз: \n";
                continue;
            }
            if (n > MAX)
            {

                std::cout << "\nВы ввели слишком большое число\nВведите другое значение\n";
                break;
            }
            if (n == 1)
            {
                std::cout << 1;

            }

            magic = (int**)(malloc(n * sizeof(int*)));
            for (int i = 0; i < n; i++)
                magic[i] = (int*)malloc(n * sizeof(int));

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    magic[i][j] = 0;
                }
            }


            if (n == 2)
            {
                std::cout << "Магического квадрата введенного порядка не существует.\n" << std::endl;
            }
            else if (n & 1)
            {


                Nechetnoye(n);
                if (prov(n))
                {
                    vivod(n);
                    std::cout << std::endl;
                }
            }
            else if (!(n % 4))
            {
                KratnyChetyry(n);
                if (prov(n))
                {
                    vivod(n);
                    std::cout << std::endl;
                }
            }
            else {
                KratnyDwa(n);
                if (prov(n))
                {
                    vivod(n);
                    std::cout << std::endl;
                }
            }
            std::cout << std::endl;
            std::cout << "Для повторения ввода введите любые символы отличные от нуля:\n";
            bool incorrectinput = false;
            do
            {

                std::cin >> s;
                if (std::cin.peek() != ' ' && std::cin.peek() != '\n' || s == "0")
                {
                    if (s == "0") {
                        return 0;
                    }
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    incorrectinput = true;
                    std::cout << "Некорректный ввод!\nПопробуйте ещё раз\n";
                }
            } while (incorrectinput == true);
            for (int i = 0; i < n; i++)
                free(magic[i]);
            free(magic);
        } while (inin == true);
    } while (s != "0");

    return 0;
}