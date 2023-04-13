cmake_minimum_required(VERSION 3.0)

project(aimotive)

include_directories(${PROJECT_NAME} src src/fields)

add_executable(${PROJECT_NAME} src/main.cpp src/map.cpp)