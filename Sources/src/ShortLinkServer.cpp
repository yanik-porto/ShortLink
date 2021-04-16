#include "include/private/ShortLinkServer.h"
#include "include/private/URLCodec.h"

#include <nlohmann/json.hpp>

ShortLinkServer::ShortLinkServer() {

}

ShortLinkServer::~ShortLinkServer() {

}

void ShortLinkServer::Start() {
        Address addr(Ipv4::any(), Port(9080));
        Http::listenAndServe<CodecHandler>(addr);
}

CodecHandler::CodecHandler() :
    Http::Handler(),
    _codec(new URLCodec("http://short.est/")){

}

CodecHandler::~CodecHandler() {
    if (_codec) {
        delete _codec;
    }
}

void CodecHandler::onRequest(const Http::Request& request, Http::ResponseWriter response) {

    if(request.resource() == "/encode") {
        if (request.method() == Http::Method::Get) {
            auto jsonBody = nlohmann::json::parse(request.body());
            if (jsonBody.find("url") != jsonBody.end()) {
                auto shortUrl = _codec->Encode(jsonBody["url"]);

                nlohmann::json jsonRes;
                jsonRes["shortUrl"] = shortUrl;

                response.send(Http::Code::Ok, jsonRes.dump(), MIME(Text, Json));
            }

        }
    } else if (request.resource() == "/decode") {
        if (request.method() == Http::Method::Get) {
            auto jsonBody = nlohmann::json::parse(request.body());
            if (jsonBody.find("shortUrl") != jsonBody.end()) {
                auto decodedUrl = _codec->Decode(jsonBody["shortUrl"]);

                nlohmann::json jsonRes;
                jsonRes["url"] = decodedUrl;

                response.send(Http::Code::Ok, jsonRes.dump(), MIME(Text, Json));
            }
        }
    }
}
