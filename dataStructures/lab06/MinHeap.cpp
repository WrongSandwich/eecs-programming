/*******************************************************************************
*@author  Evan Trout
*@file    MinHeap.cpp
*@date    10/14/19
*@brief   Implementation file for MinHeap class, which stores an array of integers and
*         contains methods for organizing and modifying that array as a a minheap
*******************************************************************************/

#include "MinHeap.h"
#include <math.h>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>

MinHeap::MinHeap()
{
    heap = new int[15000];
    curSize = 0;
    MAX_SIZE = 15000;
}

MinHeap::~MinHeap()
{
    delete [] heap;
}

void MinHeap::buildHeap(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        int temp;
        auto t1 = std::chrono::high_resolution_clock::now();
        while (inFile >> temp)
        {
            if (!insert(temp))
            {
                throw std::runtime_error("ERROR: Invalid item in data file, please fix and run again");
            }
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << "Minheap build completed in " << duration << " microseconds\n";
    }
    else
    {
        throw std::runtime_error("ERROR: Could not open file");
    }
}

bool MinHeap::insert(int x)
{
    // TODO: guard against duplicates?
    if (curSize == MAX_SIZE || x < 1)
    {
        return false;
    }
    // insert x into end of heap
    heap[curSize] = x;
    // do swaps until heap satisfies requirements
    int child = curSize;
    int par = parent(child);
    while (child != 0 && heap[par] > heap[child])
    {
        swap(&heap[par], &heap[child]);
        child = par;
        par = parent(child);
    }
    curSize++;
    return true;
}

int MinHeap::remove()
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

void MinHeap::heapify(int i)
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

int MinHeap::pq_highest()
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

int MinHeap::pq_lowest()
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

void MinHeap::levelorder()
{
    for (int i = 0; i < curSize; i++)
    {
        std::cout << heap[i] << " ";
    }
}

int MinHeap::time_highest_pq()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = pq_highest();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Pq_highest completed in " << duration << " microseconds\n";
    return temp;
}

int MinHeap::time_lowest_pq()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = pq_lowest();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Pq_lowest completed in " << duration << " microseconds\n";
    return temp;
}

int MinHeap::time_delete_pq()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = remove();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Remove completed in " << duration << " microseconds\n";
    return temp;
}

//////////////////////////////////
///// Index Helper Functions /////
//////////////////////////////////

int MinHeap::left(int parent)
{
    return 3 * parent + 1;
}

int MinHeap::middle(int parent)
{
    return 3 * parent + 2;
}

int MinHeap::right(int parent)
{
    return 3 * parent + 3;
}

int MinHeap::parent(int child)
{
    return floor((child - 1) / 3);
}

void MinHeap::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}