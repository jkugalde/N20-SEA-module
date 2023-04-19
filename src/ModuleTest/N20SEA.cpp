#include "N20SEA.h"

N20SEA::N20SEA(){

}

N20SEA::~N20SEA()
{
    //dtor
}

int N20SEA::sval2(){

int s2 = analogRead(_senspin);
return s2;

}

int N20SEA::torque(){

int r = 5*(sval() - sval2());
return r;

}

float N20SEA::setKgradB(){ //transformation constant from degrees to values.

  _kgradB=float((_ref_90B-_ref_0B)/90.0);
  return _kgradB;

}

void N20SEA::assigntorquesens(int i){

  _senspin = i;
  pinMode(_senspin,INPUT);

}

void N20SEA::setrefsB(int refs[2]){

_ref_0B=refs[0];
_ref_90B=refs[1];

}