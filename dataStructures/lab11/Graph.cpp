#include "Graph.h"
#include "Edge.h"
#include <iostream>

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