cmake_minimum_required(VERSION 3.27)
project(gator_avl)

set(CMAKE_CXX_STANDARD 14)

include_directories(test-unit)

add_executable(gator_avl
        src/AVL.h
        src/AVL.cpp
        src/main.cpp)