# Top-Level CMakeList.txt
cmake_minimum_required(VERSION 3.4)
enable_language(CXX)
add_definitions(-std=c++11)

include_directories(include)
file(GLOB aaa_header_files "include/*.hpp")

PROJECT(aaa)
add_executable(test_aaa tests/main.cpp ${aaa_header_files})
