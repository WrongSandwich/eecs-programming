/*******************************************************************************
*@author  Evan Trout
*@file    MaxHeap.cpp
*@date    10/14/19
*@brief   Implementation file for MaxHeap class, which stores an array of integers and
*         contains methods for organizing and modifying that array as a a MaxHeap
*******************************************************************************/

#include "MaxHeap.h"
#include <math.h>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>

MaxHeap::MaxHeap()
{
    heap = new int[15000];
    curSize = 0;
    MAX_SIZE = 15000;
}

MaxHeap::~MaxHeap()
{
    delete [] heap;
}

void MaxHeap::buildHeap(std::string fileName)
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
        std::cout << "MaxHeap build completed in " << duration << " microseconds\n";
    }
    else
    {
        throw std::runtime_error("ERROR: Could not open file");
    }
}

bool MaxHeap::insert(int x)
{
    if (curSize == MAX_SIZE || x < 1)
    {
        return false;
    }
    // insert x into end of heap
    heap[curSize] = x;
    // do swaps until heap satisfies requirements
    int child = curSize;
    int par = parent(child);
    while (child != 0 && heap[par] < heap[child])
    {
        swap(&heap[par], &heap[child]);
        child = par;
        par = parent(child);
    }
    curSize++;
    return true;
}

int MaxHeap::remove()
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

void MaxHeap::heapify(int i)
{
    int l = left(i);
    int m = middle(i);
    int r = right(i);
    int largest = i;
    if (l < curSize && heap[l] > heap[i])
    {
        largest = l;
    }
    if (m < curSize && heap[m] > heap[largest])
    {
        largest = m;
    }
    if (r < curSize && heap[r] > heap[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

int MaxHeap::pq_highest()
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

int MaxHeap::pq_lowest()
{
    if (curSize > 0)
    {
        int i = curSize - 1;
        int min = heap[i];
        int searchBoundary = parent(i);
        i--;
        while (i >= searchBoundary)
        {
            if (heap[i] < min)
            {
                min = heap[i];
            }
            i--;
        }
        return min;
    }
    else
    {
        return -1;
    }
}

void MaxHeap::levelorder()
{
    for (int i = 0; i < curSize; i++)
    {
        std::cout << heap[i] << " ";
    }
}

int MaxHeap::time_highest_pq()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = pq_highest();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Pq_highest completed in " << duration << " microseconds\n";
    return temp;
}

int MaxHeap::time_lowest_pq()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = pq_lowest();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Pq_lowest completed in " << duration << " microseconds\n";
    return temp;
}

int MaxHeap::time_delete_pq()
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

int MaxHeap::left(int parent)
{
    return 3 * parent + 1;
}

int MaxHeap::middle(int parent)
{
    return 3 * parent + 2;
}

int MaxHeap::right(int parent)
{
    return 3 * parent + 3;
}

int MaxHeap::parent(int child)
{
    return floor((child - 1) / 3);
}

void MaxHeap::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}