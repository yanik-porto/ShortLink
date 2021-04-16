cmake_minimum_required(VERSION 3.5)

project(ShortLink LANGUAGES CXX)


find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ShortLink Sources/main.cpp)
target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache)
