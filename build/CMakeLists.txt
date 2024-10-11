cmake_minimum_required(VERSION 3.1)

project(WordSearcher)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/../bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/../src)

add_executable(Searcher ../src/main.cpp)



find_package(GTest REQUIRED) 
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Tests ../test/main_test.cpp ../test/tests.cpp)
target_link_libraries(Tests ${GTEST_LIBRARIES})

