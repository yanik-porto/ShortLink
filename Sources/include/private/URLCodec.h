#ifndef URLCODEC_H
#define URLCODEC_H

#include "include/public/IURLCodec.h"

class URLCodec : public IURLCodec {
public:
    URLCodec();
    virtual ~URLCodec();

    void decode() override;
    void encode() override;
};

#endif // URLCODEC_H
