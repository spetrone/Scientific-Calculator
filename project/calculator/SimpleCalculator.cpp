/*
Author:
Stephanie Petrone

Implementation of the SimpleCalculator derived from Calculator

*/

#include "SimpleCalculator.h"
#include <string>
#include <iostream>

//default constructor uses all default constructors of 
  //base class Calculator, along with its private data members
  // Parser and Expression tree which each create an empty parser
  // and an empty expression tree
  SimpleCalculator::SimpleCalculator() : Calculator() {}


    //overriden function prints menu
   void  SimpleCalculator::displayMenu() {
       std::cout 
            << "\n\nSIMPLE CALCULATOR\n"
            << "----------------------------------------------------------------------------"
            << "\n--> Please enter an expression to calculate using the following  "
            << "symbols: + - * / ^ () \nand numeric values to make" 
            << " a well-formed infix expression to calculate, then press enter to calculate\n" 
            << "--> Negative numbers must be enclosed in braces like so: (-1)\n"
            << "\nExample: (-4)^2 * ((5+4) * (3/2)) \n"
            << "\n<<<< type 'exit' to return to the main menu >>>\n"
            <<"----------------------------------------------------------------------------" 
            << std::endl;
   }

    //execute the simple calculator; works polymorphically, overridden function
   void  SimpleCalculator::execute() {
       
       
     
       std::string inputString; //holds use rinput
       std::string cont; //takes input with getline to continue back to main menu
       double result;

       //display menu
       displayMenu();
       //get user input into string variable 
       getline(std::cin, inputString);

        //input validation for simple calculator
       while ((!(isSimple(inputString))) && (inputString != "exit")){
            std::cout << "Invalid characters or operations entered, " 
            << "please enter using the following characters 0123456789()*/-+^"
            << std::endl;
            //get user input into string variable 
            getline(std::cin, inputString);
       } //end while, input validation

        while (inputString != "exit") {

            calculate(inputString);

            std::cout << "\n<< Press enter to continue >>" << std::endl;
            getline(std::cin, cont);

            //display menu
            displayMenu();
            //get user input into string variable 
            getline(std::cin, inputString);

            //input validation for simple calculator
            while ((!(isSimple(inputString))) && (inputString != "exit")){
                std::cout << "Invalid characters or operations entered, " 
                << "please enter using the following characters 0123456789()*/-+^"
                << std::endl;
                //get user input into string variable 
                getline(std::cin, inputString);
            } //end while, input validation
        } //end while
       
       
   } //end execute()

   //determins if an input string contains characters tht are
   //invalid or would not be for a simple calculator
   bool SimpleCalculator::isSimple(std::string input) {
         bool simple {true} ; //flag to hold result
         std::string validString = "0123456789()*/-+^ ";
         for (char c : input) {
             if (!(validString.find(c)+1)) {
                 simple = false;
             }
         }

         return simple;
   }
