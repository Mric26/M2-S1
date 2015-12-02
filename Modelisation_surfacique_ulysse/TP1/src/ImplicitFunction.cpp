#include "ImplicitFunction.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;



ImplicitFunction::ImplicitFunction()
{

}

ImplicitFunction::~ImplicitFunction()
{

}


MyImplicitFunction::MyImplicitFunction()
{

}

MyImplicitFunction::~MyImplicitFunction()
{

}

float MyImplicitFunction::Eval(glm::vec3 p) const
{
    // Todo : Implement your function here

    return 0.0;
}

glm::vec3 MyImplicitFunction::EvalDev(glm::vec3 p) const
{
    // Todo : Implement the gradient of your function here

    return vec3(0.0);
}


