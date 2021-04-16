#ifndef IURLCODEC_H
#define IURLCODEC_H

class IURLCodec {
public:
    virtual ~IURLCodec() {};

    /**
     * @brief encode an URL to a shorten one
     */
    virtual void encode() = 0;

    /**
     * @brief decode the original URL from the shorten one previously generated
     */

    virtual void decode() = 0;
};

#endif // IURLCODEC_H
