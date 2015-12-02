#include "MyImplicitTore.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

float MyImplicitTore::Eval(glm::vec3 p) const{
  // f(x,y,z) = (x² + y² + z² + R² - r²)² - 4 R² (x² + z²)
  float R = 1.30;
  float r = 0.60;
  float res = (p.x * p.x + p.y * p.y + p.z * p.z + R * R - r * r)*(p.x * p.x + p.y * p.y + p.z * p.z + R * R - r * r) - 4*R*R*(p.x * p.x + p.z * p.z) ;
  
  //return sqrt(   (p.z*p.z) + ((sqrt(p.x*p.x + p.y*p.y) - R) * (sqrt(p.x*p.x + p.y*p.y) - R))   );
  
  return res;
}


glm::vec3 MyImplicitTore::EvalDev(glm::vec3 p) const{ 
  glm::vec3 res;
  /*
  df/dx = 4 x (x² + y² + z² + R² - r²) - 8 R² x
  df/dy = 4 y (x² + y² + z² + R² - r²)
  df/dz = 4 z (x² + y² + z² + R² - r²) - 8 R² z
  
  normal = (df/dx, df/dy, df/dz)
  */
  float R = 1.0;
  float r = 0.1;
  res.x = 4 * p.x * (p.x * p.x + p.y * p.y + p.z * p.z + R * R - r * r) - 8 * R * R * p.x;
  res.x = 4 * p.y * (p.x * p.x + p.y * p.y + p.z * p.z + R * R - r * r);
  res.x = 4 * p.z * (p.x * p.x + p.y * p.y + p.z * p.z + R * R - r * r) - 8 * R * R * p.z;
  return res;
}


