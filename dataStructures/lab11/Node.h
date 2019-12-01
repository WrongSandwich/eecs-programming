#ifndef NODE_H
#define NODE_H

class Node {
private:
    Node* parent;
    int value;
    int rank;
public:
    Node(const int& valueIn);
    void setValue(const int& valueIn);
    void setParent(Node* parentIn);
    void setRank(const int& valueIn);
    int getValue();
    Node* getParent();
    int getRank();
};

#endif