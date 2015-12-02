#include "MyImplicitAddition.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

float MyImplicitAddition::Eval(glm::vec3 p) const{
  float res =  0; /* max( f1.eval(p), f2.eval(p) ); */
  return res;
}


glm::vec3 MyImplicitAddition::EvalDev(glm::vec3 p) const{ 
  glm::vec3 res = p;
  return res;
}


