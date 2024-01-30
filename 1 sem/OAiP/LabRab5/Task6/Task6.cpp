#include <iostream>


int F(int n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	if (n == 0) {
		return 0;
	}
	else {
		return F(n / 10);
	}
}
int S(int p, int q) {
	int sum = 0;
	for (int i = p; i <= q; i++) {
		sum += F(i);
	}
	return sum;
}
int main() {
	int p = 0, q = 0;
	bool firstTime = true;
	do {
		if (!firstTime) {
			std::cout << S(p, q) << std::endl;
		}
		else {
			firstTime = false;
		}
		std::cin >> p >> q;

	} while (p >= 0 && q >= 0);
	return 0;
}