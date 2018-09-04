/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 7 - Exercise 3
 * Description: Array manipulation program.
 * Date: 03/12/18
 * ------------------------------------------------------------------------------- */
 #include <iostream>

//Function to insert a new value in the array.
int* insert(int array[], int size, int value, int position)
{
  int* insertArray = nullptr;
  insertArray = new int[size];
  for(int i = 0; i < size; i++)
  {
    insertArray[i] = 0;
  }
  insertArray[position] = value;
  for(int i = 0; i < position; i++)
  {
    insertArray[i] = array[i];
  }
  int j = 0;
  for(int i = (position + 1); i < size; i++)
  {
    j = i - 1;
    insertArray[i] = array[j];
  }
  delete[] array;
  return(insertArray);
}
//Function to remove a value from the array.
int* remove(int array[], int size, int position)
{
  int* removeArray = nullptr;
  removeArray = new int[size];
  for(int i = 0; i < size; i++)
  {
    removeArray[i] = 0;
  }
  for(int i = 0; i < position; i++)
  {
    removeArray[i] = array[i];
  }
  int j = 0;
  for(int i = position; i < size; i++)
  {
    j = i + 1;
    removeArray[i] = array[j];
  }
  delete[] array;
  return(removeArray);
}
//Function to count the number of instances of a target number.
int count(int array[], int size, int search)
{
  int y = 0;
  for(int i = 0; i < size; i++)
  {
    if(array[i] == search)
    {
      y = y + 1;
    }
  }
  return(y);
}
//Function that prints array.
void print(int array[], int size)
{
  std::cout << "[";
  for(int i = 0; i < size; i++)
  {
    std::cout << array[i];
    if (i != (size-1))
    {
      std::cout << ", ";
    }
    else{
      std::cout << "]\n";
    }
  }
}
int main()
{
  //Initial creation and filling of the array.
  int* array = nullptr;
  int size;
  std::cout << "Please enter a size for the array: ";
  std::cin >> size;
  array = new int[size];
  int x = 0;
  for(int i = 0; i < size; i++)
  {
    std::cout << "Please enter an integer to be added to the array: ";
    std::cin >> x;
    array[i] = x;
  }
  //User menu.
  int userChoice = 0;
  do {
    std::cout << "Make a selection:\n1) Insert\n2) Remove\n3) Count\n";
    std::cout << "4) Print\n5) Exit\nChoice: ";
    std::cin >> userChoice;
    //User selected "Insert".
    if (userChoice == 1) {
      int position = 0;
      int value = 0;
      do {
        std::cout << "Enter the position for your new value: ";
        std::cin >> position;
      } while(position < 0 || position > size);
      std::cout << "Enter the value you would like inserted: ";
      std::cin >> value;
      size = size + 1;
      array = insert(array, size, value, position); //Not sure if int arr is supposed to be array here.
    }
    //User selected "Remove".
    else if (userChoice == 2) {
      int position = 0;
      do {
        std::cout << "Enter the position of the value you'd like removed: ";
        std::cin >> position;
      } while(position < 0 && position > size);
      size = size - 1;
      array = remove(array, size, position);
    }
    //User selected "Count".
    else if (userChoice == 3) {
      int search = 0;
      int x = 0;
      std::cout << "Enter the value you would like to search for: ";
      std::cin >> search;
      x = count(array, size, search);
      std::cout << "The integer " << search << " is found in the array ";
      std::cout << x << " times.\n";
    }
    //User selected "Print".
    else if (userChoice == 4) {
      print(array, size);
    }
    else if (userChoice == 5) {
      std::cout << "Goodbye!\n";
    }
    else
    {
      std::cout << "ERROR: Please enter a valid selection.\n";
    }
  } while(userChoice != 5);
  delete[] array;
}
