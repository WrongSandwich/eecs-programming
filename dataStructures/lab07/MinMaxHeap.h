/*******************************************************************************
*@author  Evan Trout
*@file    MinMaxHeap.h
*@date    10/24/19
*@brief   Header file for MinMaxHeap class, which stores an array of integers and
*         contains methods for organizing and modifying that array as a a MinMaxHeap
*******************************************************************************/

#include <string>

#ifndef MINMAX_HEAP
#define MINMAX_HEAP

class MinMaxHeap
{
private:
    int* heap; // contents of heap stored as array of integers
    int curSize; // current size of the heap
    int MAX_SIZE; // maximum capacity of the heap
public:
    /**
    * @pre MinMaxHeap constructor is called
    * @return MinMaxHeap with heap initialized to array of 15000
    **/
    MinMaxHeap();

    /**
    * @pre MinMaxHeap destructor is called
    * @post Deallocates all memory used by class instance
    **/
    ~MinMaxHeap();
    
    /**
    * @post builds initial heap from file of values, and reports time taken
    * @param fileName: file to be opened containing values to be inserted
    **/
    void buildHeap(std::string fileName);

    /**
    * @post inserts the given value at end of heap, then calls functions to satisfy heap requirements
    * @param x: integer to be added to heap
    * @return true if successful, otherwise false
    **/    
    bool insert(int x);

    /**
    * @pre called by another function
    * @param index: index to be checked
    * @return true if on a min level, otherwise false
    **/
    bool isMinLevel(int index);

    /**
    * @post makes swaps with grandparents to maintain min part of heap
    * @param index: index being checked
    **/
    void checkMin(int index);

    /**
    * @post makes swaps with grandparents to maintain max part of heap
    * @param index: index being checked
    **/
    void checkMax(int index);

    /**
    * @post Removes the root and returns it, then calls trickledowns to maintain heap conditions
    * @return true if successful, otherwise false
    **/
    bool remove(int target);

    /**
    * @post uses swaps and recursive calls to maintain min heap condition after a delete
    * @param index: index to be checked
    **/
    void trickleDownMin(int index);

    /**
    * @post uses swaps and recursive calls to maintain min heap condition after a delete
    * @param index: index to be checked
    **/
    void trickleDownMax(int index);

    /**
    * @pre called by another function
    * @param search: integer being searched for
    * @return index where target was found, or -1 if not found
    **/
    int findElement(int search);
            
    /**
    * @post prints contents of heap in levelorder
    **/
    void levelorder();

    /**
    * @post prints min contents of heap in levelorder
    **/
    void printMinElements();

    /**
    * @post prints max contents of heap in levelorder
    **/
    void printMaxElements();
        
    /**
    * @param parent: index value of parent
    * @return index of left child of parent
    **/
    int left(int parent);
    
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
    * @param child: index value of child
    * @return index value of grandparent of child
    **/
    int grand(int child);

    /**
    * @param index: index value being checked
    * @return current level of the array
    **/
    int level(int index);
    
    /**
    * @post swaps values of two locations in array
    * @param x: first location in swap
    * @param y: second location in swap
    **/
    void swap(int *x, int *y);
};
#endif
