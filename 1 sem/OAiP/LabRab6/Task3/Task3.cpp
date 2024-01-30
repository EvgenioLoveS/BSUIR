#include <iostream>

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

void task3(char* str) {

	long long lenght;
	lenght = strlen(str);
	long long sum = 0;
	int sig = 1;
	for (int i = 0; i < lenght - 1; i++) {
		if (isdigit(str[i])) {
			sum = sum + ((str[i] - '0') * sig);
			sig = sig * (-1);
		}
	}
	std::cout << "Сумаа: " << sum;

}

int main() {
	setlocale(LC_ALL, "");
	long long resume;

	do {
		char str[255];
		fgets(str, 255, stdin);
		task3(str);
		std::cout << "\nХотите ли вы продолжить?" << "\n";
		std::cout << "1 - Да" << "\n";
		std::cout << "2 - Нет" << "\n";
		resume = proverka();
		system("cls");

	} while (resume == 1);

	return 0;
}