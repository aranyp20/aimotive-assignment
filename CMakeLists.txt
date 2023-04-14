cmake_minimum_required(VERSION 3.0)

project(aimotive)

include_directories(${PROJECT_NAME} src src/fields)

add_executable(${PROJECT_NAME} src/main.cpp src/map.cpp src/hexa_converter.cpp src/fields/empty_field.cpp src/fields/field.cpp src/fields/starting_field.cpp src/fields/target_field.cpp src/fields/wall_field.cpp)