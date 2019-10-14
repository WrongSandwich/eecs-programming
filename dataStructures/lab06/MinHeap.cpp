#include "MinHeap.h"
#include <math.h>
#include <chrono>
#include <iostream>

MinHeap::MinHeap(int size)
{
    heap = new int[size];
    curSize = 0;
    maxSize = size;
}

MinHeap::~MinHeap()
{
    delete [] heap;
}

// void MinHeap::heapify(int* inputs, int size)
// {
//     auto t1 = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < size; i++)
//     {
//         insert(inputs[i]);
//     }
//     auto t2 = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
//     std::cout << "Heapify completed in " << duration << " microseconds\n";
// }

bool MinHeap::insert(int x)
{
    // insert x into end of heap
    heap[curSize] = x;
    // do swaps until heap satisfies requirements
    int child = curSize;
    int parent = floor((child-1)/3);
    while (child != 0 && heap[parent] > heap[child])
    {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = floor((child-1)/3);
    }
    curSize++;
}

int MinHeap::remove()
{
    int lastElement = heap[curSize - 1];
    int pop = heap[0];
    heap[0] = lastElement;
}

int MinHeap::pq_highest()
{
    if (curSize > 0)
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        int target = heap[0];
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << "Pq_highest completed in " << duration << " microseconds\n";
        return target;
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
        // auto t1 = std::chrono::high_resolution_clock::now();
        int i = curSize - 1;
        int max = heap[i];
        int searchBoundary = floor((i-1)/3);
        i--;
        while (i >= searchBoundary)
        {
            if (heap[i] > max)
            {
                max = heap[i];
            }
            i--;
        }
        // auto t2 = std::chrono::high_resolution_clock::now();
        // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        // std::cout << "Pq_lowest completed in " << duration << " microseconds\n";
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

void MinHeap::time_lowest_pq()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = pq_lowest();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Pq_lowest completed in " << duration << " microseconds\n";
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