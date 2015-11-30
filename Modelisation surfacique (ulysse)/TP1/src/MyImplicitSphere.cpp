#include "MyImplicitSphere.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

float MyImplicitSphere::Eval(glm::vec3 p) const{
    return glm::length(p);
}


glm::vec3 MyImplicitSphere::EvalDev(glm::vec3 p) const{ 
    return p;
}


