#include "private/URLCodec.h"
#include "include/private/HashToShortURLConverter.h"

#include <functional>
#include <string>
#include <iostream>


URLCodec::URLCodec(const std::string &domainUrl) :
    _domainUrl(domainUrl) {

}

URLCodec::~URLCodec() {

}

std::string URLCodec::Encode(const std::string &originalURL) {

    std::size_t hash = std::hash<std::string>{}(originalURL);
    auto shortUrl = HashToShortURLConverter::HashToShortURL(hash);
    _hashToUrlMap.emplace(hash, originalURL);
    return _domainUrl + shortUrl;
}

std::string URLCodec::Decode(const std::string &shortURL) {
    if (shortURL.size() <= _domainUrl.size()) {
        throw "url size is smaller than the domain size";
    }
    auto shortUrlWithoutDomain = shortURL.substr(_domainUrl.size(), shortURL.size());

    std::size_t hash = HashToShortURLConverter::ShortURLToHash(shortUrlWithoutDomain);
    auto it = _hashToUrlMap.find(hash);
    if (it != _hashToUrlMap.end()) {
        return it->second;
    }
}

