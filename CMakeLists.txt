cmake_minimum_required(VERSION 3.2)
project(Komodo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Komodo ${SOURCE_FILES} src/LogManager.cpp src/LogManager.h src/Manager.h src/utils/Clock.cpp src/utils/Clock.h src/GameManager.cpp src/GameManager.h src/entity_system/framework/Entity.cpp src/entity_system/framework/Entity.h src/entity_system/components/Component.h src/utils/Vector3.cpp src/utils/Vector3.h src/entity_system/framework/EntityManager.cpp src/entity_system/framework/EntityManager.h src/entity_system/components/PositionComponent.cpp src/entity_system/components/PositionComponent.h)