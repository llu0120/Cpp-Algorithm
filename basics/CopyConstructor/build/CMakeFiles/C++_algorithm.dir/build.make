# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/build

# Include any dependencies generated for this target.
include CMakeFiles/C++_algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C++_algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C++_algorithm.dir/flags.make

CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.o: CMakeFiles/C++_algorithm.dir/flags.make
CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.o: ../CopyConstructor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.o -c /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/CopyConstructor.cpp

CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/CopyConstructor.cpp > CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.i

CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/CopyConstructor.cpp -o CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.s

# Object files for target C++_algorithm
C_______algorithm_OBJECTS = \
"CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.o"

# External object files for target C++_algorithm
C_______algorithm_EXTERNAL_OBJECTS =

C++_algorithm: CMakeFiles/C++_algorithm.dir/CopyConstructor.cpp.o
C++_algorithm: CMakeFiles/C++_algorithm.dir/build.make
C++_algorithm: CMakeFiles/C++_algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C++_algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C++_algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C++_algorithm.dir/build: C++_algorithm

.PHONY : CMakeFiles/C++_algorithm.dir/build

CMakeFiles/C++_algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C++_algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C++_algorithm.dir/clean

CMakeFiles/C++_algorithm.dir/depend:
	cd /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/build /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/build /Users/LuLienHsi/Cpp-Algorithm/basics/CopyConstructor/build/CMakeFiles/C++_algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C++_algorithm.dir/depend

