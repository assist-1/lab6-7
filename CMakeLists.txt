cmake_minimum_required(VERSION 3.23)
project(lesson)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_library(function.h classes.cpp function.cpp function.h googletests/test.cpp)

add_subdirectory(googletests)

add_executable(lesson main.cpp
        classes.cpp
        function.h
        function.cpp)