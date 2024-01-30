#include <iostream>

int main()
{

	double a, b, c, Y;
	int N;
	std::cin >> N;
	std::cout << "Enter a, b, c " << "\n";
	std::cin >> a >> b >> c;

	switch (N)
	{
	case 2:
		Y = (b * c - a * a);
		break;
	case 56:
		Y = b * c;
		break;
	case 7:
		Y = a * a * a * a * a * a * a + c;
		break;
	case 3:
		Y = a - b * c;
		break;
	default:
		Y = (a + b) * (a + b) * (a + b);
	}
	std::cout << Y << "\n";
	return 0;
}