#include "Graph.h"
#include "Edge.h"
#include <iostream>

Graph::Graph() : size(0), edges(nullptr)
{ }

void Graph::buildGraph(int sizeIn, int ** edgesIn)
{
    size = sizeIn;
    edges = new Edge*[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (edgesIn[i][j] > 1)
            {
                Edge * tempPtr = getTail(i);
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

void Graph::printGraph()
{
    for (int i = 0; i < size; i++)
    {
        printVert(i);
    }
}

void Graph::printVert(int index)
{
    std::cout << index + 1 << ": ";
    Edge * curPtr = edges[index];
    while (curPtr != nullptr)
    {
        std::cout << curPtr->dst + 1 << '(' << curPtr->cost << "), ";
        curPtr = curPtr->next;
    }
    std::cout << '\n';
}

Edge* Graph::getTail(int index)
{
    if (edges[index] == nullptr)
    {
        return nullptr;
    }
    else
    {
        Edge * tempPtr = edges[index];
        while (1)
        {
            if (tempPtr->next == nullptr)
            {
                return tempPtr;
            }
            tempPtr = tempPtr->next;
        }
    }
}