/*
Author:
Stephanie Petrone

Definition of OperatorNode class derived from
the Node class. Has specific constructors and used for downcasting

*/

#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include <string>
#include "Node.h"

class OperatorNode : public Node {

    public:
        //default constructor
        OperatorNode();

        //constructor with string parameter
        explicit OperatorNode(std::string);

        
};

#endif
