/*
Author:
Stephanie Petrone

Defition of NumericNode class derived from
the Node class with extra functionality dealing
with numeric data

*/

#ifndef NUMERICNODE_H
#define NUMERICNODE_H

#include <string>
#include "Node.h"

class NumericNode : public Node{

    public:

    //default constructor
    NumericNode();

    //overloaded constructor for double parameter
    explicit NumericNode(double num);

    //overloaded constructor for string parameter
    explicit NumericNode(std::string str);

     //overrides setVal to also save numeric value
    virtual void setVal(std::string) override;

    //functions specific to NumericNode
    //get the numeric value as a double
    double getNumber() const;

    //set the numeric value as a double
    //overridden in SciNode class
    void setNumber(double);

    private:
        double number;
};

#endif
