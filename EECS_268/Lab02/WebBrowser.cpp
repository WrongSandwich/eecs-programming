/*******************************************************************************
*@author  Evan Trout
*@file    WebBrowser.cpp
*@date    09/19/2018
*@brief   Implementation file for the WebBrowser class. Translates actions by
*         the executive class from browser commands into commands for the
*         LinkedList class. Derived from WebBrowserInterface.
*******************************************************************************/

#include <iostream>
#include <string>
#include "WebBrowser.h"
#include "WebBrowserInterface.h"
#include "LinkedList.h"

WebBrowser::WebBrowser() : current(0)
{
}

WebBrowser::~WebBrowser()
{

}

void WebBrowser::navigateTo(std::string url)
{
  //Add a new node with given url and navigate to it
  //If there are nodes after current one, must delete them
  int length = ll.getLength();
  if (current == length) //Currently at end of ll
  {
    ll.insert((current+1), url);
    current++;
  }
  else //Navigating in the middle of history list
  {
    ll.insert((current + 1), url);
    current++;
    length++;
    while (length != current)
    {
      ll.remove(length);
      length = length - 1;
    }
  }
}

void WebBrowser::forward()
{
  //Move to next node if there is one
  if (current < ll.getLength())
  {
    current++;
  }
}

void WebBrowser::back()
{
  //Move to previous node if there is one
  if (current > 1)
  {
    current = current - 1;
  }
}
std::string WebBrowser::currentURL() const
{
  //Retrieve current url and return it
  return ll.getEntry(current);
}

void WebBrowser::copyCurrentHistory(LinkedList<std::string>& destination)
{
  int length = ll.getLength();
  for (int i = 1; i <= length; i++)
  {
    destination.insert(i, ll.getEntry(i));
  }
}

void WebBrowser::printHistory()
{
  std::cout << "Oldest\n==========\n";
  for (int i = 1; i <= ll.getLength(); i++)
  {
    std::cout << ll.getEntry(i);
    if (i == current)
    {
      std::cout << " <==current";
    }
    std::cout << '\n';
  }
  std::cout << "==========\nNewest\n\n";
}
