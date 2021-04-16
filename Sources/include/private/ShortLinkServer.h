#ifndef SHORTLINKSERVER_H
#define SHORTLINKSERVER_H

#include <pistache/endpoint.h>

using namespace Pistache;

class ShortLinkServer {
public:
    ShortLinkServer();
    virtual ~ShortLinkServer();
    void Start();
};

class CodecHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(CodecHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) override;
};

#endif // SHORTLINKSERVER_H
