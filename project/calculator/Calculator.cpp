/*
Author
Stephanie Petrone
*/

#include "Calculator.h"
#include <string>
#include <iostream>
#include "../exceptions/InvalidExpressionException.h"
#include "../exceptions/IllegalCharacterException.h"
#include "../exceptions/ExpressionTreeException.h"
#include "../exceptions/UndefinedOperationException.h"
#include "expression-tree/ExpressionTree.h"
#include "parser/Parser.h"
#include "../nodes/Node.h"
#include <algorithm> //for find

//default constructor
Calculator::Calculator() : parser{}, tree{} {};

double Calculator::calculate(std::string inputExpression) {

    std::string postfixExpression ; //holds parsed expression, initialized to nothing
    double result{0}; //will hold the result of the calculation
    bool valid{true}; //flag for an invalid entry from user, flagged when exception thrown from parser or E.T.

    //parse user input, throws InvalidExpressionException
    //tries converting from infix to postfix
    try {

        parser.parse(inputExpression);
    } 
    catch (InvalidExpressionException& ex) {
        std::cout << ex.what() << std::endl;
        valid = false;
    }
    catch (IllegalCharacterException &charEx) {
        std::cout << charEx.what() << std::endl;
        valid = false;
    }
    catch (UndefinedOperationException& undex) {
        std::cout << undex.what() << std::endl;
        valid = false;
    }

    //pass parsed input to ExpressionTree
    if (valid) {
        try {
            tree.buildExpressionTree(parser.getPostfix());
        }
        catch (ExpressionTreeException& e) {
            std::cout << e.what() << std::endl;
            valid = false;
        }
    } 
    
    //do calculation with expression tree with 
    //built in "evaluate" functino of expression tree
    //if there is a valid expression tree
    if (valid) {
        try {
            result = tree.evaluateTree(tree.getRoot());
        }
        catch (ExpressionTreeException& treeEx) {
            valid = false;
            std::cout << treeEx.what() << std::endl;
        }
        catch (UndefinedOperationException& undef) {
            valid = false;
            std::cout << undef.what() << std::endl;
        }
    }

    //if still valid, set the data members
    if (valid) {
        //display result:
        std::cout << "Result: " << result << std::endl;
    }

    parser.deleteNodeVectors(); //delete heap memory used in this calculation
    return result;
}//end calculate



