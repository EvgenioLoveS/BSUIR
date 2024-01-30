#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Input a: " << endl;
    cin >> a;
    cout << "Input b: " << endl;
    cin >> b;
    a = a xor b;
    b = b xor a;
    a = a xor b;
    cout << a << " " << b << endl;
    return 0;
}