#ifndef NODE_H
#define NODE_H

class Node {
private:
    Node* parent;
    int value;
public:
    Node(const int& valueIn);
    void setValue(const int& valueIn);
    void setParent(Node* parentIn);
    int getValue();
    Node* getParent();
};

#endif