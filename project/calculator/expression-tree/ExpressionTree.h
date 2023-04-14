/*
Author:
Stephanie Petrone

Definition for ExpressionTree class

ExpressionTree class is a friend in the Node class

*/

#include "../../nodes/Node.h"
#include "../../nodes/NumericNode.h"
#include "../../nodes/SciNode.h"
#include "../../nodes/OperatorNode.h"
#include "../../exceptions/ExpressionTreeException.h"
#include <vector>
#include <stack>
#include <math.h>

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

class ExpressionTree {

    public:

    //default constructor
    ExpressionTree();
 
    //build an expression tree from a postfix node vector
    //returns the root of the tree
    Node* buildExpressionTree(std::vector<Node *>* postfix);

    //evaluate the expression tree with inorder traversal
    double evaluateTree(Node* rt);

    //get the root of the tree; no setter, not needed
    Node* getRoot() const;

    private:
    Node* root; //root of the expression tree
    double result; //holds the latest resultof the expression tree 

};

#endif
