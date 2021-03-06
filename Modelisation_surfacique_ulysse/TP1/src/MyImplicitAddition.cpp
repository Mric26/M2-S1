#include "MyImplicitAddition.h"

#include <iostream>
#include <math.h>

using namespace glm;
using namespace std;

float MyImplicitAddition::Eval(glm::vec3 p) const{
  //float res = max( f1->Eval(p), f2->Eval(p) );
  float res1 = f1->Eval(p);
  float res2 = f2->Eval(p);
  if( res1 <= res2){
    return res1;
  }
  else{
    return res2;
  }
}


glm::vec3 MyImplicitAddition::EvalDev(glm::vec3 p) const{ 
  float res1 = f1->Eval(p);
  float res2 = f2->Eval(p);
  if( res1 <= res2){
    return f1->EvalDev(p);
  }
  else{
    return f2->EvalDev(p);
  }
}


