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
include CMakeFiles/wumpus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wumpus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wumpus.dir/flags.make

CMakeFiles/wumpus.dir/wumpus/main.cpp.o: CMakeFiles/wumpus.dir/flags.make
CMakeFiles/wumpus.dir/wumpus/main.cpp.o: ../wumpus/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wumpus.dir/wumpus/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wumpus.dir/wumpus/main.cpp.o -c /home/yitbarek/Desktop/experment/final/wumpus/wumpus/main.cpp

CMakeFiles/wumpus.dir/wumpus/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wumpus.dir/wumpus/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yitbarek/Desktop/experment/final/wumpus/wumpus/main.cpp > CMakeFiles/wumpus.dir/wumpus/main.cpp.i

CMakeFiles/wumpus.dir/wumpus/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wumpus.dir/wumpus/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yitbarek/Desktop/experment/final/wumpus/wumpus/main.cpp -o CMakeFiles/wumpus.dir/wumpus/main.cpp.s

CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.o: CMakeFiles/wumpus.dir/flags.make
CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.o: ../wumpus/wumpus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.o -c /home/yitbarek/Desktop/experment/final/wumpus/wumpus/wumpus.cpp

CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yitbarek/Desktop/experment/final/wumpus/wumpus/wumpus.cpp > CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.i

CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yitbarek/Desktop/experment/final/wumpus/wumpus/wumpus.cpp -o CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.s

# Object files for target wumpus
wumpus_OBJECTS = \
"CMakeFiles/wumpus.dir/wumpus/main.cpp.o" \
"CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.o"

# External object files for target wumpus
wumpus_EXTERNAL_OBJECTS =

wumpus: CMakeFiles/wumpus.dir/wumpus/main.cpp.o
wumpus: CMakeFiles/wumpus.dir/wumpus/wumpus.cpp.o
wumpus: CMakeFiles/wumpus.dir/build.make
wumpus: CMakeFiles/wumpus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable wumpus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wumpus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wumpus.dir/build: wumpus

.PHONY : CMakeFiles/wumpus.dir/build

CMakeFiles/wumpus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wumpus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wumpus.dir/clean

CMakeFiles/wumpus.dir/depend:
	cd /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yitbarek/Desktop/experment/final/wumpus /home/yitbarek/Desktop/experment/final/wumpus /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug /home/yitbarek/Desktop/experment/final/wumpus/cmake-build-debug/CMakeFiles/wumpus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wumpus.dir/depend
