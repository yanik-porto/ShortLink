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

private:
    IURLCodec *_codec;
};

class CodecHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(CodecHandler)

    /**
     * @brief listen the request and send the corresponding response
     * @param[in]  request The http request received
     * @param[out] response The http response to the request
     */
    void onRequest(const Http::Request& request, Http::ResponseWriter response) override;
};

#endif // SHORTLINKSERVER_H
