# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4

# Include any dependencies generated for this target.
include examples/CMakeFiles/test1.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/test1.dir/flags.make

examples/CMakeFiles/test1.dir/test1.c.o: examples/CMakeFiles/test1.dir/flags.make
examples/CMakeFiles/test1.dir/test1.c.o: examples/test1.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object examples/CMakeFiles/test1.dir/test1.c.o"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test1.dir/test1.c.o   -c /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples/test1.c

examples/CMakeFiles/test1.dir/test1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test1.dir/test1.c.i"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples/test1.c > CMakeFiles/test1.dir/test1.c.i

examples/CMakeFiles/test1.dir/test1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test1.dir/test1.c.s"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples/test1.c -o CMakeFiles/test1.dir/test1.c.s

examples/CMakeFiles/test1.dir/test1.c.o.requires:
.PHONY : examples/CMakeFiles/test1.dir/test1.c.o.requires

examples/CMakeFiles/test1.dir/test1.c.o.provides: examples/CMakeFiles/test1.dir/test1.c.o.requires
	$(MAKE) -f examples/CMakeFiles/test1.dir/build.make examples/CMakeFiles/test1.dir/test1.c.o.provides.build
.PHONY : examples/CMakeFiles/test1.dir/test1.c.o.provides

examples/CMakeFiles/test1.dir/test1.c.o.provides.build: examples/CMakeFiles/test1.dir/test1.c.o

# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/test1.c.o"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

examples/test1: examples/CMakeFiles/test1.dir/test1.c.o
examples/test1: examples/CMakeFiles/test1.dir/build.make
examples/test1: lib/libtp4.so.1.3.4
examples/test1: examples/CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable test1"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/test1.dir/build: examples/test1
.PHONY : examples/CMakeFiles/test1.dir/build

examples/CMakeFiles/test1.dir/requires: examples/CMakeFiles/test1.dir/test1.c.o.requires
.PHONY : examples/CMakeFiles/test1.dir/requires

examples/CMakeFiles/test1.dir/clean:
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples && $(CMAKE_COMMAND) -P CMakeFiles/test1.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/test1.dir/clean

examples/CMakeFiles/test1.dir/depend:
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4 /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4 /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/examples/CMakeFiles/test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/test1.dir/depend

