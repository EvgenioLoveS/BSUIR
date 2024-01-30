#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <ranges>
#include <stdio.h>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	printInfo();
	int size = 0; //size_of_file
	std::fstream file;
	file.open("file.bin", std::ios::out);
	file.close();
	menu(file, size);
	return 0;
}




