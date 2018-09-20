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
  WebBrowser();
  ~WebBrowser();
  void navigateTo(std::string url);
  void forward();
  void back();
  std::string currentURL() const;
  void copyCurrentHistory(LinkedList<std::string>& destination);
  void printHistory();
};

#endif
