cmake_minimum_required(VERSION 3.8)

set(This STLExercises)

project(${This} C CXX)

set(CMAKE_CSTANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Headers/main.hpp)
set(Sources
    main.cpp)

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test) 