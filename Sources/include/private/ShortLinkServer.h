#ifndef SHORTLINKSERVER_H
#define SHORTLINKSERVER_H

#include <pistache/endpoint.h>
#include "include/public/IURLCodec.h"

using namespace Pistache;

class ShortLinkServer {
public:
    ShortLinkServer();
    virtual ~ShortLinkServer();

    /**
     * @brief start the server
     */
    void Start();
};

class CodecHandler : public Http::Handler {
public:
    CodecHandler();
    ~CodecHandler();

    HTTP_PROTOTYPE(CodecHandler)

    /**
     * @brief listen the request and send the corresponding response
     * @param[in]  request The http request received
     * @param[out] response The http response to the request
     */
    void onRequest(const Http::Request& request, Http::ResponseWriter response) override;

private:
    IURLCodec *_codec;
};

#endif // SHORTLINKSERVER_H
