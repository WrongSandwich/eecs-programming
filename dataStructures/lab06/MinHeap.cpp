#include "MinHeap.h"
#include <math.h>
#include <chrono>
#include <iostream>

MinHeap::MinHeap(int size)
{
    heap = new int[size];
    curSize = 0;
    MAX_SIZE = size;
}

MinHeap::~MinHeap()
{
    delete [] heap;
}

void MinHeap::buildHeap(int* inputs, int size)
{
    bool temp = false;
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        temp = insert(inputs[i]);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Heapify completed in " << duration << " microseconds\n";
}

bool MinHeap::insert(int x)
{
    if (curSize == MAX_SIZE)
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
        int lastElement = heap[curSize - 1];
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

void MinHeap::time_highest_pq()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = pq_highest();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Pq_lowest completed in " << duration << " microseconds\n";
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