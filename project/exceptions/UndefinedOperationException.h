/*
Author:
Stephanie Petrone

Definition of exception for an underfined operation
*/

#ifndef UNDEFOPEX_H
#define UNDEFOPEX_H

#include <stdexcept>
#include <string>

class UndefinedOperationException: public std::runtime_error {
    public:
        //constructor that calls runtime error constructor with happy birthday message
        UndefinedOperationException(std::string str) : std::runtime_error { std::string{"Undefined operation: " + str}} {};

        //default constructor
        UndefinedOperationException() : std::runtime_error {"Undefined Operation"} {};

};

#endif
