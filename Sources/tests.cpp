#define CATCH_CONFIG_MAIN

#include <iostream>

#include "include/private/ShortLinkServer.h"
#include "include/private/HashToShortURLConverter.h"
#include "include/private/URLCodec.h"
#include "3rdParties/catch.hpp"

TEST_CASE("HashToURL", "[HashURLConversion]") {

    CHECK(HashToShortURLConverter::HashToShortURL(1)  == "b");
}

TEST_CASE("Encode URL", "[Codec]") {

    std::string url = "https://codereview.stackexchange.com/questions/173618/generate-a-unique-numeric-identifier-for-each-instance-of-a-class/173635";

    std::string domainUrl = "http://short.est/";
    URLCodec codec(domainUrl);
    auto shortUrl = codec.Encode(url);

    std::cout << shortUrl << std::endl;
    CHECK(!shortUrl.empty());
    CHECK(shortUrl.find(domainUrl) != std::string::npos);
}
