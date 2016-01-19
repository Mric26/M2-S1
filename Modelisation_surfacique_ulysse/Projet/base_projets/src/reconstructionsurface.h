#ifndef RECONSTRUCTIONSURFACE_H
#define RECONSTRUCTIONSURFACE_H

//#include <glm/glm.hpp>
//#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Sparse>

#include "ImplicitFunction.h"
#include "Mesh.h"

class ReconstructionSurface : public ImplicitFunction
{
public:
    ReconstructionSurface( Mesh m );
    ~ReconstructionSurface() {}

    virtual float Eval(glm::vec3 p) const;
    virtual glm::vec3 EvalDev(glm::vec3 p) const;

    //ajout de points
    glm::vec3 barycentre();
    void construction_points();

    //calcul avec des rbf
    void construction_RBF();
    double fonction_RBF(double x);

    //calcul avec des CSRBF
    void construction_CSRBF();
    double fonction_CSRBF(double x);    

private:
    Mesh mesh;
    std::vector< glm::vec3 > vertices_tab;
    std::vector< glm::vec3 > * ajout_tab;
    Eigen::VectorXd weight_tab;
    Eigen::VectorXd iso_tab;
    glm::vec3 b;

};

#endif // RECONSTRUCTIONSURFACE_H
