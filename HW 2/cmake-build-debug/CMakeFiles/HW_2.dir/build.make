# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/HW_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW_2.dir/flags.make

CMakeFiles/HW_2.dir/hw2_res0038.cpp.o: CMakeFiles/HW_2.dir/flags.make
CMakeFiles/HW_2.dir/hw2_res0038.cpp.o: ../hw2_res0038.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW_2.dir/hw2_res0038.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW_2.dir/hw2_res0038.cpp.o -c "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/hw2_res0038.cpp"

CMakeFiles/HW_2.dir/hw2_res0038.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW_2.dir/hw2_res0038.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/hw2_res0038.cpp" > CMakeFiles/HW_2.dir/hw2_res0038.cpp.i

CMakeFiles/HW_2.dir/hw2_res0038.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW_2.dir/hw2_res0038.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/hw2_res0038.cpp" -o CMakeFiles/HW_2.dir/hw2_res0038.cpp.s

# Object files for target HW_2
HW_2_OBJECTS = \
"CMakeFiles/HW_2.dir/hw2_res0038.cpp.o"

# External object files for target HW_2
HW_2_EXTERNAL_OBJECTS =

HW_2: CMakeFiles/HW_2.dir/hw2_res0038.cpp.o
HW_2: CMakeFiles/HW_2.dir/build.make
HW_2: CMakeFiles/HW_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW_2.dir/build: HW_2

.PHONY : CMakeFiles/HW_2.dir/build

CMakeFiles/HW_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW_2.dir/clean

CMakeFiles/HW_2.dir/depend:
	cd "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2" "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2" "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/cmake-build-debug" "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/cmake-build-debug" "/Users/awubis/Documents/Spring 2019 Semester/COMP 2710/Homework/HW 2/cmake-build-debug/CMakeFiles/HW_2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/HW_2.dir/depend
