#ifndef IURLCODEC_H
#define IURLCODEC_H

#include <string>

/**
 * @brief The IURLCodec astract class encodes and decodes URL to and from a shorter version
 */
class IURLCodec {
public:
    virtual ~IURLCodec() {};

    /**
     * @brief encode an URL to a shorten one
     * @param[in] originalURL The original URL to encode
     * @return the encoded short URL
     */
    virtual std::string Encode(const std::string &originalURL) = 0;

    /**
     * @brief decode the original URL from the shorten one previously generated
     * @param[in] shortURL The short URL to decode
     * @return the decoded original URL
     */
    virtual std::string Decode(const std::string &shortURL) = 0;
};

#endif // IURLCODEC_H
