#include <iostream>
#include "BinaryOperation.h"
#include "Number.h"
#include "Expression.h"

using namespace std;

// Приводим указатель на Expression к указателю на int,
// затем берем значение этого указателя
// (значение - это указатель на таблицу виртуальных методов, а для объектов одного класса она общая).
bool check_equals(Expression const* left, Expression const* right) {
    return (*((int const *)left) == *((int const *)right)) ? true : false;
}

int main() {
    Expression* sube = new BinaryOperation(new Number(4.5), '*' , new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+' , sube);
    cout << "Result answer:" << "\n";
    cout << expr->evaluate() << endl;
    cout << "Check_equals:" << "\n";
    cout << check_equals(sube, expr);
    delete expr;
    return 0;
}
