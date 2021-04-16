#include "include/private/HashToShortURLConverter.h"

#include <algorithm>

HashToShortURLConverter::HashToShortURLConverter() {

}

HashToShortURLConverter::~HashToShortURLConverter() {

}

std::string HashToShortURLConverter::HashToShortURL(std::size_t hash) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    std::string shortUrl;
    while (hash) {
        shortUrl.push_back(alphabet[hash % 62]);
        hash /= 62;
    }

    std::reverse(shortUrl.begin(), shortUrl.end());
    return shortUrl;
}

std::size_t HashToShortURLConverter::ShortURLToHash(const std::string &shortUrl) {
    std::size_t hash = 0;
    for (char const &c: shortUrl) {
        if ('a' <= c  && c <= 'z') {
            hash = hash * 62 + c - 'a';
        }
        if ('A' <= c && c <= 'Z') {
            hash = hash * 62 + c - 'A' + 26;
        }
        if ('0' <= c && c <= '9') {
            hash = hash * 62 + c - '0' + 52;
        }
    }

    return hash;
}
