cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE sources "sources/*.hpp" "sources/*.cpp")

add_executable(server ${sources})
target_link_libraries(server PRIVATE logger)