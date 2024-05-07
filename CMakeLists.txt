cmake_minimum_required(VERSION 3.25)
project(coursera_black)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined")
include_directories(test_runner_lib profile)
add_subdirectory(test_runner_lib)

# set(SOURCE initial.cpp)

# file(GLOB SOURCE
#   sum.h
#   sum.cpp
#   initial.cpp)

# set(SOURCE week_1/draft.cpp)
# set(SOURCE week_1/san_fail.cpp)
# set(SOURCE week_1/san_fail_next.cpp)

# set(SOURCE week_3/main.cpp)

set(SOURCE week_4/draft.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} test_runner_lib)
