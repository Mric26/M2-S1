#include "reconstructionsurface.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;
using namespace Eigen;

ReconstructionSurface::ReconstructionSurface( Mesh m ){
    //variables
    mesh = m;
    vertices_tab = mesh.Vertices();
    b = barycentre();
    //ajout des points
    construction_points();
    //calcul
    construction_RBF();
//    construction_CSRBF();
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

void ReconstructionSurface::construction_points(){
    ajout_tab = new std::vector< glm::vec3 >;
    //sauvegarde de la taille initiale
    int taille = static_cast<int>(vertices_tab.size());
    //switch sur le choix de l'ajout
    int f = 10;
    int p  = 1;
    switch ( p ) {
    case 1 :
        // ajout test pour cube
        for (int v = 0; v < taille; ++v) {
            glm::vec3 c = vertices_tab.at(v);
            glm::vec3 d = c - b;
            c = glm::vec3( c.x + (d.x/f), c.y + (d.y/f), c.z + (d.z/f) );
            ajout_tab->push_back( c );
            c = glm::vec3( c.x - (d.x/f), c.y - (d.y/f), c.z - (d.z/f) );
            ajout_tab->push_back( c );
        }
        break;
    default:
        // ajout du barycentre
        ajout_tab->push_back( b );
        break;
    }
    //ajout des points au tableau de points
    int taille2 = static_cast<int>(ajout_tab->size());
    for (int i = 0; i < taille2; ++i) {
        vertices_tab.push_back( ajout_tab->at(i) );
    }
    //ajout des valeurs au tableau des iso
    iso_tab = Eigen::VectorXd(taille + taille2);
    for (int k = 0; k < taille; ++k) {
        iso_tab(k) = 0;
    }
    for (int l = 0; l < taille2; l=l+2) {
        iso_tab(taille + l) = -1;
        iso_tab(taille + l + 1) = 1;
    }
}

void ReconstructionSurface::construction_RBF(){
    //calcul des distances
    int taille = static_cast<int>(vertices_tab.size());
    Eigen::SparseMatrix<double> distances(taille, taille);
    for (int i = 0; i < taille; ++i) {
        for (int j = i; j < taille; ++j) {
            double dist = glm::distance(vertices_tab.at(i), vertices_tab.at(j));
            dist = fonction_RBF(dist);
            distances.coeffRef(i,j) = dist;
            distances.coeffRef(j,i) = dist;
        }
    }
    //calcul des poids par resolution du système avec matrice creuse
    Eigen::BiCGSTAB< Eigen::SparseMatrix<double> > solver;
    solver.compute(distances);
    weight_tab = solver.solve(iso_tab);
    std::cout << "###########################" << std::endl;
    std::cout << "Sorties du solveurs :      " << std::endl;
    std::cout << "Iterations :     " << solver.iterations() << std::endl;
    std::cout << "Estimated error: " << solver.error()      << std::endl;
    std::cout << "###########################" << std::endl;
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
        //Multiquadrique
        res = sqrt( 1 + (x * x) );
        break;
    case 4 :
        //Inverse quadratic
        res = 1 / ( 1 + (x * x) );
        break;
    case 5 :
        //Inverse multiquadric
        res = 1 / sqrt  ( 1 + (x * x) );
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
    MatrixXd distances = MatrixXd(taille, taille);

    for (int i = 0; i < taille; ++i) {
        for (int j = i; j < taille; ++j) {
            double dist = glm::distance(vertices_tab.at(i), vertices_tab.at(j));
            dist = fonction_CSRBF(dist);
            distances(i,j) = dist;
            distances(j,i) = dist;
        }
    }
    //calcul des poids
    weight_tab = distances.colPivHouseholderQr().solve(iso_tab);
}

double ReconstructionSurface::fonction_CSRBF( double x ){
    double res = 0.0;
    if( ( 0 <= x ) && ( x <1 ) ){
        //((1-x)^5) + (1 +5x + 9x^2 + 5x^3 + x^4)
        res = pow( (1-x), 5) + ( 1 + 5*x + 9*pow(x,2) + 5*pow(x,3) + pow(x,4) );
    }
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
    //fonction de calcul de normales qui ne fonctionne que dans certains cas (calcul approximatif)
    //A REMPLACER PAR UN MLS
    int taille = static_cast<int>(vertices_tab.size());
    glm::vec3 b = vertices_tab.at( taille-1 );
    return( p - b);
}


