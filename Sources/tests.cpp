#define CATCH_CONFIG_MAIN

#include <iostream>

#include "include/private/ShortLinkServer.h"
#include "include/private/HashToShortURLConverter.h"

#include "3rdParties/catch.hpp"

TEST_CASE("HashToURL", "[HashURLConversion]") {

    CHECK(HashToShortURLConverter::HashToShortURL(1)  == "b");

}
