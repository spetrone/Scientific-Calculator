/*
Author:
Stephanie Petrone

Implementation of Expression Tree

*/

#include "ExpressionTree.h"
#include "../../exceptions/UndefinedOperationException.h"
#include <iostream>

//default constructor
ExpressionTree::ExpressionTree() : root{NULL}, result{0} {};
 
//build an expression tree from a postfix node vector
//returns the root of the tree
Node* ExpressionTree::buildExpressionTree(std::vector<Node *>* postfix) {
    std::stack<Node*> stk; //working stack for building tree
    Node* lTemp{NULL};
    Node* rTemp{NULL};
    int i{0}; //accumulator for loop and accessing node in postfix vector
    bool valid {true}; //flag for weather an expression is still valid; true until error found


    while (i < postfix->size() && valid) {

        Node* n = (*postfix)[i];
        //if operand (node type 1), push to stack
        if (n->getType() == 1) {
            stk.push(n);
            
        }
        //if operator, pop two values from stack and make them the 
        //children of the operator, then push the current node to stack
        else if (n->getType() == 0) { 
            if(!(stk.empty())) {
                rTemp = stk.top();
                    stk.pop();
            } else {
                valid = false;
                throw ExpressionTreeException{};
            }
            if (!(stk.empty())) {
                lTemp = stk.top();
                stk.pop();
            } else {
                valid = false;
                throw ExpressionTreeException{};
            }
            
            n->setLeft(lTemp);
            n->setRight(rTemp);
            stk.push(n);
        }//end else if

        i++;
    } //end while

    //set root of expression tree to the value in the stack
    if (!(stk.empty())) {
        root = stk.top();
        return stk.top();
    }
    else {
        valid = false;
        throw ExpressionTreeException{};
    }
 
} //end build expression tree


//evaluate the expression tree with inorder traversal
double ExpressionTree::evaluateTree(Node* rt) {

    double result{0}; //holds result of tree evaluation

    //do inorder traversal of the tree, perfrming calculations
    //if null pointer passed, invalid tree formed
    if (rt == NULL) {
        throw ExpressionTreeException{};
    }
    else {
    //base case, at leaf; all leaves are numbers, or else tree is in an invalid form
    if (rt->getLeft() == NULL && rt->getRight() == NULL) {
        //do type checking in case it is improperly formed
        if (rt->getType() == 1) {
            NumericNode* numNodePtr = dynamic_cast<NumericNode*>(rt);
            if (numNodePtr != NULL) {
                return numNodePtr->getNumber();
            }
        }
        else { //not formed correctly
            throw ExpressionTreeException{};
        }
    } //end if

        //all internal nodes are operators, else throw exception - invalid form
        else { //in internal node, continue inorder traversal down tree

            if(rt->getType() == 0) {
                double left = evaluateTree(rt->getLeft());
                double right = evaluateTree(rt->getRight());
                char op = rt->getVal().at(0);

                
                //do calcuation based on operator
                switch (op) {
                    case ('+') : result = left + right;
                    break;
                    case ('-') : result = left - right;
                    break;
                    case ('/') : 
                    if ( right == 0 ) { //handle division by zero
                        throw UndefinedOperationException{" division by zero"};
                        result = 0;
                    }
                    else result = left / right;
                    break;
                    case('*') : result = left * right;
                    break;
                    case('^') : result = pow(left, right);
                    break;
                    default :
                        throw ExpressionTreeException{};
                } //end switch
            } //end if
            //otherwise, internal node is numeric, which is an invalid form for the tree
            else if (rt->getType() == 1) {
                throw ExpressionTreeException{};
            }
        } //end else (internal node/not base case)
            return result;
        }
    } //end evaluateTree()



    //get the root of the tree; no setter, not needed
    Node* ExpressionTree::getRoot() const {
        return root;
    }
