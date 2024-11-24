cmake_minimum_required(VERSION 3.22)

project(lucrarea5)

set(CMAKE_CXX_STANDARD 14)

include_directories(. src inc)

add_executable(lucrarea5
        src/main.cpp
        src/complex.cpp
        )
