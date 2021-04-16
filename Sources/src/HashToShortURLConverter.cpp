#include "include/private/HashToShortURLConverter.h"

#include <algorithm>

HashToShortURLConverter::HashToShortURLConverter() {

}

HashToShortURLConverter::~HashToShortURLConverter() {

}

std::string HashToShortURLConverter::HashToShortURL(unsigned int hash) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";

    std::string shortUrl;
    while (hash) {
        shortUrl.push_back(alphabet[hash % 36]);
        hash /= 36;
    }

    std::reverse(shortUrl.begin(), shortUrl.end());
    return shortUrl;
}

unsigned int HashToShortURLConverter::ShortURLToHash(const std::string &shortUrl) {

}
