#ifndef SORTS_H
#define SORTS_H

template<typename T>
class Sorts //static grants access to methods without declaring an instance of this class
{
private:
  static void merge(T* a1, T* a2, int size1, int size2); //used by merge sort to combine two sorted arrays (which are actually two halves of a single array) into a single sorted array
  static void quickSortRec(T arr[], int first, int last, bool median); //sorts array by partitioning the array, quick sorting every left of the pivot, and quick sorting every right of pivot
  //passes median to partition to inform that method how to pick a pivot value
  static void setMedianPivot(T arr[], int first, int last); //used by quicksort; puts median value of array in last position; make sure not to lose any values in the process
  static int partition(T arr[], int first, int last, bool median); //used by quickSort, partitions the array and returns the index of the pivot
  //chooses a pivot based on the median flag, if true uses setMedianPivot, if false selects the last element in the array
public:
  static void bubbleSort(T arr[], int size);
  static void selectionSort(T arr[], int size);
  static void insertionSort(T arr[], int size);
  static void mergeSort(T arr[], int size);
  static void quickSort(T arr[], int size); //Calls quickSortRec with median flag set to false
  static void quickSortWithMedian(T arr[], int size); //Calls quickSortRec with median flag set to true
  static bool isSorted(T arr[], int size); //Returns true only if array is sorted
};

#endif
