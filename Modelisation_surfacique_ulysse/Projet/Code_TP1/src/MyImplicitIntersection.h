#ifndef IMPLICIT_INTERSECTION_H
#define IMPLICIT_INTERSECTION_H

#include <glm/glm.hpp>
#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>

#include "ImplicitFunction.h"

class MyImplicitIntersection : public  ImplicitFunction
{
public:

    MyImplicitIntersection(ImplicitFunction * a, ImplicitFunction * b):ImplicitFunction() { f1 = a; f2 = b; }
    ~MyImplicitIntersection() {}

    virtual float Eval(glm::vec3 p) const;
    virtual glm::vec3 EvalDev(glm::vec3 p) const;


private:

  float R;
  ImplicitFunction * f1;
  ImplicitFunction * f2;
  
};



#endif // IMPLICIT_INTERSECTION_H
