#include "mergesort.cpp"
#include "bubbleSort.cpp"
#include "quicksort.cpp"
#include "selectionSort.cpp"
#include "insertionSort.cpp"
#include "Executive.h"

#include <string>
#include <ctime>
#include <stdexcept>
#include <random>
#include <stdlib.h>

Executive::Executive(std::string size, std::string array_order, std::string algName)
{
  srand48(1334); //Reseeding random number generator
  double* array = nullptr;
  data_size = std::stoi(size, nullptr, 10);
  algorithm_name = algName;
  data_order = array_order;
  if (data_order == "random")
  {
    array = randomArray();
  }
  else if (data_order == "ascending")
  {
    array = ascendingArray();
  }
  else if (data_order == "descending")
  {
    array = descendingArray();
  }
  else throw std::runtime_error("Invalid data order type");
}

Executive::~Executive()
{
  delete[] array;
}

double* Executive::randomArray()
{
  double* newArray = nullptr;
  newArray = new double[data_size];
  for (int i = 0; i < data_size; i++)
  {
    newArray[i] = drand48() * 100000.0;
  }
  return newArray;
}

double* Executive::ascendingArray()
{
  double* newArray = nullptr;
  newArray = new double[data_size];
  for (int i = 0; i < data_size; i++)
  {
    newArray[i] = 0.001*static_cast<double>(i);
  }
  return newArray;
}

double* Executive::descendingArray()
{
  double* newArray = nullptr;
  newArray = new double[data_size];
  for (int i = 0; i < data_size; i++)
  {
    newArray[i] = 0.001*static_cast<double>(data_size - i - 1);
  }
  return newArray;
}

void Executive::run()
{
  double timer = searchTimer();
  std::cout << "Array size = " << data_size << '\n';
  std::cout << "Algorithm used = " << algorithm_name << '\n';
  std::cout << "Array order = " << data_order << '\n';
  std::cout << "Time to sort = " << timer << '\n';
}

double Executive::searchTimer()
{
  clock_t start, end, diff;
  double runtime;
  if (algorithm_name == "selection")
  {
    start = clock();
    selectionSort(array, data_size);
    end = clock();
  }
  else if (algorithm_name == "insertion")
  {
    start = clock();
    insertionSort(array, data_size);
    end = clock();
  }
  else if (algorithm_name == "bubble")
  {
    start = clock();
    bubbleSort(array, data_size);
    end = clock();
  }
  else if (algorithm_name == "merge")
  {
    start = clock();
    mergeSort(array, data_size);
    end = clock();
  }
  else if (algorithm_name == "quick")
  {
    start = clock();
    quickSort(array, 0, data_size);
    end = clock();
  }
  else throw std::runtime_error("Invlaid search algorithm name");
  diff = end - start; //Clock ticks consumed by sort algorithm
  runtime = diff/CLOCKS_PER_SEC; //Converting to seconds
  return runtime;
}
