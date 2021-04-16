#ifndef URLCODEC_H
#define URLCODEC_H

#include <map>

#include "include/public/IURLCodec.h"

/**
 * @brief The URLCodec concrete class encodes and decodes URL to and from a shorter version
 */
class URLCodec : public IURLCodec {
public:
    explicit URLCodec(const std::string &domainUrl);
    virtual ~URLCodec();

    /**
     * @brief encode an URL to a shorten one
     * @param[in] originalURL The original URL to encode
     * @return the encoded short URL
     */
    virtual std::string Encode(const std::string &originalURL) override;

    /**
     * @brief decode the original URL from the shorten one previously generated
     * @param[in] shortURL The short URL to decode
     * @return the decoded original URL
     */
    virtual std::string Decode(const std::string &shortURL) override;

private:
    std::string _domainUrl;
    std::map<std::size_t, std::string> _hashToUrlMap;
};

#endif // URLCODEC_H
