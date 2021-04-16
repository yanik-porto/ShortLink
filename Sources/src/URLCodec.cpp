#include "private/URLCodec.h"
#include "include/private/HashToShortURLConverter.h"

#include <functional>
#include <string>

URLCodec::URLCodec(const std::string &domainUrl) :
    _domainUrl(domainUrl) {

}

URLCodec::~URLCodec() {

}

std::string URLCodec::Encode(const std::string &originalURL) {

    std::size_t hash = std::hash<std::string>{}(originalURL);
    auto shortUrl = HashToShortURLConverter::HashToShortURL(hash);
    _hashToUrlMap.emplace(hash, shortUrl);
    return _domainUrl + shortUrl;
}

std::string URLCodec::Decode(const std::string &shortURL) {
    if (shortURL.size() <= _domainUrl.size()) {
        throw "url size is smaller than the domain size";
    }
    auto shortUrlWithoutDomain = shortURL.substr(0, _domainUrl.size());

    std::size_t hash = HashToShortURLConverter::ShortURLToHash(shortURL);
    auto it = _hashToUrlMap.find(hash);
    if (it != _hashToUrlMap.end()) {
        return it->second;
    }
}

