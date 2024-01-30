#include <iostream>
#include <string>

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

std::string task(std::string str) {

	for (int i = 0; i < str.size(); i++) {
		// th >> z
		if ((str[i] == 't') || (str[i] == 'T')) {
			if (str[i + 1] == 'h' || str[i + 1] == 'H') {
				if (str[i] == 't') {
					str[i] = 'z';
					str.erase(i + 1, 1);
				}
				else {
					str[i] = 'Z';
					str.erase(i + 1, 1);
				}
			}
		}
		// ee >> i
		if ((str[i] == 'e') || (str[i] == 'E')) {
			if (str[i + 1] == 'e' || str[i + 1] == 'E') {
				if (str[i] == 'e') {
					str[i] = 'i';
					str.erase(i + 1, 1);
				}
				else {
					str[i] = 'I';
					str.erase(i + 1, 1);
				}
			}
		}
		// oo >> u
		if ((str[i] == 'o') || (str[i] == 'O')) {
			if (str[i + 1] == 'o' || str[i + 1] == 'O') {
				if (str[i] == 'o') {
					str[i] = 'u';
					str.erase(i + 1, 1);
				}
				else {
					str[i] = 'U';
					str.erase(i + 1, 1);
				}
			}
		}
		// you >> u
		if ((str[i] == 'y') || (str[i] == 'Y')) {
			if (((str[i + 1] == 'o') || (str[i + 1] == 'O')) && ((str[i + 2] == 'u') || (str[i + 2] == 'U'))) {
				if (str[i] == 'y') {
					str[i] = 'u';
					str.erase(i + 1, 2);
				}
				else {
					str[i] = 'U';
					str.erase(i + 1, 2);
				}
			}
		}
		// ph >> f
		if ((str[i] == 'p') || (str[i] == 'P')) {
			if (str[i + 1] == 'h' || str[i + 1] == 'H') {
				if (str[i] == 'p') {
					str[i] = 'f';

				}
				else {
					str[i] = 'F';
				}
				str.erase(i + 1, 1);
			}
		}
		// w >> v
		if (str[i] == 'w' || str[i] == 'W') {
			if (str[i] == 'w') {
				str[i] = 'v';
			}
			else {
				str[i] = 'V';
			}
		}
		// xs >> k
		if ((str[i] == 'x') || (str[i] == 'X')) {
			if (str[i] == 'x') {
				str[i] = 'k';
				str.insert(i + 1, "s");
			}
			else {
				str[i] = 'K';
				str.insert(i + 1, "s");
			}
			str[i + 1] = 's';
		}
		// qu >> kv
		if ((str[i] == 'q') || (str[i] == 'Q')) {
			if (str[i + 1] == 'u') {
				if (str[i] == 'q') str[i] = 'k';
				else str[i] = 'K';
				str[i + 1] = 'v';
			}
			else if (str[i] == 'q') str[i] = 'k';
			else str[i] = 'K';
		}
		// ce,ci,cy >> se,si,sy, c >> k
		if ((str[i] == 'c') || (str[i] == 'C')) {
			if (str[i + 1] == 'e') {
				if (str[i] == 'c') {
					str[i] = 's';
				}
				else {
					str[i] = 'S';
				}
				str[i + 1] = 'e';
			}
			else if (str[i + 1] == 'i') {
				if (str[i] == 'c') str[i] = 's';
				else str[i] = 'S';
				str[i + 1] = 'i';
			}
			else if (str[i + 1] == 'y') {
				if (str[i] == 'c') str[i] = 's';
				else str[i] = 'S';
				str[i + 1] = 'y';
			}
			else if (str[i] == 'c') str[i] = 'k';
			else str[i] = 'K';
		}
		if ((str[i] == 'c') || (str[i] == 'C')) {
			if (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') {
				str[i] = 's';
			}
			else {
				str[i] = 'k';
			}
		}
		if (tolower(str[i]) == tolower(str[i + 1]) && (str[i] == 'k' || str[i] == 'r' || str[i] == 't' || str[i] == 'p' || str[i] == 's' || str[i] == 'd' || str[i] == 'f' || str[i] == 'g' || str[i] == 'h' || str[i] == 'j' || str[i] == 'l' || str[i] == 'z' || str[i] == 'v' || str[i] == 'b' || str[i] == 'n' || str[i] == 'm'))
		{
			str.erase(i + 1, 1);
		}

		if (toupper(str[i]) == toupper(str[i + 1]) && (str[i] == 'K' || str[i] == 'R' || str[i] == 'T' || str[i] == 'P' || str[i] == 'S' || str[i] == 'D' || str[i] == 'F' || str[i] == 'G' || str[i] == 'H' || str[i] == 'J' || str[i] == 'L' || str[i] == 'Z' || str[i] == 'V' || str[i] == 'B' || str[i] == 'N' || str[i] == 'M'))
		{
			str.erase(i + 1, 1);
		}

	}

	return str;

}
int main() {

	setlocale(0, "");
	long long resume;
	do {
		std::string str;
		std::string str2;
		std::cout << "Введите строку: " << "\n";
		std::getline(std::cin, str);
		do
		{
			str2 = str;
			str = task(str);
		} while (str != str2);
		std::cout << str;
		std::cout << "\nХотите ли вы продолжить?" << "\n";
		std::cout << "1 - Да" << "\n";
		std::cout << "2 - Нет" << "\n";
		resume = proverka();
		system("cls");

	} while (resume == 1);
}