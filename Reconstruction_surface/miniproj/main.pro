TARGET = pointsToSurface
CONFIG *= qt opengl release
QT *= opengl xml

HEADERS = geom.h iso_value.h data_struct_algo.h pointsToSurface.h eventWidget.h viewer.h
SOURCES = geom.cpp iso_value.cpp data_struct_algo.cpp pointsToSurface.cpp eventWidget.cpp viewer.cpp main.cpp

LIBS += -Wl,-rpath=/home/s/segureta/Documents/M2-S1/Reconstruction_surface/lib/libQGLViewer-2.6.1/QGLViewer -L/home/s/segureta/Documents/M2-S1/Reconstruction_surface/lib/libQGLViewer-2.6.1/QGLViewer -lQGLViewer
INCLUDEPATH += /home/s/segureta/Documents/M2-S1/Reconstruction_surface/lib/libQGLViewer-2.6.1

