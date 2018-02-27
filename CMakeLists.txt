cmake_minimum_required (VERSION 2.6)
project (algs)

file(GLOB algs_src ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_subdirectory("src/")
add_subdirectory("test/")
