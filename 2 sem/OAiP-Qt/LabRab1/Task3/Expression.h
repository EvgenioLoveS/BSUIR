//
// Created by Asus on 11.02.2023.
//

#ifndef TASK3_EXPRESSION_H
#define TASK3_EXPRESSION_H

class Expression{
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

#endif //TASK3_EXPRESSION_H
