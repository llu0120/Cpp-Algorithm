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
CMAKE_SOURCE_DIR = /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/build

# Include any dependencies generated for this target.
include CMakeFiles/unique.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unique.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unique.dir/flags.make

CMakeFiles/unique.dir/UniquePtr.cpp.o: CMakeFiles/unique.dir/flags.make
CMakeFiles/unique.dir/UniquePtr.cpp.o: ../UniquePtr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unique.dir/UniquePtr.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unique.dir/UniquePtr.cpp.o -c /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/UniquePtr.cpp

CMakeFiles/unique.dir/UniquePtr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unique.dir/UniquePtr.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/UniquePtr.cpp > CMakeFiles/unique.dir/UniquePtr.cpp.i

CMakeFiles/unique.dir/UniquePtr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unique.dir/UniquePtr.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/UniquePtr.cpp -o CMakeFiles/unique.dir/UniquePtr.cpp.s

# Object files for target unique
unique_OBJECTS = \
"CMakeFiles/unique.dir/UniquePtr.cpp.o"

# External object files for target unique
unique_EXTERNAL_OBJECTS =

unique: CMakeFiles/unique.dir/UniquePtr.cpp.o
unique: CMakeFiles/unique.dir/build.make
unique: CMakeFiles/unique.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unique"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unique.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unique.dir/build: unique

.PHONY : CMakeFiles/unique.dir/build

CMakeFiles/unique.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unique.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unique.dir/clean

CMakeFiles/unique.dir/depend:
	cd /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/build /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/build /Users/LuLienHsi/Cpp-Algorithm/basics/SmartPointer/build/CMakeFiles/unique.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unique.dir/depend

