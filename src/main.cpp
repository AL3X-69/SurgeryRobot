#include <Arduino.h>
#include <MotorDriver.h>
#include "math.h"

MotorDriver motor;
int mAngle = 0;

void setup() {
    motor.begin();
    Serial.begin(9000);
    motor.goSpeed(100);
    delay(500);
    motor.goSpeed(-100);
    delay(500);
    motor.stop();
}

void loop() {
    //int angle = asin((5*analogRead(A0)-1687.95)/306.9);
    //Serial.println(angle);
    /*Serial.println(mAngle);
    Serial.println(mAngle - angle);
    Serial.println();
    if (abs(mAngle - angle) >= 10) {
        mAngle = angle;
        motor.unbrake();
        if (mAngle > angle) {
            motor.goSpeed(-100);

        } else {
            mAngle = angle;
            motor.goSpeed(100);
        }
    } else if (abs(mAngle - angle) > 1) {
        mAngle = angle;
        motor.unbrake();
        if (mAngle > angle) {
            motor.goSpeed(-10);

        } else {
            motor.goSpeed(10);
        }
    } else {
        motor.stop();
        motor.brake();
    }
    /*motor.goSpeed(100);
    delay(1000);
    motor.stop();
    delay(500);
    motor.goSpeed(-100);*/
    //delay(1000);
    motor.goSpeed(100);
    delay(1000);
    motor.brake();
    delay(500);
    motor.goSpeed(-100);
    delay(1000);
    motor.brake();
    delay(500);
}