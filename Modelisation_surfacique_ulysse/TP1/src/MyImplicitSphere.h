#ifndef IMPLICIT_SPHERE_H
#define IMPLICIT_SPHERE_H

#include <glm/glm.hpp>
#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>

#include "ImplicitFunction.h"

class MyImplicitSphere : public  ImplicitFunction
{
public:

    MyImplicitSphere():ImplicitFunction() {}
    ~MyImplicitSphere() {}

    virtual float Eval(glm::vec3 p) const;
    virtual glm::vec3 EvalDev(glm::vec3 p) const;


private:

};



#endif // IMPLICIT_SPHERE_H
