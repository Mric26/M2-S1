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
include CMakeFiles/host.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/host.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/host.dir/flags.make

CMakeFiles/host.dir/main.cpp.o: CMakeFiles/host.dir/flags.make
CMakeFiles/host.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/host.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/host.dir/main.cpp.o -c /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/main.cpp

CMakeFiles/host.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/host.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/main.cpp > CMakeFiles/host.dir/main.cpp.i

CMakeFiles/host.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/host.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/main.cpp -o CMakeFiles/host.dir/main.cpp.s

CMakeFiles/host.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/host.dir/main.cpp.o.requires

CMakeFiles/host.dir/main.cpp.o.provides: CMakeFiles/host.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/host.dir/build.make CMakeFiles/host.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/host.dir/main.cpp.o.provides

CMakeFiles/host.dir/main.cpp.o.provides.build: CMakeFiles/host.dir/main.cpp.o

CMakeFiles/host.dir/gpu-mc.cpp.o: CMakeFiles/host.dir/flags.make
CMakeFiles/host.dir/gpu-mc.cpp.o: gpu-mc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/host.dir/gpu-mc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/host.dir/gpu-mc.cpp.o -c /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/gpu-mc.cpp

CMakeFiles/host.dir/gpu-mc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/host.dir/gpu-mc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/gpu-mc.cpp > CMakeFiles/host.dir/gpu-mc.cpp.i

CMakeFiles/host.dir/gpu-mc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/host.dir/gpu-mc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/gpu-mc.cpp -o CMakeFiles/host.dir/gpu-mc.cpp.s

CMakeFiles/host.dir/gpu-mc.cpp.o.requires:
.PHONY : CMakeFiles/host.dir/gpu-mc.cpp.o.requires

CMakeFiles/host.dir/gpu-mc.cpp.o.provides: CMakeFiles/host.dir/gpu-mc.cpp.o.requires
	$(MAKE) -f CMakeFiles/host.dir/build.make CMakeFiles/host.dir/gpu-mc.cpp.o.provides.build
.PHONY : CMakeFiles/host.dir/gpu-mc.cpp.o.provides

CMakeFiles/host.dir/gpu-mc.cpp.o.provides.build: CMakeFiles/host.dir/gpu-mc.cpp.o

CMakeFiles/host.dir/rawUtilities.cpp.o: CMakeFiles/host.dir/flags.make
CMakeFiles/host.dir/rawUtilities.cpp.o: rawUtilities.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/host.dir/rawUtilities.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/host.dir/rawUtilities.cpp.o -c /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/rawUtilities.cpp

CMakeFiles/host.dir/rawUtilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/host.dir/rawUtilities.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/rawUtilities.cpp > CMakeFiles/host.dir/rawUtilities.cpp.i

CMakeFiles/host.dir/rawUtilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/host.dir/rawUtilities.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/rawUtilities.cpp -o CMakeFiles/host.dir/rawUtilities.cpp.s

CMakeFiles/host.dir/rawUtilities.cpp.o.requires:
.PHONY : CMakeFiles/host.dir/rawUtilities.cpp.o.requires

CMakeFiles/host.dir/rawUtilities.cpp.o.provides: CMakeFiles/host.dir/rawUtilities.cpp.o.requires
	$(MAKE) -f CMakeFiles/host.dir/build.make CMakeFiles/host.dir/rawUtilities.cpp.o.provides.build
.PHONY : CMakeFiles/host.dir/rawUtilities.cpp.o.provides

CMakeFiles/host.dir/rawUtilities.cpp.o.provides.build: CMakeFiles/host.dir/rawUtilities.cpp.o

# Object files for target host
host_OBJECTS = \
"CMakeFiles/host.dir/main.cpp.o" \
"CMakeFiles/host.dir/gpu-mc.cpp.o" \
"CMakeFiles/host.dir/rawUtilities.cpp.o"

# External object files for target host
host_EXTERNAL_OBJECTS =

host: CMakeFiles/host.dir/main.cpp.o
host: CMakeFiles/host.dir/gpu-mc.cpp.o
host: CMakeFiles/host.dir/rawUtilities.cpp.o
host: CMakeFiles/host.dir/build.make
host: OpenCLUtilities/libOCL-Utilities.a
host: /usr/lib64/libGLEW.so
host: /usr/lib64/libglut.so
host: /usr/lib64/libXmu.so
host: /usr/lib64/libXi.so
host: /usr/lib64/libGLU.so
host: /usr/lib64/libGL.so
host: /usr/lib64/libSM.so
host: /usr/lib64/libICE.so
host: /usr/lib64/libX11.so
host: /usr/lib64/libXext.so
host: /usr/local/cuda/lib64/libOpenCL.so
host: /usr/lib64/libGLU.so
host: /usr/lib64/libGL.so
host: /usr/lib64/libSM.so
host: /usr/lib64/libICE.so
host: /usr/lib64/libX11.so
host: /usr/lib64/libXext.so
host: CMakeFiles/host.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable host"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/host.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/host.dir/build: host
.PHONY : CMakeFiles/host.dir/build

CMakeFiles/host.dir/requires: CMakeFiles/host.dir/main.cpp.o.requires
CMakeFiles/host.dir/requires: CMakeFiles/host.dir/gpu-mc.cpp.o.requires
CMakeFiles/host.dir/requires: CMakeFiles/host.dir/rawUtilities.cpp.o.requires
.PHONY : CMakeFiles/host.dir/requires

CMakeFiles/host.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/host.dir/cmake_clean.cmake
.PHONY : CMakeFiles/host.dir/clean

CMakeFiles/host.dir/depend:
	cd /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master /user/6/.base/segureta/home/Documents/HPC/MarchingCube/GPU-Marching-Cubes-master/CMakeFiles/host.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/host.dir/depend
