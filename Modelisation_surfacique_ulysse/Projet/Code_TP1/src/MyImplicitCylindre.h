#ifndef IMPLICIT_CYLINDRE_H
#define IMPLICIT_CYLINDRE_H

#include <glm/glm.hpp>
#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>

#include "ImplicitFunction.h"

class MyImplicitCylindre : public  ImplicitFunction
{
public:

    MyImplicitCylindre():ImplicitFunction() {}
    ~MyImplicitCylindre() {}

    virtual float Eval(glm::vec3 p) const;
    virtual glm::vec3 EvalDev(glm::vec3 p) const;


private:

};



#endif // IMPLICIT_CYLINDRE_H
