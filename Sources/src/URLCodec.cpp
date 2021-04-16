#include "private/URLCodec.h"
#include "include/private/HashToShortURLConverter.h"

#include <functional>
#include <string>

URLCodec::URLCodec() {

}

URLCodec::~URLCodec() {

}

std::string URLCodec::Encode(const std::string &originalURL) {

    std::size_t strHash = std::hash<std::string>{}(originalURL);
    return HashToShortURLConverter::HashToShortURL(strHash);
}

std::string URLCodec::Decode(const std::string &shortURL) {

}

