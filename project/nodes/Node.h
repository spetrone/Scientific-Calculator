/*
Author:
Stephanie Petrone

Defition of Node class used in building
ExpressionTree objects, with the Parser Class

*/

#ifndef NODE_H
#define NODE_H

#include <string>


class Node {

    public:

    //default constructor
    Node();

    //default virtual destructor 
    virtual ~Node() = default;

    //constructor with type
    explicit Node(int);

    //constructor with string parameter
    explicit Node(std::string str);

    //constructor with string for val and int for type
    Node(std::string str, int type);

    //virtual functions to set and get values
    //which are strings of the operators or 
    //numeric values
    virtual std::string getVal() const;

    //setter for type
    virtual void setVal(std::string);

    //getter for type
    int getType() const;

    //setter for type
    void setType(int t);

    //setter for right node
    void setRight(Node* newRight) ;

    //getter for right node
    Node* getRight() const;

    //setter for left node
    void setLeft(Node* newLeft);

    //getter for left node
    Node* getLeft() const ;


  

    private:
        std::string value;
        int nodeType;
        Node *  left;
        Node* right;
};

#endif
