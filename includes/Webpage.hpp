#pragma once

#include <string>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>
#include <istream>
#include <iomanip>

class Webpage {
public:
    Webpage();
    Webpage(const std::string& webpageUrl, const time_t& timeVisited);
    Webpage(const Webpage&);
    Webpage& operator=(const Webpage& webpage);
    ~Webpage();
    std::string getUrl() const;
    time_t getTime() const;
    std::string convertDateToString(time_t time_);

private:
    std::string url_;
    time_t time_;
};
