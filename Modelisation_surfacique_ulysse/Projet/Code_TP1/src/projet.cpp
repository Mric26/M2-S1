#include "projet.h"

#include "Mesh.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

Projet::Reconstruction( Mesh m ){

    unsigned int  nb_vertices = m.nb_vertices;
    unsigned int  nb_faces = m.nb_faces;
    std::vector< glm::vec3 >  vertices = m.vertices;
    std::vector< glm::vec3 > normales = m.normals;
    std::vector< unsigned int > faces = m.faces;



}
