#include "N20SEA.h"

const int pinsA1[3] = {2,3,A0};

const float kA[3] = {2.0,1.0,0.0005}; // PID values, kp, kd, ki
const int refsA[2] = {510,255}; //analog reference for angle 0 and 90 (from the horizontal)

unsigned long timer = 0;
unsigned long dt = 10;
float theta = 0;
float c = 0;
unsigned long LT = 0;
unsigned long SR = 10;

N20SEA MA1;

void setup() {

 MA1.assignpins(pinsA1);
 MA1.assigntorquesens(A1);
 MA1.setrefsB(refsA);
 MA1.setk(kA); 
 MA1.setrefs(refsA);
 Serial.begin(9600);
 timer=millis();

}

void loop() {

if(Serial.available()>0){

c=Serial.parseInt()*1.0;

}

MA1.goTo(c,200);

}

