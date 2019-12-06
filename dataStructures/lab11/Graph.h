#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"

class Graph {
private:
    int size;
    Edge ** edges;
public:
    Graph();
    void buildGraph(int sizeIn, int ** edgesIn);
    void printGraph();
    void printVert(int index);
    Edge* getTail(int index);
};

#endif