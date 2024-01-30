#include <iostream>
#include <string>

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

void whoami() {
	std::cout << "Выполнил: Жгутов Евгений Дмитриевич" << "\n";
	std::cout << "Группа: 253505" << "\n";
	std::cout << "" << "\n";
}

void condition() {
	std::cout << "Пользователь вводит основание системы счисления." << "\n";
	std::cout << "Осуществить сложение и вычитание чисел в заданной системе счисления." << "\n";
	std::cout << "В другую систему счисления не переводить." << "\n";
	std::cout << "В системах счисления больших десятичной использовать буквы по аналогии с шестнадцатеричной системой." << "\n";
	std::cout << "Разработать функции для выполнения операции сложения и функции для выполнения операции вычитания." << "\n";
	std::cout << "Предусмотреть ввод положительных и отрицательных чисел." << "\n";
}
using namespace std;

string amount(string first_of_number, string second_of_number, int base) {
	string fl;
	char letters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int ostatok = 0;

	for (int i = first_of_number.size() - 1; i >= 0; i--) {	//o(n)
		int ai = 0, bi = 0;
		if (first_of_number[i] < '9' + 1)
			ai = first_of_number[i] - '0';
		else
			ai = 10 + first_of_number[i] - 'A';
		if (second_of_number[i] < '9' + 1)
			bi = second_of_number[i] - '0';
		else
			bi = 10 + second_of_number[i] - 'A';
		int n = ai + bi + ostatok;
		if (ostatok != 0) ostatok--;
		if (n > base - 1) {
			fl += letters[n - base];
			ostatok++;
		}
		else
			ostatok > 0 ? fl += letters[n] + ostatok-- : fl += letters[n];

	}
	if (ostatok > 0)
		fl += to_string(ostatok);
	string str;
	for (int i = fl.size() - 1; i >= 0; i--) {   //o(n)
		str += fl[i];
	}
	return str;
}
string difference(string first_of_number, string second_of_number, int base) {
	string fl;
	char letters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int ostatok = 0;
	bool fs = false;
	string max_of_number;
	string min_of_number;
	max_of_number = first_of_number;
	min_of_number = second_of_number;
	for (int i = 0; i < first_of_number.size(); i++) {    //o(n)
		int ai = 0;
		int bi = 0;
		if (first_of_number[i] < '9' + 1)
			ai = first_of_number[i] - '0';
		else
			ai = 10 + first_of_number[i] - 'A';
		if (second_of_number[i] < '9' + 1)
			bi = second_of_number[i] - '0';
		else
			bi = 10 + second_of_number[i] - 'A';
		if (first_of_number[i] > second_of_number[i]) {
			max_of_number = first_of_number;
			min_of_number = second_of_number;
			break;
		}
		else if (first_of_number[i] < second_of_number[i]) {
			max_of_number = second_of_number; fs = true;
			min_of_number = first_of_number;
			break;
		}
	}

	for (int i = first_of_number.size() - 1; i >= 0; i--) {   //o(n)
		int ai = 0;
		int bi = 0;
		if (max_of_number[i] < '9' + 1)
			ai = max_of_number[i] - '0';
		else
			ai = 10 + max_of_number[i] - 'A';
		if (min_of_number[i] < '9' + 1)
			bi = min_of_number[i] - '0';
		else
			bi = 10 + min_of_number[i] - 'A';
		int n = ai - bi + ostatok;
		if (ostatok < 0) ostatok++;
		if (n < 0) {
			fl += letters[base + n];
			if (ostatok == 0) ostatok--;
		}
		else
			ostatok < 0 ? fl += letters[n] + ostatok++ : fl += letters[n];
	}
	string str;
	for (int i = fl.size() - 1; i >= 0; i--) {     //o(n)
		str += fl[i];
	}
	int y = 0;
	while (str.size() != 1)       //o(n)    
	{
		if (str[0] != '0')
			break;
		else
			str.erase(str.begin(), str.begin() + 1);
	}
	if (fs) str = '-' + str;
	return str;
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
			char letters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string inputbase;
			bool RH = false;
			bool LF = false;
			int base = 0;
			int step = 0;
			cout << "Введите основание системы счисления: ";
			cin >> inputbase;
			step = inputbase.size() - 1;
			for (int i = 0; i < inputbase.size(); i++) { //o(n)
				base += (inputbase[i] - '0') * pow(10, step--);
				if (inputbase[i] < '0' || inputbase[i] > '9' || step > 1 || base > 36) {
					cout << "Неверный ввод" << "\n";
					cout << "Нажмите любую клавишу для продолжения!";
					cin.ignore(1024, '\n');
					while (cin.get() != '\n');
					system("cls");
					main();
				}

			}
			string first_of_number;
			string second_of_number;
			int minuses = 0;
			cout << "Введите первое число в ";
			cout << base;
			cout << "-й системе счисления: " << "\n";
			cin >> first_of_number;
			/*for (int i = 0; i < first_of_number.size(); i++) {
				for (int j = 0; j < strlen(letters); j++) {//o(n^2)
					if ((tolower(first_of_number[i]) == tolower(letters[j]) && base < j + 1) || ((i != 0 || first_of_number[i] != '-') && j == strlen(letters) - 1)) {
						cout << "Неверный ввод" << "\n";
						cout << "Нажмите любую клавишу для продолжения!";
						cin.ignore(1024, '\n');
						while (cin.get() != '\n');
						system("cls");
						main();
					}
					if ((tolower(first_of_number[i]) == tolower(letters[j])))
						break;
				}
				first_of_number[i] = toupper(first_of_number[i]);
			}*/

			cout << "Введите второе число в ";
			cout << base;
			cout << "-й системе счисления: " << "\n";
			cin >> second_of_number;
			/*for (int i = 0; i < second_of_number.size(); i++) {
				for (int j = 0; j < strlen(letters); j++) {      //o(n^2)
					if ((tolower(second_of_number[i]) == tolower(letters[j]) && base < j + 1) || ((i != 0 || second_of_number[i] != '-') && j == strlen(letters) - 1)) {
						cout << "Неверный ввод" << "\n";
						cout << "Нажмите любую клавишу для продолжения!";
						cin.ignore(1024, '\n');
						while (cin.get() != '\n');
						system("cls");
						main();
					}
					if ((tolower(second_of_number[i]) == tolower(letters[j])))
						break;

				}
				second_of_number[i] = toupper(second_of_number[i]);
			}*/
			if (first_of_number[0] == '-') {
				RH = !RH;
				minuses++;
				first_of_number.erase(first_of_number.begin(), first_of_number.begin() + 1);
			}
			if (second_of_number[0] == '-') {
				LF = !LF;
				minuses++;
				second_of_number.erase(second_of_number.begin(), second_of_number.begin() + 1);
			}
			while (first_of_number.size() != second_of_number.size()) {
				if (first_of_number.size() > second_of_number.size())
					second_of_number = "0" + second_of_number;
				else
					first_of_number = "0" + first_of_number;
			}
			switch (minuses)
			{
			case 0:
				cout << "Сумма двух чисел: " << amount(first_of_number, second_of_number, base) << "\n";
				cout << "Разность двух чисел: " << difference(first_of_number, second_of_number, base) << "\n";
				break;
			case 1:
				if (LF) {
					cout << "Сумма двух чисел: " << difference(first_of_number, second_of_number, base) << "\n";
					cout << "Substraction: " << amount(first_of_number, second_of_number, base) << "\n";
				}
				else {
					cout << "Сумма двух чисел: " << difference(second_of_number, first_of_number, base) << "\n";
					cout << "Разность двух чисел: -" << amount(first_of_number, second_of_number, base) << "\n";
				}
				break;
			case 2:
				cout << "Сумма двух чисел: -" << amount(first_of_number, second_of_number, base) << "\n";
				cout << "Разность двух чисел: " << difference(second_of_number, first_of_number, base) << "\n";
				break;
			default:
				break;
			}
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
