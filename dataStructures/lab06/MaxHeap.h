/*******************************************************************************
*@author  Evan Trout
*@file    MaxHeap.h
*@date    10/14/19
*@brief   Header file for MaxHeap class, which stores an array of integers and
*         contains methods for organizing and modifying that array as a a MaxHeap
*******************************************************************************/

#include <string>

#ifndef MAX_HEAP
#define MAX_HEAP

class MaxHeap
{
private:
    int* heap;
    int curSize;
    int MAX_SIZE;
public:
    MaxHeap();
    ~MaxHeap();
    void buildHeap(std::string fileName);
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
