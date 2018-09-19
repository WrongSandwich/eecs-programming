#ifndef WEB_BROWSER_H
#define WEB_BROWSER_H
#include "WebBrowserInterface.h"
#include "LinkedList.h"
#include <string>

class WebBrowser : public WebBrowserInterface
{
private:
LinkedList<std::string>* ll;
int position;

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
