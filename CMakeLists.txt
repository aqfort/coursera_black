cmake_minimum_required(VERSION 3.25)
project(coursera_brown)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(test_runner_lib profile)
add_subdirectory(test_runner_lib)

# set(SOURCE initial.cpp)

file(GLOB SOURCE
    sum.h
    sum.cpp
    initial.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} test_runner_lib)
