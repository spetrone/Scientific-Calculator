 /*
Author:
Stephanie Petrone

Implementation of OperatorNode class derived from
the Node class. Has specific constructors and used for downcasting

*/

#include <string>
#include "OperatorNode.h"
 
 
 //default constructor
OperatorNode::OperatorNode() : Node{0} {}

//constructor with string parameter
OperatorNode::OperatorNode(std::string str) : Node{str, 0} {} 

        
