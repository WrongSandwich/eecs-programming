#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
    int src;
    int dst;
    int cost;
    Edge* next;
    Edge(int srcIn, int dstIn, int costIn) : src(srcIn), dst(dstIn), cost(costIn), next(nullptr) {}
};

#endif