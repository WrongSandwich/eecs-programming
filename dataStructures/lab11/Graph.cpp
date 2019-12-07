#include "Graph.h"
#include "Edge.h"
#include "DisjointSet.h"
#include <iostream>
#include <list>

Graph::Graph() : size(0), edges(nullptr)
{
}

void Graph::buildGraph(int sizeIn, int **edgesIn)
{
    size = sizeIn;
    edges = new Edge *[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (edgesIn[i][j] > 1)
            {
                Edge *tempPtr = getTail(edges[i]);
                if (tempPtr == nullptr)
                {
                    edges[i] = new Edge(i, j, edgesIn[i][j]);
                }
                else
                {
                    tempPtr->next = new Edge(i, j, edgesIn[i][j]);
                }
            }
        }
    }
}

void Graph::BFS()
{
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
    }
    Edge **results = new Edge *[2];
    BFSHelper(results, 0, visited);
    for (int i = 0; i < size; i++)
    {
        Edge *curEdge = edges[i];
        while (curEdge != nullptr)
        {
            int curSrc = curEdge->src;
            int curDst = curEdge->dst;
            if (!isRepeat(curSrc, curDst, results[0]) && !isRepeat(curSrc, curDst, results[1]))
            {
                Edge *tailPtr = getTail(results[1]);
                if (tailPtr == nullptr)
                {
                    results[1] = new Edge(curSrc, curDst, curEdge->cost);
                }
                else
                {
                    tailPtr->next = new Edge(curSrc, curDst, curEdge->cost);
                }
            }
            curEdge = curEdge->next;
        }
    }
    // Print the results
    std::cout << "Tree Edges: ";
    printEdgeList(results[0]);
    std::cout << "Cross Edges: ";
    printEdgeList(results[1]);
}

void Graph::BFSHelper(Edge **results, int index, bool *visited)
{
    Edge *curEdge = edges[index];
    visited[index] = true;
    std::list<int> targets = {};
    while (curEdge != nullptr)
    {
        int curDst = curEdge->dst;
        if (!visited[curDst]) // not visited -> it's a tree edge, must be traversed
        {
            Edge *tailPtr = getTail(results[0]);
            if (tailPtr == nullptr)
            {
                results[0] = new Edge(curEdge->src, curEdge->dst, curEdge->cost);
            }
            else
            {
                tailPtr->next = new Edge(curEdge->src, curEdge->dst, curEdge->cost);
            }
            visited[curDst] = true;
            targets.push_back(curDst);
        }
        curEdge = curEdge->next;
    }
    while (!targets.empty())
    {
        int cur = targets.front();
        BFSHelper(results, cur, visited);
        targets.pop_front();
    }
}

void Graph::DFS()
{
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
    }
    Edge **results = new Edge *[2];
    DFSHelper(results, 0, visited);
    for (int i = 0; i < size; i++)
    {
        Edge *curEdge = edges[i];
        while (curEdge != nullptr)
        {
            int curSrc = curEdge->src;
            int curDst = curEdge->dst;
            if (!isRepeat(curSrc, curDst, results[0]) && !isRepeat(curSrc, curDst, results[1]))
            {
                Edge *tailPtr = getTail(results[1]);
                if (tailPtr == nullptr)
                {
                    results[1] = new Edge(curSrc, curDst, curEdge->cost);
                }
                else
                {
                    tailPtr->next = new Edge(curSrc, curDst, curEdge->cost);
                }
            }
            curEdge = curEdge->next;
        }
    }
    // Print the results
    std::cout << "Tree Edges: ";
    printEdgeList(results[0]);
    std::cout << "Back Edges: ";
    printEdgeList(results[1]);
}

void Graph::DFSHelper(Edge **results, int index, bool *visited)
{
    Edge *curEdge = edges[index];
    visited[index] = true;
    while (curEdge != nullptr)
    {
        int curDst = curEdge->dst;
        if (!visited[curDst]) // not visited -> it's a tree edge, must be traversed
        {
            Edge *tailPtr = getTail(results[0]);
            if (tailPtr == nullptr)
            {
                results[0] = new Edge(curEdge->src, curEdge->dst, curEdge->cost);
            }
            else
            {
                tailPtr->next = new Edge(curEdge->src, curEdge->dst, curEdge->cost);
            }
            DFSHelper(results, curDst, visited);
        }
        curEdge = curEdge->next;
    }
}

void Graph::Kruskal()
{
    int weight = 0;
    std::list<Edge *> edgeList = {};
    for (int i = 0; i < size; i++)
    {
        Edge *curPtr = edges[i];
        while (curPtr != nullptr)
        {
            edgeList.push_back(curPtr);
            curPtr = curPtr->next;
        }
    }
    edgeList.sort([](Edge *lhs, Edge *rhs) { return lhs->cost < rhs->cost; });
    DisjointSet set;
    int *inputArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        inputArray[i] = i;
    }
    set.loadArray(inputArray, size);
    set.makeSet();
    for (auto edge : edgeList)
    {
        int srcRep = set.find(edge->src);
        int dstRep = set.find(edge->dst);
        if (srcRep != dstRep)
        {
            printEdge(edge);
            weight += edge->cost;
            set.unionDS(srcRep, dstRep);
        }
    }
    std::cout << "\nTotal cost: " << weight << '\n';
}

void Graph::Prim()
{
    // initializing all tracking variables
    const int MAX_WEIGHT = 100000;
    int weight = 0;
    int *minCost = new int[size];
    Edge **minEdge = new Edge *[size];
    bool *connected = new bool[size];
    for (int i = 0; i < size; i++)
    {
        minCost[i] = MAX_WEIGHT;
        minEdge[i] = nullptr;
        connected[i] = false;
    }
    std::list<Edge *> tree = {};
    // store all edges in a list for convenient parsing
    std::list<Edge *> edgeList = {};
    for (int i = 0; i < size; i++)
    {
        Edge *curPtr = edges[i];
        while (curPtr != nullptr)
        {
            edgeList.push_back(curPtr);
            curPtr = curPtr->next;
        }
    }
    // add initial vertex
    connected[0] = true;
    // loop to carry out Prim
    bool finished = Prim_updateFinished(connected);
    while (!finished)
    {
        Prim_updateCosts(connected, minCost, minEdge, edgeList);
        int index = Prim_findMinEdge(connected, minCost);
        // Add min edge to tree
        weight += minCost[index];
        tree.push_back(minEdge[index]);
        connected[index] = true;
        finished = Prim_updateFinished(connected);
    }
    // finished, need to print results
    for (auto edge : tree)
    {
        printEdge(edge);
    }
    std::cout << "\nTotal cost: " << weight << '\n';
}

void Graph::Prim_updateCosts(bool *connected, int *minCost, Edge **minEdge, std::list<Edge *> edgeList)
{
    for (auto edge : edgeList)
    {
        if (connected[edge->src] && !connected[edge->dst] && (edge->cost < minCost[edge->dst]))
        {
            minCost[edge->dst] = edge->cost;
            minEdge[edge->dst] = edge;
        }
    }
}

int Graph::Prim_findMinEdge(bool *connected, int *minCost)
{
    int minimum = minCost[0];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (minCost[i] < minimum && !connected[i])
        {
            minimum = minCost[i];
            index = i;
        }
    }
    return index;
}

bool Graph::Prim_updateFinished(bool * connected)
{
    for (int i = 0; i < size; i++)
    {
        if (!connected[i])
        {
            return false;
        }
    }
    return true;
}

// HELPER FUNCTIONS

void Graph::printEdgeList(Edge *curPtr)
{
    while (curPtr != nullptr)
    {
        std::cout << '(' << curPtr->src + 1 << ',' << curPtr->dst + 1 << ") ";
        curPtr = curPtr->next;
    }
    std::cout << '\n';
}

void Graph::printGraph()
{
    for (int i = 0; i < size; i++)
    {
        printVert(edges[i], i);
    }
}

void Graph::printVert(Edge *curPtr, int index)
{
    std::cout << index + 1 << ": ";
    while (curPtr != nullptr)
    {
        std::cout << curPtr->dst + 1 << '(' << curPtr->cost << "), ";
        curPtr = curPtr->next;
    }
    std::cout << '\n';
}

void Graph::printEdge(Edge *target)
{
    std::cout << '(' << target->src + 1 << ", " << target->dst + 1 << "){";
    std::cout << target->cost << "} ";
}

Edge *Graph::getTail(Edge *curPtr)
{
    if (curPtr == nullptr)
    {
        return nullptr;
    }
    else
    {
        while (1)
        {
            if (curPtr->next == nullptr)
            {
                return curPtr;
            }
            curPtr = curPtr->next;
        }
    }
}

bool Graph::isRepeat(int src, int dst, Edge *curList)
{
    while (curList != nullptr)
    {
        if ((src == curList->dst && dst == curList->src) || (src == curList->src && dst == curList->dst))
        {
            return true;
        }
        curList = curList->next;
    }
    return false;
}

bool Graph::isCycle(int src, int dst, Edge *curList)
{
    bool srcFound = false;
    bool dstFound = false;
    while (curList != nullptr)
    {
        int curSrc = curList->src;
        int curDst = curList->dst;
        if (src == curSrc || src == curDst)
        {
            srcFound = true;
        }
        if (dst == curSrc || dst == curDst)
        {
            dstFound = true;
        }
        curList = curList->next;
    }
    if (srcFound && dstFound)
    {
        return true;
    }
    return false;
}

// std::list<Edge*> Graph::sortEdges()
// {
//     std::list<Edge*> edgeList = {};
//     for (int i = 0; i < size; i++)
//     {
//         Edge* curPtr = edges[i];
//         while (curPtr != nullptr)
//         {
//             edgeList.push_back(curPtr);
//             curPtr = curPtr->next;
//         }
//     }
//     edgeList.sort([](Edge * lhs, Edge * rhs) {return lhs->cost < rhs->cost;});
//     for (auto edge : edgeList)
//     {
//         std::cout << edge->cost << ' ';
//     }
//     std::cout << '\n';
// }
