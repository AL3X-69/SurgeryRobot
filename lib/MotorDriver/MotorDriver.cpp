#include "MotorDriver.h"

void MotorDriver::begin() {
    speed = 0;
    pinMode(MOTORSHIELD_IN1, OUTPUT);
    pinMode(MOTORSHIELD_IN2, OUTPUT);
    digitalWrite(MOTORSHIELD_IN1, LOW);
    digitalWrite(MOTORSHIELD_IN2, LOW);
}

void MotorDriver::stop() {
    goSpeed(0);
}

void MotorDriver::brake() {
    digitalWrite(MOTORSHIELD_IN1, HIGH);
    digitalWrite(MOTORSHIELD_IN2, HIGH);
    speed = 0;
}

void MotorDriver::unbrake() {
    digitalWrite(MOTORSHIELD_IN1, LOW);
    digitalWrite(MOTORSHIELD_IN2, LOW);
    speed = 0;
}

void MotorDriver::goSpeed(int _speed) {
    _speed = _speed < -100 ? -100 : _speed;
    _speed = _speed > 100 ? 100 : _speed;

    if (speed == _speed) {
        return;
    } else {
        speed = _speed;
    }
    if (_speed > 0) {
        digitalWrite(MOTORSHIELD_IN1, HIGH);
        digitalWrite(MOTORSHIELD_IN2, LOW);
        analogWrite(SPEEDPIN_B, _speed*255/100);
    } else if (_speed < 0) {
        digitalWrite(MOTORSHIELD_IN1, LOW);
        digitalWrite(MOTORSHIELD_IN2, HIGH);
        analogWrite(SPEEDPIN_B, -_speed*255/100);

    } else {
        digitalWrite(MOTORSHIELD_IN1, LOW);
        digitalWrite(MOTORSHIELD_IN2, LOW);
        analogWrite(SPEEDPIN_B, 0);

    }
}

void MotorDriver::revert(bool brakeAndRestart) {
    if (brakeAndRestart) {
        brake();
        delay(500);
    }
    goSpeed(-speed);
    unbrake();
}