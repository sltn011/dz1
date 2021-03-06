cmake_minimum_required(VERSION 3.10.2)
project(HTTP)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(coroutine STATIC src/coroutines/coroutine.cpp)
add_library(data STATIC src/data/Descriptor.cpp)
add_library(exceptions STATIC src/exceptions/Exceptions.cpp)
add_library(HTTP STATIC src/HTTP/BaseHTTPServer.cpp src/HTTP/HTTPMessage.cpp src/HTTP/HTTPMessageData.cpp)
add_library(log STATIC src/log/Log.cpp src/log/Loggers.cpp)
add_library(tcp STATIC src/tcp/ConnectionAsync.cpp src/tcp/SocketAsync.cpp src/tcp/Connection.cpp src/tcp/Socket.cpp)
add_library(bigFile STATIC src/bigFile/Mmap.cpp)

target_link_libraries(bigFile HTTP coroutine data exceptions log pthread tcp)

add_executable(fileServer example/server.cpp)
add_executable(fileClient example/client.cpp)
add_executable(fileGenerator example/fileGenerator.cpp)

target_link_libraries(fileServer bigFile)
target_link_libraries(fileClient bigFile)
