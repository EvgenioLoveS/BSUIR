#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

void whoami() {
	std::cout << "Выполнил: Жгутов Евгений Дмитриевич" << "\n";
	std::cout << "Группа: 253505" << "\n";
	std::cout << "" << "\n";
}

void condition() {
	std::cout << "Патриций решил устроить праздник и для этого приготовил 240 бочек вина." << "\n";
	std::cout << "Однако к нему пробрался недоброжелатель по имени Пользователь, который подсыпал яд в одну из бочек." << "\n";
	std::cout << "Недоброжелателя тут же поймали, дальнейшая его судьба неизвестна," << "\n";
	std::cout << "но ходят слухи, что он проверяет консольный ввод в аду в качестве наказания, однако сейчас не об этом." << "\n";
	std::cout << "Про яд известно, что человек, который его выпил, умирает в течение 24 часов." << "\n";
	std::cout << "До праздника осталось два дня, то есть 48 часов." << "\n";
	std::cout << "У патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в какой именно бочке яд." << "\n";
	std::cout << "Вы близкий друг Патриция и совершенно не хотите стать одним из тех рабов, что будут проверять вино на наличие яда." << "\n";
	std::cout << "Подойдите к заданию творчески и найдите способ определения отравленной бочки с ядом." << "\n";
}

long long proverka()
{
	long long x;
	while (scanf_s("%lld", &x) != 1 || x < 1 || x > 3 || getchar() != '\n')
	{
		printf("Error\n");
		printf("Ошибка ввода, повторите ввод!!!\n");
		printf("Выберите вариант:\n");
		rewind(stdin);
	}
	return x;
}

long long proverka2()
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


std::string ternary(int intoxicated) {
	std::string str;
	while (intoxicated > 0) {   //o(n)
		str += '0' + intoxicated % 3;
		intoxicated /= 3;
	}
	while (str.size() < 5)  //o(n)
		str += "0";
	reverse(str.begin(), str.end());

	return str;
}

void workplace(std::string* actuality, int** slaves, int daysOfWeek) {
	for (int i = 0; i < 240; i++) {
		for (int j = 0; j < 5; j++) {//o(n^2)
			if (actuality[i][j] == daysOfWeek + '0')
				slaves[j][i] = daysOfWeek;
		}
	}
}
void lifemenu(int daysOfWeek, std::string presentbochka, int* dead, char* reallybochka) {
	for (int i = 0; i < 5; i++) {
		if (daysOfWeek == 1 && presentbochka[i] == '1') {
			std::cout << "Раб " << i + 1 << " умер";
			std::cout << "\n";
			dead[i] = 1;
			reallybochka[i] = '1';
		}
		else if (daysOfWeek == 2 && presentbochka[i] != '0' && dead[i] == 0) {
			std::cout << "Раб " << i + 1 << " умер";
			std::cout << "\n";
			dead[i] = 1;
			reallybochka[i] = '2';
		}
		else if (dead[i] != 0) {
			std::cout << "Раб " << i + 1 << " умер";
			std::cout << "\n";
		}
		else {
			std::cout << "раб " << i + 1 << " жив";
			std::cout << "\n";
		}
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	int resume;

	do
	{

		int n;
		std::cout << "Выберите вариант: " << "\n";
		std::cout << "1 - условие задания " << "\n";
		std::cout << "2 - запуск функции самого задания " << "\n";
		std::cout << "3 - информация о студенте, выполнившим задание. " << "\n";

		n = proverka();

		switch (n)
		{
		case 1:
		{
			condition();
		}
		break;
		case 2:
		{
				int intoxicated = 0;
				std::string intoxicatedstr;
				int realintoxicated = 0;
				std::cout << "Введите номер отравленной бочки: ";
				std::cin >> intoxicatedstr;
				int step = intoxicatedstr.size() - 1;
				for (auto a : intoxicatedstr) {    //o(n)
					if (a < '0' || a>'9') {
						std::cout << "\nНажмите enter,и введите значение!";
						std::cin.ignore(1024, '\n');
						while (std::cin.get() != '\n');
						system("cls");
						main();
					}
					intoxicated += (a - '0') * pow(10, step--);

				}
				int** slaves = new int* [5];
				int deadSlaves[5]{};
				for (int i = 0; i < 5; i++) {  //o(5)
					slaves[i] = new int[240]();
				}
				std::string* actuality = new std::string[240];
				std::string presentbochka = ternary(intoxicated);
				char reallybochka[6] = "00000";
				for (int i = 1; i <= 240; i++)
					actuality[i - 1] = ternary(i);
				lifemenu(0, presentbochka, deadSlaves, reallybochka);
				workplace(actuality, slaves, 1);
				std::cout << "Первый день: \n";
				for (int i = 0; i < 5; i++) {
					std::cout << "\n" << i + 1 << " раб: ";
					for (int j = 1; j <= 240; j++) {    //o(5*240)
						if (slaves[i][j - 1] != 0)
							std::cout << j << " ";
					}
					std::cout << "\n";
				}
				lifemenu(1, presentbochka, deadSlaves, reallybochka);
				workplace(actuality, slaves, 2);
				std::cout << "Второй день: \n";
				for (int i = 0; i < 5; i++) {
					if (deadSlaves[i] == 0) {
						std::cout << "\n" << i + 1 << " раб: ";
						for (int j = 1; j <= 240; j++) {   //o(5*240)
							if (slaves[i][j - 1] == 2)
								std::cout << j << " ";
						}
						std::cout << "\n";
					}
				}
				lifemenu(2, presentbochka, deadSlaves, reallybochka);
				for (int i = 0; i < 5; i++) {  //o(5)
					if (deadSlaves[i] == 0) {
						reallybochka[i] = '0';
					}
				}
				for (int i = 4; i >= 0; i--) {
					realintoxicated += (reallybochka[i] - '0') * pow(3, 4 - i);
				}
				std::cout << "Отравленная бочка: " << realintoxicated;
		}
		break;
		case 3:
		{
			whoami();
		}
		break;
		}

		std::cout << "\nХотите ли вы продолжить?" << "\n";
		std::cout << "1 - Да" << "\n";
		std::cout << "2 - Нет" << "\n";
		resume = proverka2();
		system("cls");

	} while (resume == 1);
	return 0;
}