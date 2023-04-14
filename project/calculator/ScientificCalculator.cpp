/*
Author:
Stephanie Petrone

*/

#include "ScientificCalculator.h"
#include <string>
#include <iomanip>
#include <iostream>

//default constructor calls its base class default constructor
  ScientificCalculator::ScientificCalculator() : Calculator() {}


    //overriden function prints menu
   void  ScientificCalculator::displayMenu() {
       std::cout <<"\n\nSCIENTIFIC CALCULATOR\n"
            <<"---------------------------------------------------------------------------------" 
            << "\n--> Please enter an expression to calculate using the following  "
            << "symbols: + - * / ^ () \nand numeric values along with scientific operators in the list below.\n"
            << "--> Negative numbers must be enclosed in braces like so: (-1)\n"
            <<"- - - - - " 
            << std::endl << std::left << std::setw(30) <<  "sine function (degrees):" << std::setw(10) << "sin(#)"
            << std::endl << std::setw(30) << "tangent function (degrees):" << std::setw(10) << "tan(#)"
            << std::endl << std::setw(30) << "cosine function (degrees):" << std::setw(10) <<  "cos(#)"
            << std::endl << std::setw(30) << "logarithm function (base 10):" << std::setw(10) <<  "log(#)"
            << std::endl << std::setw(30) << "natural logarithm function:" << std::setw(10) <<  "ln(#)"
            << std::endl << std::setw(30) << "square root function:" << std::setw(10) <<  "sqrt(#)"
            << std::endl << std::setw(40) << " \n     Example: sin(90) * sqrt(4) \n"
            << std::endl << "<<< Type 'exit' to go back to the main menu...>>>\n"
            <<"---------------------------------------------------------------------------------" << std::endl;
   }

    //execute the simple calculator; works polymorphically, overridden function
   void  ScientificCalculator::execute() {
       
       std::string inputString; //holds use rinput
       std::string cont; //used with getline to continue back to menu

       //display menu
       displayMenu();
       //get user input into string variable 
       getline(std::cin, inputString);

        while (inputString != "exit") {

            calculate(inputString);

            std::cout << "\n<< Press enter to continue >>" << std::endl;
            getline(std::cin, cont);

            //display menu
            displayMenu();
            //get user input into string variable 
            getline(std::cin, inputString);
        } //end while
       
   } //end execute()

   
