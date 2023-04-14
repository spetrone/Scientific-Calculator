/*
Author:
Stephanie Petrone

Definition for simple calculator

The simple calculator has the ability to 
take infix instructions, and use its 
parser to parse it to postfix and then pass
the postfix expression to an ExpressionTree class,
and then use its expression tree to calculate a 
result.

*/

#ifndef SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_H



#include "Calculator.h"
#include "../exceptions/InvalidExpressionException.h"
#include "../exceptions/IllegalCharacterException.h"
#include "../exceptions/ExpressionTreeException.h"
#include "../exceptions/UndefinedOperationException.h"
#include <string>
#include <iostream>

class SimpleCalculator : public Calculator {

  public:

  //default constructor uses all default constructors of 
  //base class Calculator, along with its private data members
  // Parser and Expression tree which each create an empty parser
  // and an empty expression tree
  SimpleCalculator();


    //overriden function prints menu
   void displayMenu() override ;

    //override specific to functionality of simple calculator
   void execute() override ;


  private: 
  
   //determins if an input string contains characters tht are
   //invalid or would not be for a simple calculator
   bool isSimple(std::string);


};

#endif
