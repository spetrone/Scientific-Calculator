  /*
Author:
Stephanie Petrone

Implementation of SciNode class, derived
from NumericNode

Must override getNumber to return the numeric value of 
the formulaic expression

*/

#include <string>
#include <iostream>
#include "SciNode.h"
#include <math.h>
#include "../exceptions/UndefinedOperationException.h"
#define PI 3.14159265

//default constructor
SciNode::SciNode() : NumericNode{} {}


//constructor with a numeric parameter
SciNode::SciNode(double num) 
: NumericNode{std::to_string(num)} {}


/*constructor with string parameter
calls calculateValue for determining result
of forumla passed as string */
SciNode::SciNode(std::string str) {
  //set number
  NumericNode::setNumber(calculateValue(str));
  //set string holding string version of value
  Node::setVal(str);
  
}


/* overrides setVal to calculate the numeric value 
of the string formula */
void SciNode::setVal(std::string val) {
    Node::setVal(val);
    NumericNode::setNumber(calculateValue(val)); //also update double
} //end setVal




/* calculateValue(string) 
finds the appropriate formula and calculates
the numberic result of a formula provided 
in string form */
double SciNode::calculateValue(std::string formula) {

  //compare formula with different accepted formulae
  //if a match, do a calculation. 
  //should be well-formed as that is checked in Parser
  double result{0};
  double num{0}; //intermediate value for holding number in ()
  
  //sin function
  if (formula.substr(0,3) == "sin") {
    //ignore next (
      std::string numStr; //used to parse the char values in the ()
      int start = formula.find_first_of('(');
      std::string subFormula = formula.substr(start+1); //get substring of (xxx)
      
      //initialize numStr
      numStr = subFormula[0];

      //start looping at next value and read the rest of the value in chars
      int i{1}; //start at next value, first letter already iniitliazed to numStr
      while ( subFormula[i] != ')' && i < subFormula.size()) {
        numStr.push_back(subFormula[i]);
        i++;
      }
      //convert number in string to double, perform calculation
      result = sin((std::stod(numStr))*PI/180);
      if (abs(result) < 0.0000001) result = 0;

  } //end if sin

    //cos function
  if (formula.substr(0,3) == "cos") {
    //ignore next (
      std::string numStr; //used to parse the char values in the ()
      int start = formula.find_first_of('(');
      std::string subFormula = formula.substr(start+1); //get substring of (xxx)
      
      //initialize numStr
      numStr = subFormula[0];

      //start looping at next value and read the rest of the value in chars
      int i{1}; //start at next value, first letter already iniitliazed to numStr
      while ( subFormula[i] != ')' && i < subFormula.size()) {
        numStr.push_back(subFormula[i]);
        i++;
      }
      //convert number in string to double, perform calculation
      result = cos((std::stod(numStr))*PI/180);
      if (abs(result) < 0.0000001) result = 0;

  } //end if cos

  //tan function
  if (formula.substr(0,3) == "tan") {
    //ignore next (
      std::string numStr; //used to parse the char values in the ()
      int start = formula.find_first_of('(');
      std::string subFormula = formula.substr(start+1); //get substring of (xxx)
      
      //initialize numStr
      numStr = subFormula[0];

      //start looping at next value and read the rest of the value in chars
      int i{1}; //start at next value, first letter already iniitliazed to numStr
      while ( subFormula[i] != ')' && i < subFormula.size()) {
        numStr.push_back(subFormula[i]);
        i++;
      }
      //convert number in string to double, perform calculation
      //handle undefined operations with tan
      num = std::stod(numStr);
      if (num == 90|| num == 270 ) {
        throw UndefinedOperationException{"tan(" + numStr + ")"};
        result = 0;
      }
      else result = tan(num*PI/180);
      //since doing conversion, make really small numbers 0
      if (abs(result) < 0.0000001) result = 0;

  } //end if tan

    //log function (BASE 10)
  if (formula.substr(0,3) == "log") {
    //ignore next (
      std::string numStr; //used to parse the char values in the ()
      int start = formula.find_first_of('(');
      std::string subFormula = formula.substr(start+1); //get substring of (xxx)
      
      //initialize numStr
      numStr = subFormula[0];

      //start looping at next value and read the rest of the value in chars
      int i{1}; //start at next value, first letter already iniitliazed to numStr
      while ( subFormula[i] != ')' && i < subFormula.size()) {
        numStr.push_back(subFormula[i]);
        i++;
      }
      //convert number in string to double, perform calculation
      num = std::stod(numStr);
      if (num > 0){
        result = log(num)/log(10);
      } else if (num < 0) {
        throw UndefinedOperationException{"log of negative number"};
      } else if (num == 0) {
        throw UndefinedOperationException{"log of 0"};
      }
      

  } //end if log

  //ln function (BASE e)
  if (formula.substr(0,2) == "ln") {
    //ignore next (
      std::string numStr; //used to parse the char values in the ()
      int start = formula.find_first_of('(');
      std::string subFormula = formula.substr(start+1); //get substring of (xxx)
      
      //initialize numStr
      numStr = subFormula[0];

      //start looping at next value and read the rest of the value in chars
      int i{1}; //start at next value, first letter already iniitliazed to numStr
      while ( subFormula[i] != ')' && i < subFormula.size()) {
        numStr.push_back(subFormula[i]);
        i++;
      }
      //convert number in string to double, perform calculation
       num = std::stod(numStr);
      if (num > 0){
        result = log(num);
      } else if (num < 0) {
        throw UndefinedOperationException{"natural log of negative number"};
      } else if (num == 0) {
        throw UndefinedOperationException{"natural log of zero"};
      }

  } //end if ln

  //square root function sqrt()
  if (formula.substr(0,4) == "sqrt") {
    //ignore next (
      std::string numStr; //used to parse the char values in the ()
      int start = formula.find_first_of('(');
      std::string subFormula = formula.substr(start+1); //get substring of (xxx)
      
      //initialize numStr
      numStr = subFormula[0];

      //start looping at next value and read the rest of the value in chars
      int i{1}; //start at next value, first letter already iniitliazed to numStr
      while ( subFormula[i] != ')' && i < subFormula.size()) {
        numStr.push_back(subFormula[i]);
        i++;
      }
      //convert number in string to double, perform calculation
      num = std::stod(numStr);
      if (num >= 0) {
        result = sqrt(num);
      } else {
        throw UndefinedOperationException{"square root of negative number"};
      }
  } //end of square root

  return result;
} //end calculateValue()
