cmake_minimum_required(VERSION 3.28)

project(homework1)

set(CMAKE_CXX_STANDARD 14)

include_directories(. src inc)

add_executable(homework1
        src/main.cpp
        inc/main.hpp)
