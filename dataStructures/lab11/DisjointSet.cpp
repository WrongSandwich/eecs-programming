#include "DisjointSet.h"
#include "Node.h"
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>
#include <ostream>

DisjointSet::DisjointSet() : setSize(0), array(nullptr)
{
}

void DisjointSet::loadArray(std::string fileName, int sizeIn)
{
    setSize = sizeIn;
    array = new Node *[setSize];
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
        return -2;
    }
    Node *xNode = array[index(x)];
    Node *yNode = array[index(y)];
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
        yNode->setParent(xNode);
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
    Node *curPtr = array[curIndex];
    return findHelper(curPtr, false)->getValue();
}

void DisjointSet::pathCompress(int x)
{
    int curIndex = index(x);
    if (curIndex == -1)
    {
        return;
    }
    Node *curPtr = array[curIndex];
    findHelper(curPtr, true);
}

Node *DisjointSet::findHelper(Node *curPtr, bool compress)
{
    if (curPtr->getParent() == curPtr)
    {
        return curPtr;
    }
    else
    {
        Node *tempPtr = findHelper(curPtr->getParent(), compress);
        if (compress)
        {
            curPtr->setParent(tempPtr);
        }
        return tempPtr;
    }
}

int DisjointSet::find_timer(int x)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int result = find(x);
    auto t2 = std::chrono::high_resolution_clock::now();
    if (result != -1)
    {
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
        std::cout << "Time taken to find " << x << " is " << duration << " nanoseconds\n";
        return duration;
    }
    else
    {
        std::cout << "Sorry! " << x << " is not found!\n";
        return -1;
    }
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

void DisjointSet::runExperiment()
{
    //UNION ALL ELEMENTS
    std::cout << "UNION ALL ELEMENTS\n";
    for (int i = 1; i < 1000; i = i + 2)
    {
        unionDS(i, i + 1);
    }
    for (int i = 1; i < 1000; i = i + 4)
    {
        if ((i + 2) <= 1000)
        {
            unionDS(i, i + 2);
        }
    }
    for (int i = 1; i < 1000; i = i + 8)
    {
        if ((i + 4) <= 1000)
        {
            unionDS(i, i + 4);
        }
    }
    for (int i = 1; i < 1000; i = i + 16)
    {
        if ((i + 8) <= 1000)
        {
            unionDS(i, i + 8);
        }
    }
    for (int i = 1; i < 1000; i = i + 32)
    {
        if ((i + 16) <= 1000)
        {
            unionDS(i, i + 16);
        }
    }
    for (int i = 1; i < 1000; i = i + 64)
    {
        if ((i + 32) <= 1000)
        {
            unionDS(i, i + 32);
        }
    }
    for (int i = 1; i < 1000; i = i + 128)
    {
        if ((i + 64) <= 1000)
        {
            unionDS(i, i + 64);
        }
    }
    for (int i = 1; i < 1000; i = i + 256)
    {
        if ((i + 128) <= 1000)
        {
            unionDS(i, i + 128);
        }
    }
    for (int i = 1; i < 1000; i = i + 512)
    {
        if ((i + 256) <= 1000)
        {
            unionDS(i, i + 256);
        }
    }
    unionDS(1, 1000);

    //FIRST RUN OF TESTS
    std::cout << "FIRST RUN OF TESTS\n";
    std::ofstream firstRun("first.csv");
    for (int i = 1; i <= 1000; i++)
    {
        int temp = find_timer(i);
        firstRun << temp << '\n';
    }
    firstRun.close();
    //PERFORM PATH COMPRESSION
    std::cout << "PATH COMPRESSION\n";
    for (int i = 1; i <= 1000; i++)
    {
        pathCompress(i);
    }
    //SECOND RUN OF TESTS
    std::cout << "SECOND RUN OF TESTS\n";
    std::ofstream secondRun("second.csv");
    for (int i = 1; i <= 1000; i++)
    {
        int temp = find_timer(i);
        secondRun << temp << '\n';
    }
    secondRun.close();
}