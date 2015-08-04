cmake_minimum_required(VERSION 3.2)
project(Komodo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Komodo ${SOURCE_FILES} src/LogManager.cpp src/LogManager.h src/Manager.h src/utils/Clock.cpp src/utils/Clock.h src/GameManager.cpp src/GameManager.h)