#include "include/private/HashToShortURLConverter.h"

#include <algorithm>

HashToShortURLConverter::HashToShortURLConverter() {

}

HashToShortURLConverter::~HashToShortURLConverter() {

}

std::string HashToShortURLConverter::HashToShortURL(std::size_t hash) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";

    std::string shortUrl;
    while (hash) {
        shortUrl.push_back(alphabet[hash % 36]);
        hash /= 36;
    }

    std::reverse(shortUrl.begin(), shortUrl.end());
    return shortUrl;
}

std::size_t HashToShortURLConverter::ShortURLToHash(const std::string &shortUrl) {
    std::size_t hash;
    for (char const &c: shortUrl) {
        if ('a' <= c  && c <= 'z') {
            hash = hash * 36 + c - 'a';
        }
        if ('0' <= c && c <= '9') {
            hash = hash * 36 + c - '0' + 26;
        }
    }

    return hash;
}
