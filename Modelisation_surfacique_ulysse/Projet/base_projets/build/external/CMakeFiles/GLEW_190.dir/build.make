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
CMAKE_SOURCE_DIR = /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build

# Include any dependencies generated for this target.
include external/CMakeFiles/GLEW_190.dir/depend.make

# Include the progress variables for this target.
include external/CMakeFiles/GLEW_190.dir/progress.make

# Include the compile flags for this target's objects.
include external/CMakeFiles/GLEW_190.dir/flags.make

external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o: external/CMakeFiles/GLEW_190.dir/flags.make
external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o: ../external/glew-1.9.0/src/glew.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o"
	cd /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o   -c /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/external/glew-1.9.0/src/glew.c

external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.i"
	cd /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/external/glew-1.9.0/src/glew.c > CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.i

external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.s"
	cd /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/external/glew-1.9.0/src/glew.c -o CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.s

external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.requires:
.PHONY : external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.requires

external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.provides: external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.requires
	$(MAKE) -f external/CMakeFiles/GLEW_190.dir/build.make external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.provides.build
.PHONY : external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.provides

external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.provides.build: external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o

# Object files for target GLEW_190
GLEW_190_OBJECTS = \
"CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o"

# External object files for target GLEW_190
GLEW_190_EXTERNAL_OBJECTS =

external/libGLEW_190.a: external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o
external/libGLEW_190.a: external/CMakeFiles/GLEW_190.dir/build.make
external/libGLEW_190.a: external/CMakeFiles/GLEW_190.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libGLEW_190.a"
	cd /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external && $(CMAKE_COMMAND) -P CMakeFiles/GLEW_190.dir/cmake_clean_target.cmake
	cd /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GLEW_190.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/CMakeFiles/GLEW_190.dir/build: external/libGLEW_190.a
.PHONY : external/CMakeFiles/GLEW_190.dir/build

external/CMakeFiles/GLEW_190.dir/requires: external/CMakeFiles/GLEW_190.dir/glew-1.9.0/src/glew.c.o.requires
.PHONY : external/CMakeFiles/GLEW_190.dir/requires

external/CMakeFiles/GLEW_190.dir/clean:
	cd /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external && $(CMAKE_COMMAND) -P CMakeFiles/GLEW_190.dir/cmake_clean.cmake
.PHONY : external/CMakeFiles/GLEW_190.dir/clean

external/CMakeFiles/GLEW_190.dir/depend:
	cd /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/external /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external /home/s/segureta/Documents/M2-S1/Modelisation_surfacique_ulysse/Projet/base_projets/build/external/CMakeFiles/GLEW_190.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/CMakeFiles/GLEW_190.dir/depend

