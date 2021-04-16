#include "private/URLCodec.h"
#include "include/private/HashToShortURLConverter.h"

#include <functional>
#include <string>

URLCodec::URLCodec() {

}

URLCodec::~URLCodec() {

}

std::string URLCodec::Encode(const std::string &originalURL) {

    std::size_t hash = std::hash<std::string>{}(originalURL);
    auto shortUrl = HashToShortURLConverter::HashToShortURL(hash)
    _hashToUrlMap.emplace(hash, shortUrl);
    return shortUrl;
}

std::string URLCodec::Decode(const std::string &shortURL) {
    std::size_t hash = HashToShortURLConverter::ShortURLToHash(shortURL);
    auto it = _hashToUrlMap.find(hash);
    if (it != _hashToUrlMap.end()) {
        return it->second;
    }
}

