#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    long double b1, q, result;
    cin >> b1;
    q = 1.0 / 1001.0;
    result = b1 / (1 - q);
    cout << setprecision(8) << result;
    return 0;
}