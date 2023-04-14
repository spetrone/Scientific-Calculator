/*
Author:
Stephanie Petrone

Defition of SciNode class derived from
the NumericNode class with extra functionality dealing
with calculting values from strings represnting formulae

*/

#ifndef SCINODE_H
#define SCINODE_H

#include <string>
#include "NumericNode.h"

class SciNode : public NumericNode{

    public:

    //default constructor
    SciNode();

    //overloaded constructor for double parameter
    explicit SciNode(double num);

    //overloaded constructor for string parameter
    explicit SciNode(std::string str);

    //overrides setVal to use calculateValue on formula
    void setVal(std::string) override;

    //finds the appropriate formula and calculates
    //the numberic result of a formula provided 
    //in string form
    double calculateValue(std::string);

};

#endif
