#include <iostream>
#include <cmath>


int main()
{
    long double a, b, c, p, q, Q, t1, t2, x1, x2, x3, D, D1, D2, fi;
    const long double PI = acos(-1);

    int number;
    std::cout << "enter the equation number" << "\n";
    std::cin >> number;

    switch (number)
    {
    case 1:

        std::cout << "Input a, b, c= " << "\n";
        std::cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
        {
            std::cout << "any value of x" << "\n"; // любое значение x
            return 0;
        }

        if (a == 0) {
            if (a == 0 && b != 0 && c != 0) {
                if (a == 0 && b > 0 && c > 0) {
                    std::cout << "No roots";
                    return 0;
                }
                else if (a == 0 && b > 0 && c < 0) {
                    x1 = -sqrt(-c / b);
                    x2 = sqrt(-c / b);
                    std::cout << "x1 = " << x1 << " " << "x2 = " << x2 << '\n';
                    return 0;
                }
                else if (a == 0 && b < 0 && c < 0) {
                    std::cout << "No roots";
                    return 0;
                }
                else if (a == 0 && b < 0 && c > 0) {
                    x1 = sqrt(c / -b);
                    x2 = -sqrt(c / -b);
                    std::cout << "x1 = " << x1 << " " << "x2 = " << x2 << '\n';
                    return 0;
                }

            }
        }

        if (a != 0 && b == 0 && c == 0)
        {
            std::cout << 0 << "\n";
            return 0;
        }

        if (a == 0 && b > 0 && c == 0)
        {
            std::cout << 0;
            return 0;
        }

        if (a == 0 && b == 0 && c > 0)
        {
            std::cout << "Pystoe mnojestvo";
            return 0;
        }

        if (a == 0 && b < 0 && c == 0)
        {
            std::cout << 0;
            return 0;
        }

        if (a == 0 && b == 0 && c < 0)
        {
            std::cout << "Pystoe mnojestvo";
            return 0;
        }

        D = b * b - 4 * a * c;

        if (D < 0)
        {
            std::cout << "there are no valid roots" << "\n"; // нет действительных корней
            return 0;
        }

        if (D == 0)
        {
            x1 = (-b) / (2 * a);
            std::cout << x1 << "\n";
            return 0;
        }

        t1 = (-b - sqrt(D)) / (2 * a);

        t2 = (-b + sqrt(D)) / (2 * a);


        if (t1 < 0 && t2 < 0)
        {
            std::cout << "there are no solutions" << "\n"; // решений нет
            return 0;
        }

        if (!(t1 < 0))
        {
            std::cout << sqrt(t1) << " " << -sqrt(t1) << "\n";
        }

        if (!(t2 < 0))
        {
            std::cout << sqrt(t2) << " " << -sqrt(t2) << "\n";
        }
        break;
    case 2:

        std::cout << "Input a, b, c= " << "\n";
        std::cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
        {
            std::cout << "any value of x" << "\n"; // любое значение x
            return 0;
        }

        if (a != 0 && b == 0 && c == 0) {
            std::cout << "there are no valid roots";
            return 0;
        }
        if (a == 0 && b != 0 && c == 0) {
            std::cout << -b;
            return 0;
        }
        if (a == 0 && b == 0 && c != 0) {
            std::cout << 0;
            return 0;
        }

        if (a == 0 && b != 0 && c != 0) {
            D = c * c - 4 * b * b;
            if (D < 0) {
                std::cout << "x1 = " << 0;
                return 0;
            }

            else if (D > 0) {
                x1 = 0;
                x2 = (-c - sqrt(D)) / (2 * b);
                x3 = (-c + sqrt(D)) / (2 * b);
                std::cout << "x1 = " << x1 << '\n' << "x2 = " << x2 << " " << "x3 = " << x3 << "\n";
                return 0;
            }

            else if (D == 0) {
                x1 = 0;
                x2 = -c / (2 * b);
                std::cout << "x1 = " << x1 << '\n' << "x2 = " << x2 << '\n';
                return 0;
            }
        }

        D = b * b - 4 * a * (c - 2 * a);
        if (D < 0)
        {
            std::cout << "there are no solutions" << "\n"; // решений нет
            return 0;
        }

        t1 = (-b - sqrt(D)) / (2 * a);

        t2 = (-b + sqrt(D)) / (2 * a);

        D1 = t1 * t1 - 4;

        if (!(D1 < 0))
        {
            x1 = (t1 - sqrt(D1)) / 2;
            x2 = (t1 + sqrt(D1)) / 2;
            std::cout << x1 << " " << x2 << "\n";
        }

        D2 = t2 * t2 - 4;

        if (!(D2 < 0))
        {
            x1 = (t2 - sqrt(D2)) / 2;
            x2 = (t2 + sqrt(D2)) / 2;
            std::cout << x1 << " " << x2 << "\n";
        }

        if (D == 0) {
            t1 = -b / (2 * a);
            D1 = t1 * t1 - 4 * 1 * 1;
            if (D1 < 0) {
                std::cout << "No roots" << '\n';
                return 0;
            }
            else if (D1 == 0) {

                x1 = t1 / (2 * 1);
                std::cout << "x1 = " << x1 << '\n';
                return 0;
            }
            else if (D1 > 0) {
                x1 = (t1 - sqrt(D1)) / (2 * 1);
                x2 = (t1 + sqrt(D1)) / (2 * 1);
                std::cout << "x1 = " << x1 << '\n';
                std::cout << "x2 = " << x2 << '\n';
                return 0;
            }
        }
        break;

    case 3:
        std::cout << "Input p, q =" << "\n";
        std::cin >> p >> q;

        Q = powl(p / 3, 3) + powl(q / 2, 2);

        if (Q < 0)
        {
            fi = acos(-(q / 2) * powl(3 / (-p), 3.0 / 2.0));
            x1 = 2 * sqrtl(-p / 3) * cos(fi / 3);
            x2 = 2 * sqrtl(-p / 3) * cos(fi / 3 + 2 * PI / 3);
            x3 = 2 * sqrtl(-p / 3) * cos(fi / 3 - 2 * PI / 3);

            std::cout << x1 << " " << x2 << " " << x3 << "\n";
        }

        else
        {
            x1 = cbrt(-q / 2 + sqrtl(Q)) + cbrt(-q / 2 - sqrtl(Q));

            std::cout << x1 << "\n";
        }
        break;
    }
}