
#ifndef MYNODE_H
#define MYNODE_H



class myNode {
public:
    char value;
    int number;
    myNode* next{};
    myNode() = default;
    myNode(char value, int number, myNode* next);
    explicit myNode(char value);
    explicit myNode(int number);
};



#endif //MYNODE_H
