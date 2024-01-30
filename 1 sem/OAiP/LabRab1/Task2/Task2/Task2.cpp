#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    long double g = 9.80;
    long double t;
    long double h;
    cin >> h;
    t = sqrt(2.0 * h / g);
    cout << setprecision(9) << t;
    return 0;
}