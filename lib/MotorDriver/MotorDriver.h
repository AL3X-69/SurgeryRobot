// motor shield library
// by Alex6
// 18/03/2021
#ifndef __MOTORDRIVER_H__
#define __MOTORDRIVER_H__

#include <Arduino.h>
/******Pins definitions*************/
#define MOTORSHIELD_IN1	12
#define MOTORSHIELD_IN2	13
#define SPEEDPIN_B		10

/**Class for Motor Shield**/
class MotorDriver {

  private:
    int speed;

  public:

    void begin();

    // speed: 0~100
    void goSpeed(int _speed);
    void stop();
    void unbrake();
    void brake();
    void revert(bool brakeAndRestart);

};


#endif
