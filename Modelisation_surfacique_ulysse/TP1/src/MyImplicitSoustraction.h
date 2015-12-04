#ifndef IMPLICIT_SOUSTRACTION_H
#define IMPLICIT_SOUSTRACTION_H

#include <glm/glm.hpp>
#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>

#include "ImplicitFunction.h"

class MyImplicitSoustraction : public  ImplicitFunction
{
public:

    MyImplicitSoustraction(ImplicitFunction * a, ImplicitFunction * b):ImplicitFunction() { f1 = a; f2 = b; }
    ~MyImplicitSoustraction() {}

    virtual float Eval(glm::vec3 p) const;
    virtual glm::vec3 EvalDev(glm::vec3 p) const;


private:

  float R;
  ImplicitFunction * f1;
  ImplicitFunction * f2;
  
};



#endif // IMPLICIT_SOUSTRACTION_H
