/*
Author:
Stephanie Petrone

This project is an implementation of a simple calculator and 
of a scientific calculator with a menu-driven driver to have 
the user interact with the calculator.

*/

#include <iostream>
#include <string>
#include "calculator/ScientificCalculator.h"
#include "calculator/Calculator.h"
#include "calculator/SimpleCalculator.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printMainMenu();


int main() {

    int opt;
    double result{0};

    //create one of each calculator object to call on
    SimpleCalculator simple;
    ScientificCalculator sci;

    
    printMainMenu();

    while (!(cin>>opt) || (opt != 1 && opt != 2 && opt != -1)) {
        cout << "Please enter option 1 or option 2, -1 to quit" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (opt != -1){

        if(opt == 1) {
            //clear cin
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            simple.execute();

            
        }
        else if (opt == 2) {
            //clear cin
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            sci.execute();

        }

        //get menu inputagain
        printMainMenu();
        while (!(cin >> opt) || (opt != 1 && opt != 2 && opt != -1)) {
        cout << "Please enter option 1 or option 2, -1 to quit" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

       

    } //end while
    
} 

//print the driver menu
void printMainMenu() {
    cout << "\n\nMAIN MENU\n"
    << "---------------------------------------\n";
    cout << "Select an option from the menu: " << endl;
    cout << "[1] Simple Calculator" << endl;
    cout << "[2] Scientific Calculator " << endl;
    cout << "[-1] Quit" << endl;
    cout << "---------------------------------------------" << endl;
}
