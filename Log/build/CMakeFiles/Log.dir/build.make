# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lee/Engine/Log

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lee/Engine/Log/build

# Include any dependencies generated for this target.
include CMakeFiles/Log.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Log.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Log.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Log.dir/flags.make

CMakeFiles/Log.dir/Log.cpp.o: CMakeFiles/Log.dir/flags.make
CMakeFiles/Log.dir/Log.cpp.o: /home/lee/Engine/Log/Log.cpp
CMakeFiles/Log.dir/Log.cpp.o: CMakeFiles/Log.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/Engine/Log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Log.dir/Log.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Log.dir/Log.cpp.o -MF CMakeFiles/Log.dir/Log.cpp.o.d -o CMakeFiles/Log.dir/Log.cpp.o -c /home/lee/Engine/Log/Log.cpp

CMakeFiles/Log.dir/Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Log.dir/Log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/Engine/Log/Log.cpp > CMakeFiles/Log.dir/Log.cpp.i

CMakeFiles/Log.dir/Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Log.dir/Log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/Engine/Log/Log.cpp -o CMakeFiles/Log.dir/Log.cpp.s

CMakeFiles/Log.dir/main.cpp.o: CMakeFiles/Log.dir/flags.make
CMakeFiles/Log.dir/main.cpp.o: /home/lee/Engine/Log/main.cpp
CMakeFiles/Log.dir/main.cpp.o: CMakeFiles/Log.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/Engine/Log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Log.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Log.dir/main.cpp.o -MF CMakeFiles/Log.dir/main.cpp.o.d -o CMakeFiles/Log.dir/main.cpp.o -c /home/lee/Engine/Log/main.cpp

CMakeFiles/Log.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Log.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/Engine/Log/main.cpp > CMakeFiles/Log.dir/main.cpp.i

CMakeFiles/Log.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Log.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/Engine/Log/main.cpp -o CMakeFiles/Log.dir/main.cpp.s

# Object files for target Log
Log_OBJECTS = \
"CMakeFiles/Log.dir/Log.cpp.o" \
"CMakeFiles/Log.dir/main.cpp.o"

# External object files for target Log
Log_EXTERNAL_OBJECTS =

Log: CMakeFiles/Log.dir/Log.cpp.o
Log: CMakeFiles/Log.dir/main.cpp.o
Log: CMakeFiles/Log.dir/build.make
Log: CMakeFiles/Log.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lee/Engine/Log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Log"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Log.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Log.dir/build: Log
.PHONY : CMakeFiles/Log.dir/build

CMakeFiles/Log.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Log.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Log.dir/clean

CMakeFiles/Log.dir/depend:
	cd /home/lee/Engine/Log/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lee/Engine/Log /home/lee/Engine/Log /home/lee/Engine/Log/build /home/lee/Engine/Log/build /home/lee/Engine/Log/build/CMakeFiles/Log.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Log.dir/depend
