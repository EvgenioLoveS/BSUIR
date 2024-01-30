//
// Created by Asus on 11.02.2023.
//
#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Expression const* left_argument,const char op_argument,Expression const* right_argument){
    BinaryOperation::left = left_argument;
    BinaryOperation::right = right_argument;
    BinaryOperation::op = op_argument;
}

BinaryOperation::~BinaryOperation(){
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

double BinaryOperation::evaluate() const {
    return BinaryOperation::result();
}

double BinaryOperation::sum() const{
    return left->evaluate() + right->evaluate();
}
double BinaryOperation::difference() const{
    return left->evaluate() - right->evaluate();
}
double BinaryOperation::multiplication() const {
    return left->evaluate() * right->evaluate();
}
double BinaryOperation::division() const{
    return left->evaluate() / right->evaluate();
}
double BinaryOperation::result() const{
    switch(op){
        case '+' :
            return sum();
        case '-' :
            return difference();
        case '*' :
            return multiplication();
        case '/' :
            return division();
        default:
            //std::cout << "you entered an invalid operation" << "\n";
            throw "You entered an invalid operation";
    }
}