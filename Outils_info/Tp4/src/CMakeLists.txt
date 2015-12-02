cmake_minimum_required (VERSION 2.8)
project (TP4)

#commande pour obliger a lancer le cmake dans un dossier build ou autre tant que cest different du dossier source
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

#importation de la librairie SWIG
FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

#importation de la librairie Python
FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

#importation de tcl et de la librairie tp4
set(TCL_INCLUDE_PATH "/usr/include/tcl")
set(TP4_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/../libtp4/lib)
INCLUDE_DIRECTORIES(${TCL_INCLUDE_PATH} ${TP4_INCLUDE_PATH})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

#compilation des .c
add_executable(test1 test1.c)
add_executable(test2 test2.c)

#commande perso pour creer le wrapper
add_custom_command(OUTPUT main_wrap.c COMMAND ${SWIG_EXECUTABLE} ARGS -python ${PROJECT_SOURCE_DIR}/main.i)

#commande pour la creation du .so à partir du wrapper et des librairies
SET_SOURCE_FILES_PROPERTIES(main.i PROPERTIES CC ON)
SET_SOURCE_FILES_PROPERTIES(main.i PROPERTIES SWIG_FLAGS "-includeall")
SWIG_ADD_MODULE(myModuleCmake python  ../src/main_wrap.c)
SWIG_LINK_LIBRARIES(myModuleCmake ${PYTHON_LIBRARIES})
