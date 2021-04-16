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
    static std::string HashToShortURL(std::size_t hash);

    /**
     * @brief convert the short URL back to the corresponding hash
     * @param[in] shortUrl The short url to convert
     * @return the corresponding hash
     */
    static std::size_t ShortURLToHash(const std::string &shortUrl);
};

#endif // URLTOHASHCONVERTER_H
