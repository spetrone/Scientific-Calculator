/*
Author:
Stephanie Petrone

Definition of exception for an invalid expression
*/

#ifndef INVALIDEXPEX_H
#define INVALIDEXPEX_H

#include <stdexcept>

class InvalidExpressionException: public std::runtime_error {
    public:
        //constructor that calls runtime error constructor with happy birthday message
        InvalidExpressionException() : std::runtime_error {"\nInvalid expression entered\n"} {};
};

#endif
