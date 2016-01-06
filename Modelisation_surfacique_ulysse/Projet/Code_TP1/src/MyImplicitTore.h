#ifndef IMPLICIT_TORE_H
#define IMPLICIT_TORE_H

#include <glm/glm.hpp>
#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>

#include "ImplicitFunction.h"

class MyImplicitTore : public  ImplicitFunction
{
public:

    MyImplicitTore():ImplicitFunction() {}
    ~MyImplicitTore() {}

    virtual float Eval(glm::vec3 p) const;
    virtual glm::vec3 EvalDev(glm::vec3 p) const;


private:

  float R;
  
};



#endif // IMPLICIT_TORE_H
