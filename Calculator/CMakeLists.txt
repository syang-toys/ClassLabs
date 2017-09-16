cmake_minimum_required(VERSION 3.7)
project(Lab4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp NaiveQueue.cpp NaiveQueue.h utils.cpp utils.h Calculator.cpp Calculator.h)
add_executable(Lab4 ${SOURCE_FILES})