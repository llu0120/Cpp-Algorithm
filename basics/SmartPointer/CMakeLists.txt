cmake_minimum_required(VERSION 3.5.1)  # CMake version check
project(C++_algorithm)               # Create project "simple_example"

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(unique UniquePtr.cpp)
add_executable(shared SharedPtr.cpp)
add_executable(cr CircularReference.cpp) 
add_executable(weak WeakPtr.cpp) 

SET(CMAKE_CXX_FLAGS "-std=c++0x")
