#
# CMakeLists.txt
# Created by CLion on Jan 1, 2016. Modified by Hexapetalous.
#
# This is a part of P0000, a number division.
#
# Copyright (c) 2016 Hexapetalous. All rights reserved.
# The code is licensed to MIT License.
#

# Because I only have 2.8 in my system.
#cmake_minimum_required(VERSION 3.3)
cmake_minimum_required(VERSION 2.8)
project(P0000)

set(BOOST_DIR "/usr/local/include")
set(BOOST_ROOT "/usr/local/include")
find_package(Boost REQUIRED COMPONENTS
        program_options
        )
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_COMPILER g++ )

set(SOURCE_FILES main.c proc.c proc.h parameters.h parameters.cpp config.h)
add_executable(P0000 ${SOURCE_FILES})
target_link_libraries(P0000 ${Boost_LIBRARIES})
