#ifndef URLTOHASHCONVERTER_H
#define URLTOHASHCONVERTER_H

#include <string>

/**
 * @brief The HashToShortURLConverter concrete class convert a given hash to a short URL
 */
class HashToShortURLConverter {
public:
    HashToShortURLConverter();
    ~HashToShortURLConverter();

    /**
     * @brief convert a given hash to a short URL
     * @param[in] hash The url hash to convert
     * @return the corresponding short url
     */
    std::string HashToShortURL(unsigned int hash) const;

    /**
     * @brief convert the short URL back to the corresponding hash
     * @param[in] shortUrl The short url to convert
     * @return the corresponding hash
     */
    unsigned int ShortURLToHash(const std::string &shortUrl) const;
};

#endif // URLTOHASHCONVERTER_H
