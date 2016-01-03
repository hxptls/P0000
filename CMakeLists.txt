cmake_minimum_required(VERSION 3.3)
project(P0000)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_C_COMPILER g++ )

set(SOURCE_FILES main.c proc.c proc.h parameters.h parameters.cpp)
add_executable(P0000 ${SOURCE_FILES})
