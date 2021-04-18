#define CATCH_CONFIG_MAIN

#include <iostream>
#include <thread>

#include "include/private/ShortLinkServer.h"
#include "include/private/HashToShortURLConverter.h"
#include "include/private/URLCodec.h"
#include "3rdParties/catch.hpp"

#include <curl/curl.h>
#include <nlohmann/json.hpp>


TEST_CASE("HashToURL", "[HashURLConversion]") {

    CHECK(HashToShortURLConverter::HashToShortURL(1)  == "b");
}

TEST_CASE("Encode/Decode URL", "[Codec]") {

    std::string url = "https://codereview.stackexchange.com/questions/173618/generate-a-unique-numeric-identifier-for-each-instance-of-a-class/173635";

    std::string domainUrl = "http://short.est/";
    URLCodec codec(domainUrl);
    auto encodedUrl = codec.Encode(url);

    std::cout << encodedUrl << std::endl;
    CHECK(!encodedUrl.empty());
    CHECK(encodedUrl.find(domainUrl) != std::string::npos);

    auto decodedUrl = codec.Decode(encodedUrl);
    std::cout << decodedUrl << std::endl;
    CHECK(decodedUrl == url);
}


size_t WriteCallback (char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
};

std::string urlStr = "https://github.com/pistacheio/pistache/blob/master/examples/http_server.cc";
std::string shortUrlStr = "http://short.est/rQrVIOEFzIg";

TEST_CASE("Encoding", "[Server]") {
    std::string jsonstr = "{\"url\":\"" + urlStr + "\"}";

    CURL *curl;
    CURLcode res;

    struct curl_slist *headers=NULL; // init to NULL is important
    std::ostringstream oss;

    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:9080/encode");
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonstr.c_str());

      std::string readBuffer;
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);



      /* Check for errors */
      if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
      } else {
          std::cout << "body response : " << readBuffer << std::endl;
          auto jsonBody = nlohmann::json::parse(readBuffer);
          if (jsonBody.find("shortUrl") != jsonBody.end()) {
              auto shortUrl = jsonBody["shortUrl"];
              CHECK( shortUrl == shortUrlStr );
          }
      }

      /* always cleanup */
      curl_easy_cleanup(curl);
    }
}

TEST_CASE("Decoding", "[Server]") {
    std::string jsonstr = "{\"shortUrl\":\"" + shortUrlStr + "\"}";

    CURL *curl;
    CURLcode res;

    struct curl_slist *headers=NULL; // init to NULL is important
    std::ostringstream oss;

    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:9080/decode");
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonstr.c_str());

      std::string readBuffer;
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);

      /* Check for errors */
      if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
      } else {
          std::cout << "body response : " << readBuffer << std::endl;
          auto jsonBody = nlohmann::json::parse(readBuffer);
          if (jsonBody.find("url") != jsonBody.end()) {
              auto originalUrl = jsonBody["url"];
              CHECK( originalUrl == urlStr );
          }
      }

      /* always cleanup */
      curl_easy_cleanup(curl);
    }
}
