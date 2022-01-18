#include "../includes/Webpage.hpp"

Webpage::Webpage() : Webpage("",0){};
Webpage::Webpage(const std::string& url, const time_t& timeVisited){
  url_ = url;
  time_ = timeVisited;
}

Webpage::Webpage(const Webpage& wp){
  url_ = wp.url_;
  time_ = wp.time_;
}
Webpage& Webpage::operator=(const Webpage& webpage){
  url_ = webpage.getUrl();
  time_ = webpage.getTime();
  return *this;
}
Webpage::~Webpage(){}

std::string Webpage::getUrl() const{ return url_; }

time_t Webpage::getTime() const{
  // this will get the current time and store it into a time_t object
  // we can use structs to access certain memebers of the time_t object via pointner but that is beyond the scope of this project
  return time_;
}

std::string Webpage::convertDateToString(time_t time_){
  // if we need to convert between a human readable version
  return std::asctime(std::localtime(&time_));
}

