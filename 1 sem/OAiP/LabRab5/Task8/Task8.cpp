#include <iostream>


unsigned long long f(unsigned long long n)
{
	unsigned long long x;
	if (n == 0) {
		return 0;
	}
	x = (n + 1) / 2;
	return x * x + f(n / 2);
}

int main()
{
	unsigned long long  kol;
	std::cin >> kol;
	for (int i = 0; i < kol; i++) {
		unsigned long long n;
		std::cin >> n;
		std::cout << f(n);
		std::cout << "\n";
	}
	return 0;
}