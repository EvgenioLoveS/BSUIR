//
// Created by Asus on 11.02.2023.
//

#ifndef TASK3_BINARYOPERATION_H
#define TASK3_BINARYOPERATION_H
#include "Expression.h"

class BinaryOperation : public Expression {
private:
    Expression const* left;
    Expression const* right;
    char op;
    double sum() const;
    double difference() const;
    double multiplication() const;
    double division() const;
    double result() const;
public:
    BinaryOperation(Expression const* left_argument,const char op_argument,Expression const* right_argument);
    ~BinaryOperation();
    double evaluate() const override;
};
#endif //TASK3_BINARYOPERATION_H
