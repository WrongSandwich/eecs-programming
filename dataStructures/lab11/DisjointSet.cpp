#include "DisjointSet.h"
#include "Node.h"
#include <string>
#include <fstream>

DisjointSet::DisjointSet() : setSize(0), array(nullptr)
{}
    

void DisjointSet::loadArray(std::string fileName, int sizeIn)
{
    setSize = sizeIn;
    array = new Node*[setSize];
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        int temp;
        //TODO: prevent duplicates
        // populate array with nodes
        for (int i = 0; i < setSize; i++)
        {
            inFile >> temp;
            array[i] = new Node(temp);
        }
    }
    else
    {

    }
}

DisjointSet::~DisjointSet()
{
    for (int i = 0; i < setSize; i++)
    {
        delete array[i];
    }
    delete[] array;
}

void DisjointSet::makeSet()
{
    for (int i = 0; i < setSize; i++)
    {
        array[i]->setParent(array[i]);
    }
}

int DisjointSet::unionDS(int x, int y)
{
    int xRep = find(x);
    int yRep = find(y);
    if (xRep == -1 || yRep == -1)
    {
        return -1;
    }
    if (xRep == yRep)
    {
        return xRep;
    }
    Node* xNode = array[index(x)];
    Node* yNode = array[index(y)];
    int xRank = xNode->getRank();
    int yRank = yNode->getRank();
    if (xRank < yRank)
    {
        xNode->setParent(yNode);
        return xRep;
    }
    else if (xRank > yRank)
    {
        yNode->setParent(xNode);
        return yRep;
    }
    else // ranks are equal
    {
        xNode->setParent(yNode);
        xNode->setRank(xRank + 1);
        return xRep;
    }
}

int DisjointSet::find(int x)
{
    int curIndex = index(x);
    if (curIndex == -1)
    {
        return -1;
    }
    Node* curPtr = array[curIndex];
    return findHelper(curPtr)->getValue();
}

Node* DisjointSet::findHelper(Node* curPtr)
{
    if (curPtr->getParent() == curPtr)
    {
        return curPtr;
    }
    else
    {
        Node* tempPtr = findHelper(curPtr->getParent());
        curPtr->setParent(tempPtr);
        return tempPtr;
    }
}

int find_timer(int x)
{
    return 1;
}

int DisjointSet::index(int x)
{
    for (int i = 0; i < setSize; i++)
    {
        if (array[i]->getValue() == x)
        {
            return i;
        }
    }
    return -1;
}