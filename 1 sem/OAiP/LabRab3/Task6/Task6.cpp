#include <iostream>
#include <cmath>

double f(double X)
{
    return sinh(X) + acos(X) - 1.5;
}

int main()
{
    int part;
    double x, value, min_value, step, root;

    std::cout << "part: " << std::endl; // на сколько частей разделить область поиска корней 
    std::cin >> part;

    root = x = 0.; // первый корень
    min_value = value = fabs(f(x));

    step = (1. - x) / (part - 1); // расчет шага

    std::cout << "step: " << step << std::endl; // чему равен шаг

    std::cout << "#1" << " x=" << x << " value:" << value << std::endl;

    for (int i = 2; i <= part; i++)
    {
        value = fabs(f(x));
        x += step;

        if (value < min_value)
        {

            min_value = value;
            root = x;

        }

        std::cout << "#" << i << " x=" << x << " value:" << value << std::endl;

    }

    std::cout << "root: " << root << "\n" << "min_value: " << min_value << std::endl;

    return 0;
}