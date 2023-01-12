cmake_minimum_required(VERSION 3.8)

set(This StandartTests)

set(Sources
    MainTests.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    STLExercises
)

add_test(
    NAME ${This}
    COMMAND ${This}
)