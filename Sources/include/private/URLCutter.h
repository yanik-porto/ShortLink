#ifndef URLCUTTER_H
#define URLCUTTER_H

#include <iostream>

#include "include/public/IURLCutter.h"

/**
 * @brief The IURLCutter concrete class cuts the domain name from a given URL and provides the shorten website URI
 */
class URLCutter : public IURLCutter {
public:
    explicit URLCutter(const std::string &domainName);
    ~URLCutter();

    std::string GetURI(const std::string &fullUrl) ;

private:
    std::string _domainName;
};

#endif // URLCUTTER_H
