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
CMAKE_SOURCE_DIR = /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master

# Include any dependencies generated for this target.
include OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/depend.make

# Include the progress variables for this target.
include OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/progress.make

# Include the compile flags for this target's objects.
include OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/flags.make

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/flags.make
OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o: OpenCLUtilities/openCLUtilities.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o -c /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/openCLUtilities.cpp

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.i"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/openCLUtilities.cpp > CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.i

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.s"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/openCLUtilities.cpp -o CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.s

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.requires:
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.requires

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.provides: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.requires
	$(MAKE) -f OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/build.make OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.provides.build
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.provides

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.provides.build: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/flags.make
OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o: OpenCLUtilities/openCLGLUtilities.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o -c /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/openCLGLUtilities.cpp

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.i"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/openCLGLUtilities.cpp > CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.i

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.s"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/openCLGLUtilities.cpp -o CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.s

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.requires:
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.requires

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.provides: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.requires
	$(MAKE) -f OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/build.make OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.provides.build
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.provides

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.provides.build: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/flags.make
OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o: OpenCLUtilities/histogram-pyramids.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o -c /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/histogram-pyramids.cpp

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.i"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/histogram-pyramids.cpp > CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.i

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.s"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/histogram-pyramids.cpp -o CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.s

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.requires:
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.requires

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.provides: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.requires
	$(MAKE) -f OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/build.make OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.provides.build
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.provides

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.provides.build: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o

# Object files for target OCL-Utilities
OCL__Utilities_OBJECTS = \
"CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o" \
"CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o" \
"CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o"

# External object files for target OCL-Utilities
OCL__Utilities_EXTERNAL_OBJECTS =

OpenCLUtilities/libOCL-Utilities.a: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o
OpenCLUtilities/libOCL-Utilities.a: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o
OpenCLUtilities/libOCL-Utilities.a: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o
OpenCLUtilities/libOCL-Utilities.a: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/build.make
OpenCLUtilities/libOCL-Utilities.a: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libOCL-Utilities.a"
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && $(CMAKE_COMMAND) -P CMakeFiles/OCL-Utilities.dir/cmake_clean_target.cmake
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OCL-Utilities.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/build: OpenCLUtilities/libOCL-Utilities.a
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/build

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/requires: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLUtilities.cpp.o.requires
OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/requires: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/openCLGLUtilities.cpp.o.requires
OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/requires: OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/histogram-pyramids.cpp.o.requires
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/requires

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/clean:
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities && $(CMAKE_COMMAND) -P CMakeFiles/OCL-Utilities.dir/cmake_clean.cmake
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/clean

OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/depend:
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : OpenCLUtilities/CMakeFiles/OCL-Utilities.dir/depend
