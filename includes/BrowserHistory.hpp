#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include <string>

#include "Webpage.hpp"

class BrowserHistory {
 public:
  BrowserHistory();

  void visitSite(Webpage newSite);
  std::string back();
  std::string forward();

  void readHistory(std::string fileName);

  std::string getUrl();
  size_t getNavSize();
  std::list<Webpage> getSitesVisited();

  void print();

 private:
  std::list<Webpage> navHistory;
  std::list<Webpage>::iterator navPos;
  std::list<Webpage> sitesVisited;
  size_t numSites;
};

