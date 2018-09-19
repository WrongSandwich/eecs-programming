#include <iostream>
#include <string>
#include "WebBrowser.h"
#include "WebBrowserInterface.h"
#include "LinkedList.h"

//Need to create a LinkedList in this code
WebBrowser::WebBrowser() : position(0)
{
}

WebBrowser::~WebBrowser()
{

}

void WebBrowser::navigateTo(std::string url)
{
  //Add a new node with given url and navigate to it
  //If there are nodes after current one, must delete them
  if (position == ll.getLength()) //Currently at end of ll
  {
    ll.insert((position+1), url); //throw precondviolatedexcep???
  }
  else //Navigating in the middle of history list
  {
    while {ll.getLength() > position} //Delete forward history
    {
      ll.remove(position + 1);
    }
    ll.insert(position + 1, url); //throw precondviolatedexcep??
  }
  position++; //Move to new url in list
}

void WebBrowser::forward()
{
  //Move to next node if there is one
  if (position < ll.getLength())
  {
    position++;
  }
}

void WebBrowser::back()
{
  //Move to previous node if there is one
  if (position > 1)
  {
    position = position - 1;
  }
}
std::string WebBrowser::currentURL() const
{
  //Retrieve current url and return it
  return ll.getEntry(position);
}

void WebBrowser::copyCurrentHistory(LinkedList<string>& destination)
{
  int length = ll.getLength();
  for (int i = 1; i <= length; i++)
  {
    destination.insert(i, ll.getEntry(i))
  }
}

void WebBrowser::printHistory()
{
  std::cout << "Oldest\n==========\n";
  for (int i = 1; i <= ll.getLength(); i++)
  {
    std::cout << ll.getEntry(i);
    if (i == position)
    {
      std::cout << " <==current";
    }
    std::cout << '\n';
  }
  std::cout << "==========\nNewest\n";
}
