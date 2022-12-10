cmake_minimum_required(VERSION 3.16)
project(laba_PL_6_7)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_library(header.hpp function.cpp header.hpp)

add_subdirectory(googletests)

add_executable(main main.cpp header.hpp function.cpp)
