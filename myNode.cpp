

#include "mynode.h"

#include "myNode.h"
myNode::myNode(char value, int number, myNode* next):value(value), next(next), number(number){}

myNode::myNode(char value){
    this->value = value;
}
myNode::myNode(int number){
    this->number = number;
}


