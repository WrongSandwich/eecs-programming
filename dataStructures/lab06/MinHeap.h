/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    09/25/19
*@brief   Header file for Executive class, which creates and modifies a
*         BinarySearchTree
*******************************************************************************/


#ifndef MIN_HEAP
#define MIN_HEAP

class MinHeap
{
private:
    int* heap;
    int curSize;
    int maxSize;
public:
    MinHeap(int size);
    ~MinHeap();
    // Build using top-down approach. Should also print time taken to built
    void heapify(int* inputs, int size);
    bool insert(int x);
    int remove();
    int pq_highest();
    int pq_lowest();
    void levelorder();
    void time_lowest_pq();
};
#endif
