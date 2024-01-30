#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    long double x1, y1, x2, y2, x3, y3, a, b, c, h1, h2, h3, m1, m2, m3, bis1, bis2, bis3, alf, bet, gam, alf2, bet2, gam2, alf3, bet3, gam3, r, R, s1, s2, c1, c2, S1, S2, S3, p, P;
    cout << "x1 = " << endl;
    cin >> x1;
    cout << "y1 = " << endl;
    cin >> y1;
    cout << "x2 = " << endl;
    cin >> x2;
    cout << "y2 = " << endl;
    cin >> y2;
    cout << "x3 = " << endl;
    cin >> x3;
    cout << "y3 = " << endl;
    cin >> y3;
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // сторона а
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)); // сторона b
    c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)); // сторона c
    p = (a + b + c) / 2; // полупериметр
    P = (a + b + c); // периметр
    h1 = 2 * sqrt(p * (p - a) * (p - b) * (p - c)) / a; // высота проведенная к стороне a
    h2 = 2 * sqrt(p * (p - a) * (p - b) * (p - c)) / b; // высота проведенная к стороне b
    h3 = 2 * sqrt(p * (p - a) * (p - b) * (p - c)) / c; // высота проведенная к стороне c
    bis1 = (sqrt(b * c * (b + c - a) * (a + c + b))) / (b + c); // биссектриса падающая на a
    bis2 = (sqrt(a * c * (a + c - b) * (b + c + a))) / (a + c); // биссектриса падающая на b
    bis3 = (sqrt(b * a * (b + a - c) * (a + c + b))) / (b + a); // биссектриса падающая на c
    m3 = sqrt(2 * a * a + 2 * b * b - c * c) / 2; // медиана падающая на c
    m2 = sqrt(2 * a * a + 2 * c * c - b * b) / 2; // медиана падающая на b
    m1 = sqrt(2 * b * b + 2 * c * c - a * a) / 2; // медиана падающая на a
    alf = (b * b + c * c - a * a) / (2 * b * c); // угол a 
    alf2 = acos(alf); // угол a в радианах
    bet = (a * a + c * c - b * b) / (2 * a * c); // угол b 
    bet2 = acos(bet); // угол b в радианах
    gam = (b * b + a * a - c * c) / (2 * b * a); // угол c 
    gam2 = acos(gam); // угол c в радианах
    alf3 = (alf2 * 180 / 3.14159265); // угол a в градусах
    bet3 = (bet2 * 180 / 3.14159265); // угол b в градусах
    gam3 = (gam2 * 180 / 3.14159265); // угол c в градусах
    S1 = sqrt(p * (p - a) * (p - b) * (p - c)); // площадь треугольника через Герона
    S2 = (a * h1) / 2; // площадь треугольника через Высоту
    S3 = (a * c * sin(alf)) / 2; // площадь треугольника через угол между двух прилежащих сторон
    r = S1 / p; // радиус вписанной окружности
    R = (a * b * c) / (4 * S1); // радиус описанной окружности
    c1 = 2 * 3.14159265 * r; // длинна вписанной окружности
    s1 = 3.14159265 * r * r; // площадь вписанной окружности
    c2 = 2 * 3.14159265 * R; // длинна описанной окружности
    s2 = 3.14159265 * R * R; // площадь описанной окружности 
    cout << setprecision(5) << "Storona a= " << a << endl;
    cout << setprecision(5) << "Storona b= " << b << endl;
    cout << setprecision(5) << "Storona c= " << c << endl;
    cout << setprecision(5) << "Visota1= " << h1 << endl;
    cout << setprecision(5) << "Visota2= " << h2 << endl;
    cout << setprecision(5) << "Visota3= " << h3 << endl;
    cout << setprecision(5) << "mediana1= " << m1 << endl;
    cout << setprecision(5) << "mediana2= " << m2 << endl;
    cout << setprecision(5) << "mediana3= " << m3 << endl;
    cout << setprecision(5) << "Bisektrisa1= " << bis1 << endl;
    cout << setprecision(5) << "Bisektrisa2= " << bis2 << endl;
    cout << setprecision(5) << "Bisektrisa3= " << bis3 << endl;
    cout << setprecision(5) << bet2 << " " << setprecision(5) << bet3 << endl;
    cout << setprecision(5) << gam2 << " " << setprecision(5) << gam3 << endl;
    cout << setprecision(5) << alf2 << " " << setprecision(5) << alf3 << endl;
    cout << setprecision(5) << "radiys Opacanoy= " << R << endl;
    cout << setprecision(5) << "radiys vpisanoy= " << r << endl;
    cout << setprecision(5) << "dlina vpisanoy= " << c1 << endl;
    cout << setprecision(5) << "s vpisanoy= " << s1 << endl;
    cout << setprecision(5) << "dlina opisanoy= " << c2 << endl;
    cout << setprecision(5) << "s opisanoy= " << s2 << endl;
    cout << setprecision(5) << "Square of triangle = " << S1 << " or " << setprecision(5) << S2 << " or " << setprecision(0) << S3 << endl;
    cout << setprecision(5) << "Perimetr= " << P << endl;
    return 0;
}