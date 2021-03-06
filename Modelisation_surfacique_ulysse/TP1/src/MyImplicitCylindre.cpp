#include "MyImplicitCylindre.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

float MyImplicitCylindre::Eval(glm::vec3 p) const{
  // x² + y² = r²
  float res = 0;
  res = sqrt(p.x * p.x + p.y * p.y);
  cout << res << endl;
  return res;
}


glm::vec3 MyImplicitCylindre::EvalDev(glm::vec3 p) const{ 
  vec3 res;
  res.x = p.x;
  res.y = p.y;
  res.z = 0;
  return res;
}


