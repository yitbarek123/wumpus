# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.6/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.6/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yitbarek/Desktop/experment/final/wumpus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gameunittest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gameunittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gameunittest.dir/flags.make

CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.o: CMakeFiles/gameunittest.dir/flags.make
CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.o: ../tests/gameunittest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.o -c /home/yitbarek/Desktop/experment/final/wumpus/tests/gameunittest.cpp

CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yitbarek/Desktop/experment/final/wumpus/tests/gameunittest.cpp > CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.i

CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yitbarek/Desktop/experment/final/wumpus/tests/gameunittest.cpp -o CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.s

# Object files for target gameunittest
gameunittest_OBJECTS = \
"CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.o"

# External object files for target gameunittest
gameunittest_EXTERNAL_OBJECTS =

gameunittest: CMakeFiles/gameunittest.dir/tests/gameunittest.cpp.o
gameunittest: CMakeFiles/gameunittest.dir/build.make
gameunittest: CMakeFiles/gameunittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gameunittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameunittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gameunittest.dir/build: gameunittest

.PHONY : CMakeFiles/gameunittest.dir/build

CMakeFiles/gameunittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gameunittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gameunittest.dir/clean

CMakeFiles/gameunittest.dir/depend:
	cd /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yitbarek/Desktop/experment/final/wumpus /home/yitbarek/Desktop/experment/final/wumpus /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug/CMakeFiles/gameunittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gameunittest.dir/depend
