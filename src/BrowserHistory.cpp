#include "../includes/BrowserHistory.hpp"

BrowserHistory::BrowserHistory()
    : navHistory(std::list<Webpage>()),
      navPos(navHistory.begin()),
      sitesVisited(std::list<Webpage>()),
      numSites(0){};

std::string BrowserHistory::back() {
  // while we're not at the front
  if (navPos != navHistory.begin()) {
    auto back = std::prev(navPos, 1);
    navPos--;
    return back->getUrl();
  }
  throw new std::bad_alloc;
}
std::string BrowserHistory::forward() {
  // https://en.cppreference.com/w/cpp/iterator/next
  if (navPos != navHistory.end()) {
    auto next = std::next(navPos, 1);
    navPos++;
    return next->getUrl();
  }

  else {
    throw new std::bad_alloc();
  }
}
std::string BrowserHistory::getUrl() {
  if (!navHistory.empty() || !sitesVisited.empty()) {
    return navPos->getUrl();
  } else {
    throw std::logic_error("site does not exist");
  }
}
void BrowserHistory::visitSite(Webpage newSite) {
  this->navHistory.push_back(newSite);
  this->sitesVisited.push_back(newSite);

  ++numSites;

  if (this->navHistory.size() > 1) {
    while (navPos != std::next(navHistory.end(), -1)) {
      navHistory.pop_back();
    }
    navHistory.push_back(newSite);
    navPos = std::next(navHistory.end(), -1);
  } else {
    navPos = navHistory.begin();
  }
}

void BrowserHistory::readHistory(std::string fileName) {
  std::string directionIndicator, url_;
  std::ifstream inFile(fileName);

  while (inFile >> directionIndicator) {
    if (directionIndicator == "new") {
      long long int newTime;

      inFile >> url_ >> newTime;
      // was wondering why this is broken, copy constructor not properly
      // constructed...
      Webpage newSite = Webpage(
          url_,
          time_t(newTime));  // time_t(long long int&) <-- called type casting
      visitSite(newSite);
    } else if (directionIndicator == "back") {
      back();
    } else if (directionIndicator == "forward") {
      forward();
    } else {
      throw new std::logic_error("invalid command");
    }
  }
  inFile.close();
}
size_t BrowserHistory::getNavSize() { return navHistory.size(); }

void BrowserHistory::print() {
  for (auto element : this->navHistory) {
    std::cout << element.getUrl() << std::endl;
    std::cout << element.getTime() << std::endl;
  }
}

std::list<Webpage> BrowserHistory::getSitesVisited() { return sitesVisited; }
