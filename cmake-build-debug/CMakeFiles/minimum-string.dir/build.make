# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /Users/teodordre/Documents/reps/C++/coursera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/teodordre/Documents/reps/C++/coursera/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minimum-string.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minimum-string.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minimum-string.dir/flags.make

CMakeFiles/minimum-string.dir/minimum-string/main.cpp.o: CMakeFiles/minimum-string.dir/flags.make
CMakeFiles/minimum-string.dir/minimum-string/main.cpp.o: ../minimum-string/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/teodordre/Documents/reps/C++/coursera/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minimum-string.dir/minimum-string/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minimum-string.dir/minimum-string/main.cpp.o -c /Users/teodordre/Documents/reps/C++/coursera/minimum-string/main.cpp

CMakeFiles/minimum-string.dir/minimum-string/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minimum-string.dir/minimum-string/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/teodordre/Documents/reps/C++/coursera/minimum-string/main.cpp > CMakeFiles/minimum-string.dir/minimum-string/main.cpp.i

CMakeFiles/minimum-string.dir/minimum-string/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minimum-string.dir/minimum-string/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/teodordre/Documents/reps/C++/coursera/minimum-string/main.cpp -o CMakeFiles/minimum-string.dir/minimum-string/main.cpp.s

# Object files for target minimum-string
minimum__string_OBJECTS = \
"CMakeFiles/minimum-string.dir/minimum-string/main.cpp.o"

# External object files for target minimum-string
minimum__string_EXTERNAL_OBJECTS =

minimum-string: CMakeFiles/minimum-string.dir/minimum-string/main.cpp.o
minimum-string: CMakeFiles/minimum-string.dir/build.make
minimum-string: CMakeFiles/minimum-string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/teodordre/Documents/reps/C++/coursera/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minimum-string"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimum-string.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minimum-string.dir/build: minimum-string

.PHONY : CMakeFiles/minimum-string.dir/build

CMakeFiles/minimum-string.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minimum-string.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minimum-string.dir/clean

CMakeFiles/minimum-string.dir/depend:
	cd /Users/teodordre/Documents/reps/C++/coursera/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/teodordre/Documents/reps/C++/coursera /Users/teodordre/Documents/reps/C++/coursera /Users/teodordre/Documents/reps/C++/coursera/cmake-build-debug /Users/teodordre/Documents/reps/C++/coursera/cmake-build-debug /Users/teodordre/Documents/reps/C++/coursera/cmake-build-debug/CMakeFiles/minimum-string.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minimum-string.dir/depend
