cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

project(test_task)

add_subdirectory("logger/")
add_subdirectory("server/")
add_subdirectory("client/")