cmake_minimum_required(VERSION 3.5)

project(ShortLink LANGUAGES CXX)


find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ShortLink Sources/main.cpp)
add_executable(ShortLinkTests Sources/tests.cpp)

get_filename_component(
    PROJECT_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ABSOLUTE
)

set (CMAKE_HEADER_DIR ${PROJECT_DIR}/Sources)
set (CMAKE_SOURCE_DIR ${PROJECT_DIR}/Sources)
set (CMAKE_INCLUDE_PATH ${CMAKE_HEADER_DIR}/include)
set (ROOT_PUBLIC_INCLUDE_DIR ${CMAKE_INCLUDE_PATH}/public)
set (ROOT_PRIVATE_INCLUDE_DIR ${CMAKE_INCLUDE_PATH}/private)
set (ROOT_SOURCES_DIR ${CMAKE_SOURCE_DIR}/src)
set (3RD_PARTIES_DIR ${PROJECT_DIR}/3rdParties)

include_directories(${PROJECT_DIR} ${CMAKE_HEADER_DIR} ${CMAKE_INCLUDE_PATH})

add_library(ShortLinkLib STATIC
    ${ROOT_PUBLIC_INCLUDE_DIR}/IURLCodec.h
    ${ROOT_PUBLIC_INCLUDE_DIR}/IURLCutter.h
    ${ROOT_PRIVATE_INCLUDE_DIR}/URLCutter.h
    ${ROOT_PRIVATE_INCLUDE_DIR}/URLCodec.h
    ${ROOT_PRIVATE_INCLUDE_DIR}/HashToShortURLConverter.h
    ${ROOT_PRIVATE_INCLUDE_DIR}/ShortLinkServer.h
    ${ROOT_SOURCES_DIR}/ShortLinkServer.cpp
    ${ROOT_SOURCES_DIR}/URLCodec.cpp
    ${ROOT_SOURCES_DIR}/URLCutter.cpp
    ${ROOT_SOURCES_DIR}/HashToShortURLConverter.cpp
    ${3RD_PARTIES_DIR}/catch.hpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC  ${CMAKE_SOURCE_DIR}/
    PUBLIC  ${ROOT_PUBLIC_INCLUDE_DIR}
    PRIVATE ${ROOT_PRIVATE_INCLUDE_DIR}
    )

target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache ShortLinkLib)
target_link_libraries(ShortLinkTests PkgConfig::Pistache ShortLinkLib)
