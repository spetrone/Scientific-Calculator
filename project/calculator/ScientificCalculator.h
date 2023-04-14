/*
Author:
Stephanie Petrone

*/
#ifndef SCIENTIFICCALCULATOR_H
#define SCIENTIFICCALCULATOR_H

#include "Calculator.h"
#include "../exceptions/InvalidExpressionException.h"
#include "../exceptions/IllegalCharacterException.h"
#include "../exceptions/ExpressionTreeException.h"
#include "../exceptions/UndefinedOperationException.h"
#include <string>
#include <iostream>

class ScientificCalculator : public Calculator {

    public:

  //default constructor uses all default constructors of 
  //base class Calculator, along with its private data members
  // Parser and Expression tree which each create an empty parser
  // and an empty expression tree
  ScientificCalculator();


    //overriden function prints menu
   void displayMenu() override ;

    //override for execution specific to scientific calculator
   void execute() override ;

};

#endif
