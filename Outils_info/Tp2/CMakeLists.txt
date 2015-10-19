cmake_minimum_required (VERSION 2.6)
project (TP2)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

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
add_subdirectory(eigen)

include_directories(${TP2_SOURCE_DIR}/src)
include_directories(${TP2_SOURCE_DIR}/eigen)

add_executable(main_exe ${SOURCE_FILES})

enable_testing()
add_executable(test_exe ${TEST_FILES})
add_test(Test test_exe)
