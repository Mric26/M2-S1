#include "MyImplicitTore.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

float MyImplicitTore::Eval(glm::vec3 p) const{
  // f(x,y,z) = (x² + y² + z² + R² - r²)² - 4 R² (x² + z²)
  float res = 0;
  res = (p.x * p.x + p.y * p.y + p.z * p.z);
  return res;
}


glm::vec3 MyImplicitTore::EvalDev(glm::vec3 p) const{ 
  /*
  df/dx = 4 x (x² + y² + z² + R² - r²) - 8 R² x
  df/dy = 4 y (x² + y² + z² + R² - r²)
  df/dz = 4 z (x² + y² + z² + R² - r²) - 8 R² z
  
  normal = (df/dx, df/dy, df/dz)
  */
  return p;
}


