#include "include/private/ShortLinkServer.h"
#include "include/private/URLCodec.h"

ShortLinkServer::ShortLinkServer() :
    _codec(new URLCodec()){

}

ShortLinkServer::~ShortLinkServer() {
    if(_codec) {
        delete _codec;
    }
}

void ShortLinkServer::Start() {
        Address addr(Ipv4::any(), Port(9080));
        Http::listenAndServe<CodecHandler>(addr);
}
void CodecHandler::onRequest(const Http::Request& request, Http::ResponseWriter response) {

    if(request.resource() == "/encode") {
        if (request.method() == Http::Method::Get) {
        }
    } else if (request.resource() == "/decode") {
        if (request.method() == Http::Method::Get) {
        }
    }
}
