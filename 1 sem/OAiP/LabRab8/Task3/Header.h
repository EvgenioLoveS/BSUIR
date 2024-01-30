#pragma once

typedef union Shop;
typedef union Ceh;
typedef class Enterprise;
int intCheck(int, int, int);
void strCheck(char str[]);
void printInfo();
void initProducts(Enterprise&);
bool arrCheck(char a[], char b[]);
bool productsCheck(Enterprise, Enterprise, int);
void sheykerSort(Enterprise*, int);
void saveInFile(std::fstream&, Enterprise);
void firstProduct(std::fstream&, int&);
void secondProduct(std::fstream&, int&);
void thirdProduct(std::fstream&, int&);
void printProducts(Enterprise);
void appendixProducts(std::fstream&, int&);
void inputFromFile(std::fstream&, int&);
int searchProducts(std::fstream&, int&);
void changeElems(std::fstream&, int);
void deleteElems(std::fstream&, int, int&);
void result(std::fstream&, int);
int menu(std::fstream&, int&);