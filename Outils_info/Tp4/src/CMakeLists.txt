cmake_minimum_required (VERSION 2.8)
project (TP4)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")

SET_SOURCE_FILES_PROPERTIES(main.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(main.i PROPERTIES SWIG_FLAGS "-includeall")
SWIG_ADD_MODULE(main python main.i main_wrap.cxx)
SWIG_LINK_LIBRARIES(main ${PYTHON_LIBRARIES})

