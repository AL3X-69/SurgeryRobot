#include <Arduino.h>
#include <MotorDriver.h>

MotorDriver motor;

void setup() {
    motor.begin();
}

void loop() {
    motor.goSpeed(100);
    delay(1000);
    motor.stop();
    delay(500);
    motor.goSpeed(-100);
    delay(1000);
}