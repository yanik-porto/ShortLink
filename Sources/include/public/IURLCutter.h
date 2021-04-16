#ifndef IURLCUTTER_H
#define IURLCUTTER_H

/**
 * @brief The IURLCutter abtract class cuts the domain name from a given URL and provides the shorten website URI
 */
class IURLCutter {
public:
    virtual ~IURLCutter() {};

    /**
     * @brief get the website URI from the full URL
     * @param fullUrl The full website URL
     * @return the corresponding website shorten URI
     */
    std::string GetURI(const std::string &fullUrl);
};

#endif // IURLCUTTER_H
