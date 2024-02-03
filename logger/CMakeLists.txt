cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE sources "sources/*.hpp" "sources/*.cpp" "include/*.hpp")

add_library(logger SHARED ${sources})
target_include_directories(logger PUBLIC "include/")