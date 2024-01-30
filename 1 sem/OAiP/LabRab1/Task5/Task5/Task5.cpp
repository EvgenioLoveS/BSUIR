#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    long long d;
    double a1, a100, a70, result;
    cin >> a1;
    cin >> a100;
    d = (a100 - a1) / 99;
    a70 = a1 + d * 69;
    cout << d << endl;
    result = ((a1 + a70) / 2) * 70;
    cout << setprecision(10) << result;
    return 0;
}