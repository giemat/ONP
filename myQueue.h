
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "myNode.h"

class myQueue {
private:
    myNode* Front;
    myNode* Back;
    int queueSize;
public:
    myQueue() = default;
    void pop();
    void enqueue(char value);
    [[nodiscard]] char back() const;
    [[nodiscard]] char front() const;
    [[nodiscard]] bool empty() const;
    ~myQueue();
};



#endif //MYQUEUE_H
