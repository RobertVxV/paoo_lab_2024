cmake_minimum_required(VERSION 3.28)

project(lucrarea4)

set(CMAKE_CXX_STANDARD 14)

include_directories(. src inc)

add_executable(lucrarea4
        src/main.cpp
        src/dreptunghi.cpp
        )
