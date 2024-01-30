#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    long double v0;
    long double t;
    long double a;
    long double s;
    cin >> a >> t >> v0;
    s = v0 * t + (a * t * t / 2);
    cout << setprecision(20) << s;
    return 0;
}