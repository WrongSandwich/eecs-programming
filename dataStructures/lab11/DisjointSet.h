#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include "Node.h"
#include <string>

class DisjointSet {
private:
    int setSize;
    Node** array;
public:
    DisjointSet(std::string fileName, int sizeIn);
    ~DisjointSet();
    void makeSet();
    int unionDS(int x, int y);
    int find(int x);
    Node* findHelper(Node* curPtr);
    int find_timer(int x);
    int index(int x);
};

#endif