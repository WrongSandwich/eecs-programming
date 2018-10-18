#include <time.h>
#include <functional> //allows for passing functions as paramaters
//use clock() instead of time()

double SortTimer::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
  //start a timer

  //call the sort passed to us
  sort(arr, size);

  //stop the timer

  //return the time
}
