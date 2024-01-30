#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <ranges>
#include <stdio.h>
#include "Header.h"

typedef union Shop {
	int shopNum;
};

typedef union Ceh {
	int count;
};

typedef class Enterprise {
public:
	Shop products;
	Ceh ceh;
	char title[60];
};

void initProducts(Enterprise& products)
{
	printf_s("Введите наименование продукции: ");
	strCheck(products.title);
	std::cout << "Введите количество выпущенной продукции: ";
	products.ceh.count = intCheck(products.ceh.count, 1, 100000);
	std::cout << "Введите номер цеха: ";
	products.products.shopNum = intCheck(products.products.shopNum, 1, 100000);
}

bool productsCheck(Enterprise products1, Enterprise products2, int choice)
{
	switch (choice)
	{
	case 1:
	{
		if (arrCheck(products1.title, products2.title))
		{
			return true;
		}
		break;
	}
	case 2:
	{
		if (products1.ceh.count == products2.ceh.count)
		{
			return true;
		}
	}
	case 3:
	{
		if (products1.products.shopNum == products2.products.shopNum)
		{
			return true;
		}
	}
	default:
	{
		return false;
	}
	}
	return false;
}

void sheykerSort(Enterprise* arr, int length) {
	int max = length;
	int isFind = -1;
	for (int i = 0; i < length; i++)
	{
		int max_i = i;
		for (int j = i; j < length; j++)
		{
			if (arr[j].ceh.count > arr[max_i].ceh.count)
			{
				max_i = j;
			}
		}
		std::swap(arr[i], arr[max_i]);
	}
}

void saveInFile(std::fstream& file, Enterprise products)
{
	file.open("file.bin", std::ios::binary | std::ios::app);  //ios::binary нужен для того, чтобы данные сохранялись как есть, без какого-либо форматирования
	file.write((char*)&products, sizeof(Enterprise));				//при записи структуры в бинарный файл можно записать всю структуру целиком и сразу.
	file.close();													//В режиме app данные записываются строго в конец файла, даже если до этого указатель смещался функцией seek, при записи он будет автоматически смещен в конец.
	///В режиме ate указатель утанавливается в конец файла при открытии, но записывать можно в любую часть файла, смещая указатель функцией seek
}

void firstProduct(std::fstream& file, int& size)
{
	while (1)
	{
		int localChoice = 0;
		printf("Введите количество записей:");
		localChoice = intCheck(localChoice, 1, 500);
		for (int i = 0; i < localChoice; i++)
		{
			Enterprise products;
			initProducts(products);
			saveInFile(file, products);
		}
		size += localChoice;
		break;
	}
}

void secondProduct(std::fstream& file, int& size)
{
	printf("Введите вашу структуру\n");
	while (1)
	{
		printf("Хотите продолжить? \n");
		printf("1 - Да   2 - Нет\n");
		int but = 0;
		but = intCheck(but, 1, 2);
		if (but == 1) {
			Enterprise products;
			initProducts(products);
			saveInFile(file, products);
			size++;
		}
		else if (but == 2)
		{
			break;
		}
	}
}

void thirdProduct(std::fstream& file, int& size)
{
	system("cls");
	printf("Задайте параметры продукции:\n");
	printf("1 - Ввести наименование продукта\n");
	printf("2 - Ввести количество продукта\n");
	printf("3 - Ввести номер цеха\n");
	int localChoice = 0;
	localChoice = intCheck(localChoice, 1, 3);
	Enterprise predetproducts{ '\0',0,0 };
	if (localChoice == 1)
	{
		printf("\nВведите название продукта:\n");
		strCheck(predetproducts.title);
	}
	if (localChoice == 2)
	{
		printf("\nВведите количество товара:(1-500):\n");
		predetproducts.ceh.count = intCheck(predetproducts.ceh.count, 1, 500);

	}
	if (localChoice == 3)
	{
		printf("\nВведите номер цеха(1-500);\n");
		predetproducts.products.shopNum = intCheck(predetproducts.products.shopNum, 1, 500);

	}
	system("cls");
	printf("Введите вашу структуру\n");
	while (1) {
		Enterprise products;
		do
		{
			initProducts(products);
			saveInFile(file, products);
			size++;
		} while (!productsCheck(predetproducts, products, localChoice));
		break;
	}
}

void printProducts(Enterprise products)
{
	printf("Наименование вашего продукта: \n");
	std::cout << products.title;
	printf("\n");
	printf("Количество вашего продукта: \n");
	std::cout << products.ceh.count;
	printf("\n");
	printf("Номер вашего цеха: \n");
	std::cout << products.products.shopNum;
	printf("\n");
}

void appendixProducts(std::fstream& file, int& size) {
	while (1)
	{
		printf("Выберите тип ввода\n(1)Задание параметров продукции\n(2)Вести диалог с пользователем\n(3)Ввод до встречи с заранее заданными параметрами продукции\n");
		printf("Ваш выбор: ");
		int localChoice = 0;
		localChoice = intCheck(localChoice, 1, 3);
		if (localChoice == 1)
		{
			firstProduct(file, size);
			break;
		}
		else if (localChoice == 2)
		{
			secondProduct(file, size);
			break;
		}
		else if (localChoice == 3)
		{
			thirdProduct(file, size);
			break;
		}
	}
}

void inputFromFile(std::fstream& file, int& size)
{
	if (size == 0)
	{
		printf("Проверьте сведения о продукции!\n");
	}
	else
	{
		file.open("file.bin", std::ios_base::binary | std::ios_base::in);
		for (int i = 0; i < size; i++)
		{
			Enterprise products;
			file.read((char*)&products, sizeof(products));
			printProducts(products);
			printf("\n");
		}
		file.close();
	}
}

int searchProducts(std::fstream& file, int& size)
{
	if (size == 0)
	{
		printf("\nДобавьте запись!\n");
	}
	else
	{
		printf("Введите параметры продукции\n");
		printf("1(Ввод наименования)\t2(Ввод количества продукта)\t3(Номер цеха)\n");
		int localChoice = 0;
		localChoice = intCheck(localChoice, 1, 3);
		Enterprise products{ '\0',0,0 };
		{
			products.title[0] = '\0';
			products.products.shopNum = 0;
			products.ceh.count = 0;
		}
		if (localChoice == 1) {
			printf("Наименование продукта:\n");
			strCheck(products.title);
		}
		else if (localChoice == 2) {
			printf("Количество выпущенного продукта:\n");
			products.ceh.count = intCheck(products.ceh.count, 1, 500);
		}
		else if (localChoice == 3)
		{
			printf("Номер цеха:\n");
			products.products.shopNum = intCheck(products.products.shopNum, 1, 500);
		}
		bool ans;
		file.open("file.bin", std::ios_base::binary | std::ios_base::in);
		Enterprise Products{};
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			file.read((char*)&Products, sizeof(Products));
			ans = productsCheck(Products, products, localChoice);
			if (ans) {
				break;
			}
			count = 1;
		}
		file.close();
		if (ans == false)
		{
			printf("Данный продукция не найдена!\n");
			return -1;
		}
		else if (ans)
		{
			printf("\nЗапись найдена:\n");
			printProducts(Products);
			printf("\n");
			return count;
		}
	}
}

void changeElems(std::fstream& file, int indent)
{
	if (indent == 0)
	{
		printf("\nВведите имеющийся элемент для изменения\n");
	}
	else
	{
		printf("Введите параметры для изменения продукции\n");
		printf("1(Ввод наименования)\t2(Ввод количества продукта)\t3(Номер цеха)\n");
		int localChoice = 0;
		localChoice = intCheck(localChoice, 1, 3);
		Enterprise products;
		file.open("file.bin", std::ios_base::binary | std::ios_base::in);
		file.seekg(indent * sizeof(Enterprise), std::ios::beg);
		file.read((char*)&products, sizeof(products));
		file.close();
		if (localChoice == 1)
		{
			char a[60];
			printf("Наименование продукта:\n");
			strCheck(products.title);
		}
		else if (localChoice == 2)
		{
			printf("Количество выпущенного продукта:\n");
			products.ceh.count = intCheck(products.ceh.count, 1, 500);
		}
		else if (localChoice == 3)
		{
			printf("Номер цеха:\n");
			products.products.shopNum = intCheck(products.products.shopNum, 1, 500);
		}
		FILE* file2;
		fopen_s(&file2, "file.bin", "rb+");
		fseek(file2, sizeof(Enterprise) * indent, 0);
		fwrite((char*)&products, sizeof(Enterprise), 1, file2);
		fclose(file2);
	}
}

void deleteElems(std::fstream& file, int indent, int& size)
{
	if (size == 0)
	{
		printf("\nДобавьте запись!\n");
	}
	else if (indent != 0)
	{
		printf("\nВведите имеющийся элемент для удаления\n");
	}
	else
	{
		FILE* file2;
		fopen_s(&file2, "file.bin", "rb+");
		Enterprise Buffer;
		for (int i = indent; i < size - 1; i++)
		{
			fseek(file2, (i + 1) * sizeof(Enterprise), 0);
			fread(&Buffer, sizeof(Enterprise), 1, file2);
			fseek(file2, i * sizeof(Enterprise), 0);
			fwrite(&Buffer, sizeof(Enterprise), 1, file2);
		}
		size--;
		fclose(file2);
		printf("\nВаш параметр успешно удалён\n");
	}
}

void result(std::fstream& file, int size)
{
	file.open("file.bin", std::ios::binary | std::ios::in);
	Enterprise* mas = new Enterprise[size];
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&mas[i], sizeof(Enterprise));
	}
	file.close();
	sheykerSort(mas, size);
	int k = 0;
	int ceh = 0;
	printf("\nВведите номер цеха:");
	ceh = intCheck(ceh, 1, 500);
	for (int i = 0; i < size; i++)
	{
		if (mas[i].products.shopNum == ceh)
		{
			k++;
			printf("\nНаименование:");
			std::cout << mas[i].title;
			printf("\nКоличество выпущенного товара: ");
			std::cout << mas[i].ceh.count;
			printf("\n=======================================================");
		}
	}
	if (k == 0)
	{
		printf("Данный номер цеха отсутствует!\n");
	}
	delete[] mas;
}

int menu(std::fstream& file, int& size)
{
	printf("\n==========================================\n");
	printf("\n\tФункции:");
	printf("\n0 - Выход из программы.");
	printf("\n1 - Добавить новую продукцию.");
	printf("\n2 - Просмотр записей файла.");
	printf("\n3 - Поиск и вывод записей с заданным параметром");
	printf("\n4 - Изменение элемента записи с заданным значением элемента.");
	printf("\n5 - Удаление элемента записи с заданным значением элемента.");
	printf("\n6 - Вывод количество выпущенных изделий по каждому наименованию для заданного цеха в порядке убывания.");
	std::cout << "\nВаш выбор: ";
	int localChoice = 0;
	localChoice = intCheck(localChoice, 0, 6);
	switch (localChoice)
	{
	case 0:
	{
		std::cout << "\n==========================================\n";
		std::cout << "\n----Вы вышли из программы, хорошего дня!----\n";
		return 0;
	}
	case 1:
	{
		std::cout << "\n==========================================\n";
		appendixProducts(file, size);
		break;
	}
	case 2:
	{
		std::cout << "\n==========================================\n";
		inputFromFile(file, size);
		break;
	}
	case 3:
	{
		std::cout << "\n==========================================\n";
		searchProducts(file, size);
		break;
	}
	case 4:
	{
		std::cout << "\n==========================================\n";
		int indent = searchProducts(file, size);
		changeElems(file, indent);
		break;
	}
	case 5:
	{
		std::cout << "\n==========================================\n";
		int indent = searchProducts(file, size);
		if (indent == -1)
		{

		}
		else
		{
			deleteElems(file, indent, size);
		}
		break;
	}
	case 6:
	{
		std::cout << "\n==========================================\n";
		result(file, size);
		break;
	}
	default:
		std::cout << "\nОшибка ввода!\n";
		break;
	}
	menu(file, size);
	return 0;
}
