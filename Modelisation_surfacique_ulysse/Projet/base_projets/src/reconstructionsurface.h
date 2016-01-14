#ifndef RECONSTRUCTIONSURFACE_H
#define RECONSTRUCTIONSURFACE_H

//#include <glm/glm.hpp>
//#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>
#include <eigen3/Eigen/Dense>

#include "ImplicitFunction.h"
#include "Mesh.h"

class ReconstructionSurface : public ImplicitFunction
{
public:
    ReconstructionSurface( Mesh m );
    ~ReconstructionSurface() {}

    virtual float Eval(glm::vec3 p) const;
    virtual glm::vec3 EvalDev(glm::vec3 p) const;

    glm::vec3 barycentre();
    void construction_RBF();
    double fonction_RBF(double x);
    void construction_CSRBF();
    double fonction_CSRBF(double x);

private:
    Mesh mesh;
    std::vector< glm::vec3 > vertices_tab;
    std::vector< glm::vec3 > * ajout_tab;
    Eigen::VectorXf weight_tab;
};

#endif // RECONSTRUCTIONSURFACE_H
