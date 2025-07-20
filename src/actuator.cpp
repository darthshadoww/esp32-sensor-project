#include "actuator.h"
#include <ESP32Servo.h>

static Servo lockServo;
static const int servoPin = 13;

void initActuator() {
    lockServo.attach(servoPin);
    setLocked();
}

void setLocked() {
    lockServo.write(0);
}

void setUnlocked() {
    lockServo.write(90);
}
