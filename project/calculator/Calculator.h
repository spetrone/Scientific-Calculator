/*
Author:
Stephanie Petrone

Definition of the abstract Calculator class
Its derived classes are the SimpleCalculator class
and the ScientificCalculator class

*/

#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "Calculator.h"
#include "../nodes/Node.h"
#include <string>
#include <iostream>
#include "../exceptions/InvalidExpressionException.h"
#include "../exceptions/IllegalCharacterException.h"
#include "../exceptions/ExpressionTreeException.h"
#include "expression-tree/ExpressionTree.h"
#include "parser/Parser.h"


class Calculator {

    public:

    //default constructor
    Calculator(); 

    //virtual default destructor
    virtual ~Calculator() = default;

    //pure virtual function prints menu
    virtual void displayMenu() = 0;

    //interacts with user to perform a calculation
    //works polymorphically with the SimpleCalculator
    //and the Scientific Calculator to show its 
    //menu, get input, calculate, etc.
    virtual void execute() = 0;

    //used in execute, calculates
    //common to all types of calculators; not virtual
    double calculate(std::string);


    private:
        Parser parser;
        ExpressionTree tree;


};

#endif
