  /*
Author:
Stephanie Petrone

Implementation of NumericNode class derived from
the Node class with extra functionality dealing
with numeric data

*/

#include <string>
#include "NumericNode.h"
  
  //default constructor
    NumericNode::NumericNode() : Node{1} {}

    //constructor with a numeric parameter
    NumericNode::NumericNode(double num) 
    : Node{std::to_string(num), 1}, number{num} {}

    //constructor with string parameter
    NumericNode::NumericNode(std::string str) 
    : Node{str, 1}, number{std::stod(str)} {}


    //overrides setVal to also save numeric value
    void NumericNode::setVal(std::string val) {
       Node::setVal(val);
       number = std::stod(val); //also update double
    }

    //functions specific to NumericNode
    //get the numeric value as a double
    double NumericNode::getNumber() const {
      return number;
    }

    //set the numeric value as a double
    void NumericNode::setNumber(double newNum) {
      number = newNum;
      Node::setVal( std::to_string(newNum)); //also update string values
    }
