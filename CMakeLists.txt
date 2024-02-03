cmake_minimum_required(VERSION 3.26)
project(Assignment1_Conversion)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment1_Conversion src/main.cpp
        src/htmlConverter.cpp
        inc/htmlConverter.h
)
