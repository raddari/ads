cmake_minimum_required(VERSION 3.17)
project(ads)

set(CMAKE_C_STANDARD 11)

add_subdirectory(deps/unity)

include_directories(include)

add_library(array SHARED)

add_subdirectory(src)
add_subdirectory(test)