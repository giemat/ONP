cmake_minimum_required(VERSION 3.28)
project(ONP)

set(CMAKE_CXX_STANDARD 17)

add_executable(ONP main.cpp
        myNode.cpp
        myStack.h
        myStack.cpp
        myQueue.cpp)
