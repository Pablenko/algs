set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -Wall -g")

find_package(GTest REQUIRED)
find_package (Threads)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB algs_tests_src "*.hpp" "*.cpp")

add_executable(algs_tests ${algs_tests_src} ${algs_src})
target_link_libraries(algs_tests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
