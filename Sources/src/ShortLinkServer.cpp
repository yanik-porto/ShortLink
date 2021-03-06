#include "include/private/ShortLinkServer.h"
#include "include/private/URLCodec.h"

#include <nlohmann/json.hpp>

ShortLinkServer::ShortLinkServer() {
    Address addr(Ipv4::any(), Port(9080));
    auto opts = Http::Endpoint::options().threads(2);
    _server = new Http::Endpoint(addr);
    _server->init(opts);
    _server->setHandler(Http::make_handler<CodecHandler>());
}

ShortLinkServer::~ShortLinkServer() {
    if(_server) {
        _server->shutdown();
        delete _server;
    }
}

void ShortLinkServer::Start() {
        std::cout << "Serving the API on http://localhost:9080/" << std::endl;
        _server->serve();
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
        if (request.method() == Http::Method::Post) {
            auto jsonBody = nlohmann::json::parse(request.body());
            if (jsonBody.find("url") != jsonBody.end()) {
                auto shortUrl = _codec->Encode(jsonBody["url"]);

                nlohmann::json jsonRes;
                jsonRes["shortUrl"] = shortUrl;
                response.send(Http::Code::Ok, jsonRes.dump(), MIME(Text, Json));
            }
        }
    } else if (request.resource() == "/decode") {
        if (request.method() == Http::Method::Post) {
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
