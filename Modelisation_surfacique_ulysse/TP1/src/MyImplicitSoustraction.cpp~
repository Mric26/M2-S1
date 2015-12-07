#include "MyImplicitSoustraction.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

float MyImplicitSoustraction::Eval(glm::vec3 p) const{
  float res1 = f1->Eval(p);
  float res2 = f2->Eval(p);
  
  return res1 * res2;
  
  
  
  if( res1 >= res2){
    return res1;
  }
  else{
    return res1 - res2;
  }
}


glm::vec3 MyImplicitSoustraction::EvalDev(glm::vec3 p) const{ 
  float res1 = f1->Eval(p);
  float res2 = f2->Eval(p);  
  if( res1 >= res2){
    return f1->EvalDev(p);
  }
  else{
    return f2->EvalDev(p);
  }
}


