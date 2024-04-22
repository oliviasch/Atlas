cmake_minimum_required(VERSION 3.27)
project(atlas)

set(CMAKE_CXX_STANDARD 14)

add_executable(atlas main.cpp
        Splay.h
        Splay.cpp
        Node.h
        Node.cpp
        RBTree.h
        RBTree.cpp
)
