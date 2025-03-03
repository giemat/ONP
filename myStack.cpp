#include <iostream>
#include "myStack.h"
#include "myNode.h"
void myStack::push(char value) {
    myNode* newNode = new myNode(value);
    newNode->next = Top;
    Top = newNode;
    stackSize++;
}

void myStack::pop() {
    if (!empty()) {
        myNode* temp = Top;
        Top = Top->next;
        delete temp;
        stackSize--;
    } else {
        std::cout << "Empty stack" << std::endl;
    }
}

char myStack::top() const {
    if (!empty()) {
        return Top->value;
    } else {
        return 0;
    }
}

bool myStack::empty() const {
    return Top == nullptr;
}

myStack::~myStack() {
    while (!empty()) {
        pop();
    }
}

void myStack::print() const {
    myNode* current = Top;
    while (current != nullptr) {
        std::cout << current->number << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int myStack::intTop() const {
    if (!empty()) {
        return Top->number;
    } else {
        return 0;
    }
}

void myStack::intPush(int value) {
    myNode* newNode = new myNode(value);
    newNode->next = Top;
    Top = newNode;
    stackSize++;
}


