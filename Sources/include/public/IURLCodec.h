#ifndef IURLCODEC_H
#define IURLCODEC_H

class IURLCodec {
public:
    virtual ~IURLCodec() {};

    virtual void encode() = 0;
    virtual void decode() = 0;
};

#endif // IURLCODEC_H
