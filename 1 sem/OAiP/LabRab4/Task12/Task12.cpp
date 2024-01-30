#include <iostream>
#include <cmath>

int main()
{
    long long int nachchislo, celiykorenb, sledsqrt, levoe, pravoe, levoespovom, pravoespovom, vygly, n, m;
    std::cin >> nachchislo;
    celiykorenb = sqrt(nachchislo);
    levoe = celiykorenb;
    pravoe = levoe + 1;
    levoespovom = pow(levoe, 2) + 1;
    pravoespovom = pow(pravoe, 2);
    vygly = (long long int)powl(pravoe - 0.5, 2) + 1;
    if (nachchislo <= 0)
    {
        return 0;
    }
    else if (nachchislo == pow((int)sqrt(nachchislo), 2))
    {
        std::cout << levoe - 1 << " ";//номер строки
        std::cout << 0;//номер столбца
    }
    else if (nachchislo == levoespovom)
    {
        std::cout << 0 << " "; //номер строки
        std::cout << pravoe - 1; //номер столбца
    }
    else if (nachchislo < vygly)
    {
        std::cout << nachchislo - levoespovom << " ";// номер строки
        std::cout << pravoe - 1;//номер столбца
    }
    else if (nachchislo > vygly)
    {
        std::cout << pravoe - 1 << " ";//номер строки
        std::cout << pravoe - (nachchislo - vygly) - 1;//номер столбца
    }
    else if (nachchislo = vygly)
    {
        std::cout << pravoe - 1 << " "; //номер строки
        std::cout << pravoe - 1;//номер столбца
    }
    return 0;
}