/*
Author:
Stephanie Petrone

Implementation file for Parse

*/

#include "Parser.h"
#include "../../nodes/Node.h"
#include <vector>
#include <stack>
#include <iostream>
#include "../../exceptions/InvalidExpressionException.h"
#include "../../exceptions/IllegalCharacterException.h"


//default constructor sets validity to true (For the expression)
//validity is used in the 
Parser::Parser() : infixPtr{NULL}, postfixPtr{NULL} {}

//destructor to delete memory allocated for Node vectors
Parser::~Parser() {
    deleteNodeVectors();
}

//takes an infix string and returns a vector
//of nodes (for the expression tree) in postfix form
//deals with pointers to the heap
std::vector<Node*>* Parser::parse (std::string infixString) {
    
    std::vector<Node*>* resultPtr = NULL;
    //first parse into nodes, then pass that to infix to postfix

    std::vector<Node*>* const vectorPtr = toNodeVector(infixString);
    return infixToPostfix(vectorPtr);

}

//takes  a node vector in infix form and returns a pointer to  a vector 
//with it in postfix form; deals with pointers to the heap
std::vector<Node*>* Parser::infixToPostfix(std::vector<Node*>* infixVecPtr) {
    
    //use a stack for nodes
    std::stack<Node*> nodeStk;  //the working stack, not put on
    std::vector<Node*>* postFix = new std::vector<Node*>; //the result postfix node ptr vector

    //push special character to stack
    Node firstNode{"end"};
    int loc{0}; //keeps track of location in node vector to compare to if needed
    nodeStk.push(&firstNode); //push an invalid node to bottom of stack to prevent underflow with comparisons

    //loop through private data member - the parsed infix node ptr vector
    for (Node* n : (*infixVecPtr)) {

        //if it is a numeric type (Numeric or scientific node)
        if(n->getType() == 1) {
            copyToPostfix(n, postFix);
        }
        else if (n->getType() == 0) { //operator node or ( )

            if (n->getVal() == "(") {
                if (loc >= 1 && (*infixVecPtr)[loc-1]->getVal() == ")"){
                    throw InvalidExpressionException{};
                }
                //negative unary operator
                if ((*infixVecPtr)[loc+1]->getVal() == "-") {
                    //create a zero node so it is 0 - nextNumber
                    Node* zeroNodePtr = new NumericNode{0};
                    postFix->push_back(zeroNodePtr);
                }
                nodeStk.push(n);
            }
            else if (n->getVal() == "^") {
                nodeStk.push(n);
            }
            else if (n->getVal() == ")" ) {
                //get all values in ()
                while (nodeStk.top()->getVal() != "end" && nodeStk.top()->getVal() != "(") {
                    copyToPostfix(nodeStk.top(), postFix);
                    nodeStk.pop();
                }//end while
                //ensure it is well-formed; if not well-formed, no ()
                if (!nodeStk.empty() && nodeStk.top()->getVal() == "(")
                    nodeStk.pop(); //pop the "("
                else { 
                    throw InvalidExpressionException{};
                }
            }
            else { //compare precedences of operators to determine what to do with stack
                //compare operators with char values in node values (ust [0] since they are strings)
                if (prec(n)  > prec(nodeStk.top())) {
                    nodeStk.push(n); //precedence is higher, push to stack
                }
                else { //lower precedence, pop them off while it is a lower precedence and not at bottom of stack
                    while(nodeStk.top()->getVal() != "end" && prec(n)  <= prec(nodeStk.top())) {
                        copyToPostfix(nodeStk.top(), postFix); 
                        nodeStk.pop();
                    }
                    //finally push lower precedence node to stack
                    nodeStk.push(n);
                } //end else

            } //end else
        } //end else if --> numeric type = 0
        loc++; //increment location
    } //end for (iterating through node vector)

    //empty the stack at the end
    while(nodeStk.top()->getVal() != "end" ) {
        copyToPostfix(nodeStk.top(), postFix); 
        nodeStk.pop();
    }

    postfixPtr = postFix; //set data member of postfix vector continuing to be used
    return postFix;
}



//takes string and parses it to make an array of nodes in 
//the same order as the array
//throws invalidExpressionException for improper formulae (e.g. sinx)
//throws illegalCharacterException for illegal characters (e.g. &)
std::vector<Node*>* Parser::toNodeVector(std::string infixStr) {

    //get char by char in infixStr
    std::vector<Node*>* vectorPtr = new std::vector<Node*>; 

    //compare to current type to know if it is a new node 
    charTypeT lastType ;
    std::string tempString; //used to set each node
    bool inFormula{false}; //flag to determine if in the middle of parsing a formula

    try {

        //read first element
        char c = infixStr[0];
        char lastChar{c};
        tempString = c;
        lastType = getType(c);
        int formCount{0}; //used in if(inFormula) to test validity of forumla and braces

        for (int i{0}; i < infixStr.size()+1; i++) {

            //loop goes one beyond string for last node, so do bounds checking
            //on last char; + skip side case of first char for operators and numbers
            //since they need to compare with a previous value unlike the formula parsing
            if(i > 0 && i < infixStr.size()){
                c = infixStr[i];

                //if different from previous chunk, create node and add it to vector; reset tempString
                if(!inFormula && (lastType == op || (lastType == digit && (getType(c) == op || getType(c) == ignore)))) {

                        {
                        Node * nodePtr;
                        //make operator node if type is operator
                        if(lastType == op) {
                            nodePtr = new OperatorNode{tempString};
                        }
                        else if (lastType == digit) {
                            nodePtr = new NumericNode{tempString};
                        }
                        
                        //add node to vector
                        vectorPtr->push_back(nodePtr);
                        tempString.clear();
                    }
                } //end if

            }//end if 

            //side case, not in formula & last element
                if (i == infixStr.size() && !inFormula ) {
                    if (!(getType(c) == ignore)){
                        Node * nodePtr;
                        //make operator node if type is operator
                        if(lastType == op) {
                            nodePtr = new OperatorNode{tempString};
                        }
                        else if (lastType == digit) {
                            nodePtr = new NumericNode{tempString};
                        }
                        //add node to vector
                        vectorPtr->push_back(nodePtr);
                        tempString.clear();
                    }
                }

                //keep going through string and parsing
                if(getType(c) == ignore) { //ignore whitespace
                    lastType = ignore;
                }
                else if (!inFormula && i > 0){ //all other cases other than first char
                    tempString.push_back(c);
                    lastType = getType(c);  
                }
                //test if it is an alphanumeric formula (test for inFormula to not double flag/clear)
                if(getType(c) == alpha && !inFormula) {
                    inFormula = true; //set flag to change it it is processed
                    formCount = 0; //reset to zero
                    tempString.clear();
                }
                


                //PARSING AN ALPHANUMERIC FORMULA - for scientific calculations
                //Creates a SciNode
                if(inFormula) {

                    //test for expression form invalidity
                    if (lastType == alpha && getType(c) != alpha){
                        if (c != '(') {
                            throw InvalidExpressionException{};
                        }
                    } 
                    if ((formCount != 0) && lastChar == '(' && (getType(c) != digit) && c != '-') {
                        throw InvalidExpressionException{};
                    }
                    if (c == ')' && lastType != digit) {
                        throw InvalidExpressionException{};
                    }

                    //add to temp string if not a whitespace (ignore whitespace)
                    if(!(c == ' ' )){
                        if(tempString.empty()) { //side case for first letter (otherwise adds space to beg)
                            tempString.clear();
                            tempString = c;
                        }
                        else { //add rest of formula to tempSTring
                            tempString.push_back(c);
                        }
                        
                        
                    }

                    //set for reference the last type, keep tracking through formula
                    lastType = getType(c);

                    //finally, flag the enf of the formula after checking for validity above
                    if ( c == ')') {
                        inFormula = false;

                        //create new SciNode node
                        Node * nodePtr;
                        SciNode * SciNodePtr = new SciNode{tempString};
                        nodePtr = SciNodePtr;

                        //push node to vector
                        //add node to vector
                        vectorPtr->push_back(nodePtr);

                        tempString.clear();
                        lastType = ignore; //ignore last operator since it is part of formula
                        c = ' '; //to ignore the ) in side case where ) of formula is the last in string
                    }
                    formCount++; //incrementing number of characters in formula to track for brace checking
                } //end if inFormula
        
                //save this char to compare for testing for validity for formulae
                lastChar = c;
                
        } //end for
        
    }//end try
    catch (IllegalCharacterException& charEx) {
        //clear the vector and rethrow
        (*vectorPtr).clear(); //clear result vector
        throw; //re-throw the exception to be handled in calculator
    } //end catch
    
    infixPtr = vectorPtr;
    return vectorPtr;

}




/*
delete heap memory that is allocated during each parse call.

The memory is allocated for an infix node vector, 
pointed to by Parser's infixPtr data member, and for a postfix node vector,
pointer to by Parer's postfixPtr data member. 
The infixPtr vector contains all nodes including the ( ) nodes, while
postfixPtr's vector contains postfix nodes along with extra 0 NumericNodes
added for calculating unary - operations.

each call to parse creates an infix vector and a postfix vector
--> there must be a call to deleteNodeVectors for every call to parse (after tree is used)
*/
void Parser::deleteNodeVectors() {

    //delete infix allocated memory
    //delete each object
    if (infixPtr != NULL) { //if vector exists
        
        for (int i = 0; i < (*infixPtr).size(); i++) {
            delete (*infixPtr)[i];
            (*infixPtr)[i] = NULL;
        }
        //delete the vector
        delete infixPtr;
        infixPtr = NULL;
    }

    //delete postfix allocated memory
     if (postfixPtr != NULL) { //if vector exists
        
        for (int i = 0; i < (*postfixPtr).size(); i++) {
            delete (*postfixPtr)[i];
            (*postfixPtr)[i] = NULL;
        }
        //delete the vector
        delete postfixPtr;
        postfixPtr = NULL;
    }
}


//get the inffix expression; no setter
std::vector<Node*>* Parser::getInfix() const {
    return infixPtr;
}

//get the postfix expression pointer; no setter
std::vector<Node*>* Parser::getPostfix() const {
    return postfixPtr;
}

//returns enum type of char (alpha, ignore (whitespace), numeric or op(operator))
charTypeT Parser::getType(char c) {
    if(isdigit(c) || c == '.') 
        return digit;
    else if(c == '/' || c == '*' || c == '+' || c == '-' || c == '^'  || c == '(' || c == ')')
        return op;
    else if (c == ' ')
        return ignore; //ignore whitespace
    else if ((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z'))
        return alpha;
    else {
        throw IllegalCharacterException{c};
    }
}


//creates a copy of a node on the heap and pushes it to the given vector
void Parser::copyToPostfix(Node* ndPtr, std::vector<Node*>* postfixVec) {

    //generic node pointer to be pushed to postfix vector
    Node * newNodePtr;
    //create a copy based on node type
    //push to postfix 
    SciNode* sci = dynamic_cast<SciNode*>(ndPtr);
    if ( sci != NULL) {
        SciNode * newSciNode = new SciNode(ndPtr->getVal());
        newNodePtr = newSciNode;
    }else if (dynamic_cast<NumericNode*>(ndPtr) != NULL) {
        //create new numeric node
        NumericNode * newNumNode = new NumericNode(ndPtr->getVal());
        newNodePtr = newNumNode;
    } else if (dynamic_cast<OperatorNode*>(ndPtr) != NULL) {
        OperatorNode * newOpNode = new OperatorNode(ndPtr->getVal());
        newNodePtr = newOpNode;
    }

    //push the new node to the vector
    postfixVec->push_back(newNodePtr);
}


//create precedence hierachy, assign integer values, and write control statements 
//to determine the precedence of some operator
//accesses operator through node argument
int Parser::prec(Node* n) {
    char c = (n->getVal()).front();
    int pre{0}; //holds precedence value;
    //lowest precedence 0, highest 3
    if (c == '+' || c == '-') {
        pre = 1;
    } else if (c == '*' || c=='/') {
        pre = 2;
    } else if (c == '^') {
        pre = 3;
    } else {
        pre = 0;
    }

    return pre;
}

