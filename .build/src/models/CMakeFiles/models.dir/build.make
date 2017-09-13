# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lezkus/Documents/CPProb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lezkus/Documents/CPProb/.build

# Include any dependencies generated for this target.
include src/models/CMakeFiles/models.dir/depend.make

# Include the progress variables for this target.
include src/models/CMakeFiles/models.dir/progress.make

# Include the compile flags for this target's objects.
include src/models/CMakeFiles/models.dir/flags.make

src/models/CMakeFiles/models.dir/models.cpp.o: src/models/CMakeFiles/models.dir/flags.make
src/models/CMakeFiles/models.dir/models.cpp.o: ../src/models/models.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/models/CMakeFiles/models.dir/models.cpp.o"
	cd /home/lezkus/Documents/CPProb/.build/src/models && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/models.dir/models.cpp.o -c /home/lezkus/Documents/CPProb/src/models/models.cpp

src/models/CMakeFiles/models.dir/models.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/models.cpp.i"
	cd /home/lezkus/Documents/CPProb/.build/src/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lezkus/Documents/CPProb/src/models/models.cpp > CMakeFiles/models.dir/models.cpp.i

src/models/CMakeFiles/models.dir/models.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/models.cpp.s"
	cd /home/lezkus/Documents/CPProb/.build/src/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lezkus/Documents/CPProb/src/models/models.cpp -o CMakeFiles/models.dir/models.cpp.s

src/models/CMakeFiles/models.dir/models.cpp.o.requires:

.PHONY : src/models/CMakeFiles/models.dir/models.cpp.o.requires

src/models/CMakeFiles/models.dir/models.cpp.o.provides: src/models/CMakeFiles/models.dir/models.cpp.o.requires
	$(MAKE) -f src/models/CMakeFiles/models.dir/build.make src/models/CMakeFiles/models.dir/models.cpp.o.provides.build
.PHONY : src/models/CMakeFiles/models.dir/models.cpp.o.provides

src/models/CMakeFiles/models.dir/models.cpp.o.provides.build: src/models/CMakeFiles/models.dir/models.cpp.o


# Object files for target models
models_OBJECTS = \
"CMakeFiles/models.dir/models.cpp.o"

# External object files for target models
models_EXTERNAL_OBJECTS =

src/models/libmodels.so: src/models/CMakeFiles/models.dir/models.cpp.o
src/models/libmodels.so: src/models/CMakeFiles/models.dir/build.make
src/models/libmodels.so: src/cpprob/libcpprob.so
src/models/libmodels.so: /usr/lib/libboost_program_options.a
src/models/libmodels.so: /usr/lib/libboost_serialization.a
src/models/libmodels.so: /usr/lib/libboost_filesystem.a
src/models/libmodels.so: /usr/lib/libboost_system.a
src/models/libmodels.so: /usr/lib/libzmq.so
src/models/libmodels.so: src/models/CMakeFiles/models.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lezkus/Documents/CPProb/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmodels.so"
	cd /home/lezkus/Documents/CPProb/.build/src/models && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/models.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/models/CMakeFiles/models.dir/build: src/models/libmodels.so

.PHONY : src/models/CMakeFiles/models.dir/build

src/models/CMakeFiles/models.dir/requires: src/models/CMakeFiles/models.dir/models.cpp.o.requires

.PHONY : src/models/CMakeFiles/models.dir/requires

src/models/CMakeFiles/models.dir/clean:
	cd /home/lezkus/Documents/CPProb/.build/src/models && $(CMAKE_COMMAND) -P CMakeFiles/models.dir/cmake_clean.cmake
.PHONY : src/models/CMakeFiles/models.dir/clean

src/models/CMakeFiles/models.dir/depend:
	cd /home/lezkus/Documents/CPProb/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lezkus/Documents/CPProb /home/lezkus/Documents/CPProb/src/models /home/lezkus/Documents/CPProb/.build /home/lezkus/Documents/CPProb/.build/src/models /home/lezkus/Documents/CPProb/.build/src/models/CMakeFiles/models.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/models/CMakeFiles/models.dir/depend

