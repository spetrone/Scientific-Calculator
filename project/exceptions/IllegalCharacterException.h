/*
Author:
Stephanie Petrone

Definition of exception for an invalid character entered for calculating
*/

#ifndef ILLEGALCHAREX_H
#define ILLEGALCHAREX_H

#include <stdexcept>
#include <string>

class IllegalCharacterException: public std::runtime_error {
    public:
        //constructor that calls runtime error constructor with happy birthday message
        IllegalCharacterException(char c) : std::runtime_error { std::string{"\nIllegal character '"} + c + "' entered\n"} {};
};

#endif
