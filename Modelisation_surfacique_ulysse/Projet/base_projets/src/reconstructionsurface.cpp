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
    vertices_tab = mesh.vertices;
    //ajout des points
    ajout_tab = new std::vector< glm::vec3 >;
    ajout_tab->push_back( barycentre() );
    for (int i = 0; i < ajout_tab->size; ++i) {
        vertices_tab.push_back( ajout_tab->at(i) );
    }
    //calcul
    construction_RBF();
//    construction_CSRBF();
}

void ReconstructionSurface::construction_RBF(){
    //calcul des distances
    int taille = static_cast<int>(vertices_tab.size());
    MatrixXf distances = MatrixXf(taille, taille);

    for (int i = 0; i < taille; ++i) {
        for (int j = i; j < taille; ++j) {
            double dist = glm::distance(vertices_tab.at(i), vertices_tab.at(j));
            dist = fonction_RBF(dist);
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

double ReconstructionSurface::fonction_RBF( double x ){
    double res;
    int fonction  = 1;
    switch ( fonction ) {
    case 1 :
        //Gaussienne
        res = exp( -( x * x ) );
        break;
    case 2 :
        //Logarithme
        res = x * log(x);
        break;
    case 3 :
        //Multi - Quadratique
        res = sqrt( (x * x) + 1 );
        break;
    default:
        res = 0.0;
        break;
    }
    return res;
}

void ReconstructionSurface::construction_CSRBF(){
    //calcul des distances
    int taille = static_cast<int>(vertices_tab.size());
    MatrixXf distances = MatrixXf(taille, taille);
    ////SparseMatrix<double> distances(taille, taille); ////Matrice creuse pour accelerer

    for (int i = 0; i < taille; ++i) {
        for (int j = i; j < taille; ++j) {
            double dist = glm::distance(vertices_tab.at(i), vertices_tab.at(j));
            dist = fonction_CSRBF(dist);
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
    ////utiliser un solveur de matrice creuse
}

double ReconstructionSurface::fonction_CSRBF( double x ){
    double res = 0.0;
    if( ( 0 <= x ) && ( x <1 ) ){
        //((1-x)^5) + (1 +5x + 9x^2 + 5x^3 + x^4)
        res = pow( (1-x), 5) + ( 1 + 5*x + 9*pow(x,2) + 5*pow(x,3) + pow(x,4) );
    }
    return res;
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

float ReconstructionSurface::Eval(glm::vec3 p) const{
    double res = 0.0;
    double dist =0.0;
    int taille = static_cast<int>(vertices_tab.size());
    for (int i = 0; i < taille; ++i) {
        dist = glm::distance(p, vertices_tab.at(i));
        dist = exp(-(dist*dist));
        res = res + (dist * weight_tab(i) );
    }
    return res;
}

glm::vec3 ReconstructionSurface::EvalDev(glm::vec3 p) const{
    return p;
}


