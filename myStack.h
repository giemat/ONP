
#ifndef MYSTACK_H
#define MYSTACK_H


#include "myNode.h"

class myStack {
private:
    myNode* Top;
    int stackSize;
public:
    myStack() = default;
    void push(char value);
    void intPush(int value);
    void pop();
    [[nodiscard]] char top() const;
    [[nodiscard]] int intTop() const;
    [[nodiscard]] bool empty() const;
    void print() const;
    ~myStack();
};


#endif //MYSTACK_H
