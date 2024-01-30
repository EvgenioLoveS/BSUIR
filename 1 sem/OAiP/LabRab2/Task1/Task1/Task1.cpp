#include <iostream>
int main()
{
    int X, Y;

    std::cin >> X >> Y;

    if (X == 0 && Y == 0)
    {
        std::cout << "ERROR";
    }

    else if (X == 0 || Y == 0)
    {
        std::cout << "YES";
    }

    else if (X % Y == 0 || Y % X == 0)
    {
        std::cout << "YES";
    }

    else if (X % Y != 0 || Y % X != 0)
    {
        std::cout << "NO";
    }

    return 0;
}