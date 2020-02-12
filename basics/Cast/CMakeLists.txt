cmake_minimum_required(VERSION 3.5.1)  # CMake version check
project(C++_algorithm)               # Create project "simple_example"

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(static StaticCast.cpp)
add_executable(dynamic DynamicCast.cpp)
add_executable(const ConstCast.cpp) 

SET(CMAKE_CXX_FLAGS "-std=c++0x")
