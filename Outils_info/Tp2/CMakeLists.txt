cmake_minimum_required (VERSION 2.6)
project (TP2)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

#Prep ourselves for compiling boost
set(Boost_LIBRARIES 
  /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
  /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
  /usr/lib/x86_64-linux-gnu/libboost_system.so
  /usr/lib/x86_64-linux-gnu/libboost_program_options.so
  /usr/lib/x86_64-linux-gnu/libboost_signals.so
)
#find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_FILES src/main.cpp)
set(TEST_FILES src/tests/test1.cpp)

include(ExternalProject)
ExternalProject_Add (
	Eigen
	# we suppose here that your project is named TP
	# Library Eigen3 is stored in the sub - folder eigen
	SOURCE_DIR ${TP2_SOURCE_DIR}/eigen
	INSTALL_COMMAND echo "Skipping install"
)

include_directories(${TP2_SOURCE_DIR}/src)
include_directories(${TP2_SOURCE_DIR}/eigen)

add_executable(main_exe ${SOURCE_FILES})

enable_testing()
add_executable(test_exe ${TEST_FILES})
add_test(Test test_exe)
