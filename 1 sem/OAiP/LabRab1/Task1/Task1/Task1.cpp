#include <iostream>
using namespace std;

int main()
{
    float x, a, b, c, d;
    cout << "Input= " << endl;
    cin >> x;
    a = x * x;
    b = 69 * a + 8;
    c = 23 * a + 32;
    d = x * (c);
    cout << d + b << endl;
    cout << b - d << endl;
    return 0;
}