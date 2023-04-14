/*
Author:
Stephanie Petrone
*/

#include <stdexcept>

#ifndef EXPRESSIONTREEEXCEPTION_H
#define EXPRESSIONTREEEXCEPTION_H

class ExpressionTreeException: public std::runtime_error {
    public:
        //constructor that calls runtime error constructor with happy birthday message
        ExpressionTreeException() : std::runtime_error {"\nInvalid expression (expression tree error)\n"} {};
};

#endif
