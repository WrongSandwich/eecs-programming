/*******************************************************************************
*@author  Evan Trout
*@file    WebBrowser.h
*@date    09/19/2018
*@brief   Implementation file for the WebBrowser class. Translates actions by
*         the executive class from browser commands into commands for the
*         LinkedList class. Derived from WebBrowserInterface.
*******************************************************************************/

#ifndef WEB_BROWSER_H
#define WEB_BROWSER_H
#include "WebBrowserInterface.h"
#include "LinkedList.h"
#include <string>

class WebBrowser : public WebBrowserInterface
{
private:
LinkedList<std::string> ll;
int current;

public:

  /**
  * @post creates a WebBrowser and initializes current to 0
  * @return returns the WebBrowser
  */
  WebBrowser();

  /**
  * @post all memory is freed and the WebBrowser is deleted
  */
  ~WebBrowser();

  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  void navigateTo(std::string url);

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
  void forward();

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL
  */
  void back();

  /**
  * @return the current URL
  */
  std::string currentURL() const;

  /**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list
  * @param destination, an empty list of strings that will have a copy of current history copied into
  */
  void copyCurrentHistory(LinkedList<std::string>& destination);

  /**
  * @pre none
  * @post Prints all urls contained in ll with some formatting
  */
  void printHistory();
};

#endif
