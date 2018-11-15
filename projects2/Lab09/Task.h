#ifndef TASK
#define TASK

#include <string>

class Task
{
private:
  int taskID;
  std::string taskName;
  int estimatedTimeToComplete;
  int timeAddedToBST;
  int timeStarted;
public:
  Task(int newID, std::string newName, int newEstimate, int currentTime);
  void printStats();
  void getID();
  void startTask(int currentTime);
};
#endif
