#include "myQueue.h"
#include <iostream>


void myQueue::pop() {
    if (empty()) {
        std::cout << "Empty queue" << std::endl;
        return;
    }
    myNode* temp = Front;
    if (Front == Back) {
        Front = Back = nullptr;
    } else {
        Front = Front->next;
    }
    delete temp;
    queueSize--;
}

bool myQueue::empty() const {
    return (Front == nullptr && Back == nullptr);
}

myQueue::~myQueue() {
    while (!empty()) {
        pop();
    }
}

void myQueue::enqueue(char value) {
    myNode* temp = new myNode();
    temp->value = value;
    temp->next = nullptr;
    if (empty()) {
        Front = Back = temp;
    } else {
        Back->next = temp;
        Back = temp;
    }
    queueSize++;
}

char myQueue::back() const{
    return Back->value;
}

char myQueue::front() const{
    return Front->value;
}
