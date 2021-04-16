#ifndef URLCODEC_H
#define URLCODEC_H

#include "include/public/IURLCodec.h"

/**
 * @brief The URLCodec class encodes and decodes URL to and from a shorter version
 */
class URLCodec : public IURLCodec {
public:
    URLCodec();
    virtual ~URLCodec();

    /**
     * @brief encode an URL to a shorten one
     */
    void encode() override;

    /**
     * @brief decode the original URL from the shorten one previously generated
     */
    void decode() override;
};

#endif // URLCODEC_H
