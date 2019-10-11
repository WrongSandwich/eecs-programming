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
    int heap[15000];
public:
    MinHeap();
    ~MinHeap();
    // Build using top-down approach. Should also print time taken to built
    void heapify();
    bool insert(int x);
    void remove();
    void pq_highest();
    void pq_lowest();
    void levelorder();
    void time_lowest_pq();
};
#endif
