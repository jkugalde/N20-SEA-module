#include "N20Servo.h"


N20Servo::N20Servo()
{

_Kp=0; //pid constants and variables initialization
_Kd=0;
_Ki=0;
_preverror=0;
_thI=8;
Derror=0;
Ierror=0;
_sensval=0;
elapsedtime=0;
currenttime=0;
previoustime=0;


}

void N20Servo::assignpins(int pins [3]){

  _pinA=pins[0];
  _pinB=pins[1];
  _pinsens=pins[2];
  pinMode(_pinA,OUTPUT);
  pinMode(_pinB,OUTPUT);
  digitalWrite(_pinA,LOW);
  digitalWrite(_pinB,LOW);
  pinMode(_pinsens,INPUT);

}

N20Servo::~N20Servo()
{
    //dtor
}


int N20Servo::readSens(){ //read the analog value of the sensor

	_sensval=analogRead(_pinsens);
	return _sensval;

}

int N20Servo::sval(){ //read the analog value of the sensor

	return _sensval;

}

void N20Servo::act(int pA, int pB){

	analogWrite(_pinA,pA);
  analogWrite(_pinB,pB);

}

void N20Servo::setk(float k [3]){ //assign pid constants

	_Kp=k[0];
  _Kd=k[1];
  _Ki=k[2];

}

float N20Servo::setKgrad(){ //transformation constant from degrees to values.

  _kgrad=float((_ref_90-_ref_0)/90.0);
  return _kgrad;

}

void N20Servo::setrefs(int refs[2]){ 
  _ref_0=refs[0];
  _ref_90=refs[1];
  setKgrad();
}

void N20Servo::goTo(int target, int maxvel){

  target=int(_kgrad*target)+_ref_0;
  int pos = readSens();
  double error = target-pos;

  currenttime=millis();
  elapsedtime=double(currenttime-previoustime);
 
  Derror = (error-_preverror)/elapsedtime;
  Ierror +=error*elapsedtime;

  // if(abs(error)<=_thI){
  //   Ierror=0;
  // }
  // if (error==0){
  //   Ierror=0;
  // }
  //   if (_preverror>0 && error<0 || error>0 && _preverror<0){
  //   Ierror=0;
  // }

  // Serial.print("error: ");
  // Serial.println(error);
  // Serial.print("Derror: ");
  // Serial.println(Derror);
  // Serial.print("Ierror: ");
  // Serial.println(Ierror);
  
  double pow=int(_Kp*error)+int(_Kd*Derror)+int(_Ki*Ierror);

  _preverror=error;
  previoustime=currenttime;
  
  pow=constrain(pow,-maxvel,maxvel);
  pow=int(pow);
  
  if(pow>0){ //direction
    act(pow,0);
  }
  else{  
    act(0,-pow);
  }

}