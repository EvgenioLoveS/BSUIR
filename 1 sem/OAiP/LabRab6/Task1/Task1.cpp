#include <iostream>

long long proverkak()
{
	long long x;
	while (scanf_s("%lld", &x) != 1 || x < 0 || x > INT_MAX || getchar() != '\n')
	{
		printf("Error\n");
		rewind(stdin);
	}
	return x;
}

long long proverka()
{
	long long x;
	while (scanf_s("%lld", &x) != 1 || x < 1 || x > 2 || getchar() != '\n')
	{
		printf("Ошибка ввода, повторите ввод!!!\n");
		printf("Хотите ли вы продолжить?\n");
		rewind(stdin);
	}
	return x;
}

void task1(char* str, long long pos) {

	long long k = 0;

	if (str[pos] == ' ') {
		pos--;
	}

	for (int i = pos; i >= 0; i--) {
		if (str[i] == ' ') {
			k++;
		}
	}

	std::cout << k + 1;
}
int main() {
	setlocale(LC_ALL, "");
	int resume;


	do {
		long long pos;
		char str[81];
		std::cout << "Введите строку: " << "\n";
		for (int i = 0; i < 80; i++) {
			str[i] = getchar();
			if (str[i] == '\n') {
				break;
			}
		}
		std::cout << "Введите k-ю позицию: " << "\n";
		pos = proverkak();
		task1(str, pos);

		std::cout << "\nХотите ли вы продолжить?" << "\n";
		std::cout << "1 - Да" << "\n";
		std::cout << "2 - Нет" << "\n";
		resume = proverka();
		system("cls");

	} while (resume == 1);

	return 0;
}