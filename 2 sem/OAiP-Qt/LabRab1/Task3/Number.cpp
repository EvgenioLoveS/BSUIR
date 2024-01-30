//
// Created by Asus on 11.02.2023.
//
#include "Number.h"

Number::Number(double value_argument){
    Number::value = value_argument;
}

double Number::evaluate() const {
    return value;
}