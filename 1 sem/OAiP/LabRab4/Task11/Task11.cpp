#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << "На вход подаётся поле для игры в сапёр размером n*m символов." << "\n";
    std::cout << "Где символ '.' означает пустое место, а символ '*' - бомбу." << "\n";
    std::cout << "Требуется дополнить это поле числами, как в оригинальной игре." << "\n";
    std::cout << "Выполнил: Жгутов Евгений" << "\n";
    while (true) {
        char** a;
        char inp;
        int i, j, n, m, vrem = 0;
        std::string s;
        std::cout << "Введите n: " << "\n";
        std::cin >> n;
        if (std::cin.peek() != ' ' && std::cin.peek() != '\n' || n < 1)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nНекорректный ввод. Попробуйте ещё раз. ";
            continue;
        }
        std::cout << "Введите m: " << "\n";
        std::cin >> m;
        if (std::cin.peek() != ' ' && std::cin.peek() != '\n' || n < 1)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nНекорректный ввод. Попробуйте ещё раз. ";
            continue;
        }
        if ((n == 0) || (m == 0)) {
            std::cout << "\nНекорректный ввод. Попробуйте ещё раз. ";
            continue;
        }
        a = (char**)(malloc((n + 2) * sizeof(char*)));
        for (int i = 0; i < (n + 2); i++)
            a[i] = (char*)malloc((m + 2) * sizeof(char));
        n++;
        m++;


        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                std::cin >> a[i][j];
                if ((a[i][j] != '*') && (a[i][j] != '.')) vrem++;
                if (vrem > 0) break;
            }
            if (vrem > 0) break;
        }
        if (vrem > 0) {
            std::cout << "Неверный ввод. Повторите попытку.\n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            for (int i = 0; i < (n + 1); i++) {
                free(a[i]);
            }
            free(a);
            continue;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j] == '*') {
                    for (int o = (i - 1); o < (i + 2); o++) {
                        for (int g = (j - 1); g < (j + 2); g++) {
                            if ((a[o][g] != '*') && (a[o][g] != '.')) {
                                a[o][g] = (int)(a[o][g] - '0') + ('0' + 1);
                            }
                            else if (a[o][g] == '.') a[o][g] = '1';
                        }
                    }
                }
            }
        }
        std::cout << "\n";
        for (i = 1; i < n; i++)
        {
            for (j = 1; j < m; j++)
            {
                std::cout << a[i][j] << " ";
            }
            std::cout << "\n";
        }
        for (int i = 0; i < (n + 1); i++) free(a[i]);
        free(a);
        std::cout << "Для завершения программы введите 0. Для повторного ввода введите что угодно кроме нуля. \n";
        std::cin >> s;
        if (s.size() == 1) {
            if (s == "0") return 0;
        }
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}