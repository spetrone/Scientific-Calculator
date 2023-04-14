/*
Author:
Stephanie Petrone

Definition of Parser class

*/

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include "../../nodes/Node.h"
#include "../../nodes/OperatorNode.h"
#include "../../nodes/NumericNode.h"
#include "../../nodes/SciNode.h"
#include "../../exceptions/IllegalCharacterException.h"
#include "../../exceptions/InvalidExpressionException.h"

enum charTypeT {op, digit, ignore, alpha}; //used for reference of char types during parsing
class Parser {

    public:

        //default constructor; will set validity to true
        Parser() ;

        //define destructor to delete memory of allocated data members
        ~Parser();

        //takes an infix string and returns a vector
        //of nodes (for the expression tree) in postfix form
        std::vector<Node*>* parse (std::string infixString) ;

        //takes  a node vector in infix form and returns a pointer to  a vector 
        //with it in postfix form
        std::vector<Node*>* infixToPostfix(std::vector<Node*>* infixVec) ;

        


        //takes string and parses it to make an array of nodes in 
        //the same order as the array
        //throws invalidExpressionException for improper formulae (e.g. sinx)
        //throws illegalCharacterException for illegal characters (e.g. &)
        std::vector<Node*>* toNodeVector(std::string infixStr);
        
        

        /*
        delete heap memory that is allocated during each parse call.
        */
        void deleteNodeVectors();
    
        //get the inffix expression; no setter
        std::vector<Node*>* getInfix() const ;
         //get the postfix expression; no setter

        std::vector<Node*>* getPostfix() const ;

    private:

        //returns type of characer, - alpha, ignore (whiespace), numeric or op
        //type is an enum in global scope
        charTypeT getType(char c);

        //create precedence hierachy, assign integer values, and write control statements 
        //to determine the precedence of some operator
        //accesses operator through node argument
        int prec(Node* n);

        //creates a copy of a node on the heap and pushes it to the given vector
        void copyToPostfix(Node*, std::vector<Node*>*);


        //data members
        std::vector<Node*>* infixPtr; //holds the parsed infix expression (as nodes in vector)
        std::vector<Node*>* postfixPtr; //holds the postfix expression if valid

};

#endif
