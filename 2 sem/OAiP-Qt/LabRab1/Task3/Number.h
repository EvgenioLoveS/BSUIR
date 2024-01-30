//
// Created by Asus on 11.02.2023.
//

#ifndef TASK3_NUMBER_H
#define TASK3_NUMBER_H
#include "Expression.h"
class Number : public Expression {
private:
    double value;
public:
    Number(double value_argument);
    double evaluate() const override;

};
#endif //TASK3_NUMBER_H
