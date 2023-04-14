/*
Author:
Stephanie Petrone

Implementation of Node class used in building
ExpressionTree objects, with the Parser Class

*/

#include "Node.h"
#include <string>
    
    //default constructor
    Node::Node() : left{NULL}, right{NULL}, nodeType{-1}{}

    Node::Node(int type) 
    : left{NULL}, right{NULL}, nodeType{type} {}

    //constructor with string parameter
    Node::Node(std::string str) 
    : left{NULL}, right{NULL}, value{str} {}

    //constructor with string for val and int for type
    Node::Node(std::string str, int type) 
    : left{NULL}, right{NULL}, value{str}, nodeType{type} {}

    //virtual functions to set and get values
    //which are strings of the operators or 
    //numeric values
    std::string Node::getVal() const {
        return value;
    }

    //setter for value
    void Node::setVal(std::string val) {
        value = val;
    }

    //getter for type
    int Node::getType() const {
         return nodeType;
    }

    //setter for type
    void Node::setType(int t) {
        nodeType = t;
    }

    //setter for right node
    void Node::setRight(Node* newRight) {
        right = newRight;
    }

    //getter for right node
    Node * Node::getRight() const {
        return right;
    }

    //setter for left node
    void Node::setLeft(Node* newLeft) {
        left = newLeft;
    }

    //getter for left node
    Node* Node::getLeft() const {
        return left;
    }

