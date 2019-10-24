/*******************************************************************************
*@author  Evan Trout
*@file    MinHeap.h
*@date    10/14/19
*@brief   Header file for MinHeap class, which stores an array of integers and
*         contains methods for organizing and modifying that array as a a minheap
*******************************************************************************/

#include <string>

#ifndef MIN_HEAP
#define MIN_HEAP

class MinHeap
{
private:
    int* heap; // contents of heap stored as array of integers
    int curSize; // current size of the heap
    int MAX_SIZE; // maximum capacity of the heap
public:
    /**
    * @pre MinHeap constructor is called
    * @return MinHeap with heap initialized to array of 15000
    **/
    MinHeap();

    /**
    * @pre MinHeap destructor is called
    * @post Deallocates all memory used by class instance
    **/
    ~MinHeap();
    
    /**
    * @post builds initial heap from file of values, and reports time taken
    * @param fileName: file to be opened containing values to be inserted
    **/
    void buildHeap(std::string fileName);

    /**
    * @post inserts the given value and carries out swaps til heap condition is satisfied
    * @param x: integer to be added to heap
    * @return true if successful, otherwise false
    **/    
    bool insert(int x);

    /**
    * @post Removes the root and returns it, then calls heapify to maintain heap conditions
    * @return int value of root, or -1 if heap is empty
    **/
    int remove();
    
    /**
    * @pre called by remove
    * @post recursively maintains heap conditions
    * @param i: current index in heap
    **/    
    void heapify(int i);
    
    /**
    * @return -1 if tree is empty, otherwise root value
    **/
    int pq_highest();
    
    /**
    * @post searches leaves for lowest priority value
    * @return -1 iof tree is empty, otherwise lowest priority value
    **/
    int pq_lowest();
    
    /**
    * @post prints contents of heap in levelorder
    **/
    void levelorder();
    
    /**
    * @post calls pq_highest and prints the amount of time it takes
    * @return value from pq_highest
    **/
    int time_highest_pq();

    /**
    * @post calls pq_lowest and prints the amount of time it takes
    * @return value from pq_lowest
    **/
    int time_lowest_pq();
    
    /**
    * @post calls remove and prints the amount of time it takes
    * @return value from remove
    **/
    int time_delete_pq();
    
    /**
    * @param parent: index value of parent
    * @return index of left child of parent
    **/
    int left(int parent);
    
    /**
    * @param parent: index value of parent
    * @return index of middle child of parent
    **/
    int middle(int parent);
    
    /**
    * @param parent: index value of parent
    * @return index of right child of parent
    **/
    int right(int parent);
    
    /**
    * @param child: index value of child
    * @return index value of parent of child
    **/
    int parent(int child);
    
    /**
    * @post swaps values of two locations in array
    * @param x: first location in swap
    * @param y: second location in swap
    **/
    void swap(int *x, int *y);
};
#endif
