#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "DisjointSet.h"

class Graph {
private:
    int size;
    Edge ** edges;
public:
    Graph();
    void buildGraph(int sizeIn, int ** edgesIn);
    void BFS();
    void BFSHelper(Edge ** results, int index, bool * visited);
    void DFS();
    void DFSHelper(Edge ** results, int index, bool * visited);
    void Kruskal();
    void printEdgeList(Edge* curPtr);
    void printGraph();
    void printVert(Edge* curPtr, int index);
    void printEdge(Edge* target);
    Edge* getTail(Edge* curPtr);
    bool isRepeat(int src, int dst, Edge * curList);
    bool isCycle(int src, int dst, Edge * curList);
    Edge* sortEdges();
};

#endif