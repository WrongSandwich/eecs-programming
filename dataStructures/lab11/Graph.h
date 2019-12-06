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
    Edge ** BFS();
    void DFS();
    void DFSHelper(Edge ** results, int index, bool * visited);
    void printEdgeList(Edge* curPtr);
    void printGraph();
    void printVert(Edge* curPtr, int index);
    Edge* getTail(Edge* curPtr);
    bool isRepeat(int src, int dst, Edge * curList);
};

#endif