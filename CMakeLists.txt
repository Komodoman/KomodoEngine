cmake_minimum_required(VERSION 3.2)
project(Komodo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Komodo ${SOURCE_FILES} LogManager.cpp LogManager.h Manager.h)