#include "reconstructionsurface.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;
using namespace Eigen;

//exp(-x²)

ReconstructionSurface::ReconstructionSurface( Mesh m ){
    //variables
    mesh = m;
    vertices_tab = mesh.Vertices();
    //ajout du barycentre
    vertices_tab.push_back( barycentre() );
    //calcul des distances
    int taille = static_cast<int>(vertices_tab.size());
    Matrix3f distances = Matrix3f(taille, taille);

    for (int i = 0; i < taille; ++i) {
        for (int j = i; j < taille; ++j) {
            double dist = glm::distance(vertices_tab.at(i), vertices_tab.at(j));
            dist = exp(-(dist*dist));
            distances(i,j) = dist;
            distances(j,i) = dist;
        }
    }
    //construction des iso
    Eigen::VectorXf iso_tab(taille);
    for (int k = 0; k < taille-1; ++k) {
        iso_tab(k) = 0;
    }
    iso_tab(taille) = 1;
    //calcul des poids
    weight_tab = distances.colPivHouseholderQr().solve(iso_tab);
}

float ReconstructionSurface::Eval(glm::vec3 p) const{
    double res = 0;
    int taille = static_cast<int>(vertices_tab.size());
    for (int i = 0; i < taille; ++i) {
        res = res + (vertices_tab.at(i) * weight_tab(i) );
    }
    return res;
}

glm::vec3 ReconstructionSurface::EvalDev(glm::vec3 p) const{
    return p;
}

glm::vec3 ReconstructionSurface::barycentre(){
    //init
    glm::vec3 res;
    //addition des points
    int taille = static_cast<int>(vertices_tab.size());
    for (int i = 0; i < taille; ++i) {
        res = res + vertices_tab.at(i);
    }
    //division
    res.x = res.x / taille;
    res.y = res.y / taille;
    res.z = res.z / taille;
    //res
    return res;
}

