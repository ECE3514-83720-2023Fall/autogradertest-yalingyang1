cmake_minimum_required(VERSION 3.9...3.19)
project(Exercise24 CXX)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.x
)

FetchContent_MakeAvailable(Catch2)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build tests
add_executable(unit_tests catch.hpp unit_tests.cpp
  stopwatch.hpp stopwatch.cpp test_stopwatch.cpp
  algorithms_sort.hpp test_algorithms.cpp)

add_executable(benchmark_find benchmark_algorithms.cpp stopwatch.hpp stopwatch.cpp)

add_executable(instructor_tests catch.hpp unit_tests.cpp
  stopwatch.hpp stopwatch.cpp test_stopwatch.cpp
  algorithms_sort.hpp instructor_tests.cpp)

