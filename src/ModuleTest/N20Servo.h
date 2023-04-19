#ifndef N20Servo_h
#define N20Servo_h

#include "Arduino.h"


class N20Servo
{

    public:

    N20Servo();
    ~N20Servo();
    void setk(float k [3]);
    int readSens(); //reads the sensor
    int sval();
    void assignpins(int pins [3]); //setup pins
    void act(int pA, int pB); //actuates
    void goTo(int target, int maxvel); //go to angle with maxvel in pwm
    void setrefs(int refs [2]); //refs for 90 and 0 degrees
    float setKgrad();
    unsigned long SR;

    private:

      int _sensval;
      int _pinA;
      int _pinB;
      int _pinsens;
      float _Kp;
      float _Kd;
      float _Ki;
      double _preverror;
      int Ierror;
      int Derror;
      int _ref_0;
      int _ref_90;
      float _kgrad;
      float _thI;
      unsigned long currenttime;
      unsigned long previoustime;
      double elapsedtime;

};

#endif //N20Servo_H
