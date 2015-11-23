cmake_minimum_required (VERSION 2.8)
project (TP4)

set(CMAKE_C_FLAGS "-g -Wall")
include_directories (${TP4_SOURCE_DIR}/lib)

add_subdirectory (lib)
add_subdirectory (examples)

