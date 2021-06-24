## Brief

ShortLink is a URL shortening service where you enter a URL such as https://codesubmit.io/library/react and it returns a short URL such as http://short.est/GeAi9K.

## Dependencies

The code can be compiled with a C++!17 compiler. 
Here is the list of commands to run in a linux terminal in order to install the dependencies.

### cmake

sudo apt-get update -y
sudo apt-get install -y cmake

### pistache : the chosen framework

$ sudo add-apt-repository ppa:pistache+team/unstable
$ sudo apt update
$ sudo apt install libpistache-dev

### nlohmann_json : a json parser

sudo apt-get update -y
sudo apt-get install -y nlohmann-json-dev

### libcurl : send http request for testing the API

$ sudo apt update
$ sudo apt upgrade
$ sudo apt install curl libcurl4-openssl-dev




## Running the code

Compile the code by with the help of the CMakeList.txt file.

Two executables and a library are provided.
The library ShortLinkLib provides an API with /decode /encode endpoints. 
The ShortLink executable runs the server.
The ShortLinkTests executable runs tests on the server enpoints.

Runs ShortLink executable for starting the server and either runs the ShortLinkTests executable or send http requests with curl or Postman for example.

Encoding request example :
curl -d '{"url":"https://github.com/pistacheio/pistache/blob/master/examples/http_server.cc"}' -X POST http://localhost:9080/encode

Decoding request example : 
curl -d '{"shortUrl":"http://short.est/rQrVIOEFzIg"}' -X POST http://localhost:9080/decode
