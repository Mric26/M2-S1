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
include lib/CMakeFiles/tp4.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/tp4.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/tp4.dir/flags.make

lib/CMakeFiles/tp4.dir/tp4.c.o: lib/CMakeFiles/tp4.dir/flags.make
lib/CMakeFiles/tp4.dir/tp4.c.o: lib/tp4.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object lib/CMakeFiles/tp4.dir/tp4.c.o"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tp4.dir/tp4.c.o   -c /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib/tp4.c

lib/CMakeFiles/tp4.dir/tp4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp4.dir/tp4.c.i"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib/tp4.c > CMakeFiles/tp4.dir/tp4.c.i

lib/CMakeFiles/tp4.dir/tp4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp4.dir/tp4.c.s"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib/tp4.c -o CMakeFiles/tp4.dir/tp4.c.s

lib/CMakeFiles/tp4.dir/tp4.c.o.requires:
.PHONY : lib/CMakeFiles/tp4.dir/tp4.c.o.requires

lib/CMakeFiles/tp4.dir/tp4.c.o.provides: lib/CMakeFiles/tp4.dir/tp4.c.o.requires
	$(MAKE) -f lib/CMakeFiles/tp4.dir/build.make lib/CMakeFiles/tp4.dir/tp4.c.o.provides.build
.PHONY : lib/CMakeFiles/tp4.dir/tp4.c.o.provides

lib/CMakeFiles/tp4.dir/tp4.c.o.provides.build: lib/CMakeFiles/tp4.dir/tp4.c.o

# Object files for target tp4
tp4_OBJECTS = \
"CMakeFiles/tp4.dir/tp4.c.o"

# External object files for target tp4
tp4_EXTERNAL_OBJECTS =

lib/libtp4.so.1.3.4: lib/CMakeFiles/tp4.dir/tp4.c.o
lib/libtp4.so.1.3.4: lib/CMakeFiles/tp4.dir/build.make
lib/libtp4.so.1.3.4: lib/CMakeFiles/tp4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library libtp4.so"
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tp4.dir/link.txt --verbose=$(VERBOSE)
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib && $(CMAKE_COMMAND) -E cmake_symlink_library libtp4.so.1.3.4 libtp4.so.1 libtp4.so

lib/libtp4.so.1: lib/libtp4.so.1.3.4

lib/libtp4.so: lib/libtp4.so.1.3.4

# Rule to build all files generated by this target.
lib/CMakeFiles/tp4.dir/build: lib/libtp4.so
.PHONY : lib/CMakeFiles/tp4.dir/build

lib/CMakeFiles/tp4.dir/requires: lib/CMakeFiles/tp4.dir/tp4.c.o.requires
.PHONY : lib/CMakeFiles/tp4.dir/requires

lib/CMakeFiles/tp4.dir/clean:
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib && $(CMAKE_COMMAND) -P CMakeFiles/tp4.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/tp4.dir/clean

lib/CMakeFiles/tp4.dir/depend:
	cd /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4 /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4 /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib /home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib/CMakeFiles/tp4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/tp4.dir/depend
