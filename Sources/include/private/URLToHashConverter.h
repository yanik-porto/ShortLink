#ifndef URLTOHASHCONVERTER_H
#define URLTOHASHCONVERTER_H

#include <string>

/**
 * @brief The URLToHashConverter concrete class provides a unique hash for a given URL
 */
class URLToHashConverter {
public:
    URLToHashConverter();
    ~URLToHashConverter();

    unsigned int URLToHash(const std::string &url) const;
};

#endif // URLTOHASHCONVERTER_H
