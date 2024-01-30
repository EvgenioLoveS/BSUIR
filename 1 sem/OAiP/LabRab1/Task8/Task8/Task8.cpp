#include <iostream>
using namespace std;
int main() {
    int h1, min1, h2, min2, h, min, result;
    cin >> h1 >> min1;
    cin >> h2 >> min2;
    result = (h2 * 60 + min2) - (h1 * 60 + min1);
    h = result / 60;
    min = result % 60;
    cout << "h=" << h << " min=" << min;
    return 0;
}