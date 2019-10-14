/*******************************************************************************
*@author  Evan Trout
*@file    MinHeap.h
*@date    10/14/19
*@brief   Header file for MinHeap class, which stores an array of integers and
*         contains methods for organizing and modifying that array as a a minheap
*******************************************************************************/


#ifndef MIN_HEAP
#define MIN_HEAP

class MinHeap
{
private:
    int* heap;
    int curSize;
    int MAX_SIZE;
public:
    MinHeap(int size);
    ~MinHeap();
    // Build using top-down approach. Should also print time taken to built
    void buildHeap(int* inputs, int size);
    bool insert(int x);
    int remove();
    void heapify(int i);
    int pq_highest();
    int pq_lowest();
    void levelorder();
    int time_lowest_pq();
    int time_highest_pq();
    int time_delete_pq();
    int left(int parent);
    int middle(int parent);
    int right(int parent);
    int parent(int child);
    void swap(int *x, int *y);
};
#endif
