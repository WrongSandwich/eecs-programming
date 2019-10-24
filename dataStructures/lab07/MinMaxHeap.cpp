/*******************************************************************************
*@author  Evan Trout
*@file    MinMaxHeap.cpp
*@date    10/14/19
*@brief   Implementation file for MinMaxHeap class, which stores an array of integers and
*         contains methods for organizing and modifying that array as a a MinMaxHeap
*******************************************************************************/

#include "MinMaxHeap.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>

MinMaxHeap::MinMaxHeap()
{
    heap = new int[15000];
    curSize = 0;
    MAX_SIZE = 15000;
}

MinMaxHeap::~MinMaxHeap()
{
    delete [] heap;
}

void MinMaxHeap::buildHeap(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        int temp;
        while (inFile >> temp)
        {
            if (!insert(temp))
            {
                throw std::runtime_error("ERROR: Invalid item in data file, please fix and run again");
            }
        }
    }
    else
    {
        throw std::runtime_error("ERROR: Could not open file");
    }
}

bool MinMaxHeap::insert(int x)
{
    if (curSize == MAX_SIZE || x < 1)
    {
        return false;
    }
    // insert x into end of heap
    heap[curSize] = x;
    // satisfy heap requirement
    int child = curSize;
    curSize++;
    int par = parent(child);
    if (isMinLevel(child)) // child is on a min level
    { 
        if (heap[child] > heap[par])
        {
            swap(&heap[par], &heap[child]);
            checkMax(par);
        }
        else
        {
            checkMin(child);
        }
    } 
    else
    {
        if (heap[par] > heap[child])
        {
            swap(&heap[par], &heap[child]);
            checkMin(par);
        }
        else
        {
            checkMax(child);
        }
    }
    return true;
}

bool MinMaxHeap::isMinLevel(int index)
{
    int curLevel = level(index);
    return ((curLevel % 2) == 0);
}

void MinMaxHeap::checkMin(int index)
{
    if (index > 2)
    {
        int gp = grand(index);
        if (heap[gp] > heap[index])
        {
            swap(&heap[gp], &heap[index]);
            checkMin(gp);
        }
    }

}

void MinMaxHeap::checkMax(int index)
{
    if (index > 2)
    {
        int gp = grand(index);
        if (heap[gp] < heap[index])
        {
            swap(&heap[gp], &heap[index]);
            checkMax(gp);
        }
    }

}

int MinMaxHeap::remove()
{
    if (curSize == 0)
    {
        return -1;
    }
    else if (curSize == 1)
    {
        curSize--;
        return heap[0];
    }
    else
    {
        int pop = heap[0];
        heap[0] = heap[curSize - 1];
        curSize--;
        heapify(0);
        return pop;
    }
}

void MinMaxHeap::heapify(int i)
{
    int l = left(i);
    int m = middle(i);
    int r = right(i);
    int smallest = i;
    if (l < curSize && heap[l] < heap[i])
    {
        smallest = l;
    }
    if (m < curSize && heap[m] < heap[smallest])
    {
        smallest = m;
    }
    if (r < curSize && heap[r] < heap[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int MinMaxHeap::pq_highest()
{
    if (curSize > 0)
    {
        return heap[0];
    }
    else
    {
        return -1;
    }
}

int MinMaxHeap::pq_lowest()
{
    if (curSize > 0)
    {
        int i = curSize - 1;
        int max = heap[i];
        int searchBoundary = parent(i);
        i--;
        while (i >= searchBoundary)
        {
            if (heap[i] > max)
            {
                max = heap[i];
            }
            i--;
        }
        return max;
    }
    else
    {
        return -1;
    }
}

void MinMaxHeap::levelorder()
{
    for (int i = 0; i < curSize; i++)
    {
        std::cout << heap[i] << " ";
    }
}

//////////////////////////////////
///// Index Helper Functions /////
//////////////////////////////////

int MinMaxHeap::left(int parent)
{
    return 2 * parent + 1;
}

int MinMaxHeap::right(int parent)
{
    return 2 * parent + 2;
}

int MinMaxHeap::parent(int child)
{
    return floor((child - 1) / 2);
}

int MinMaxHeap::grand(int child)
{
    return parent(parent(child));
}

int MinMaxHeap::level(int index)
{
    index++;
    return floor(log2(index));
}

void MinMaxHeap::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}