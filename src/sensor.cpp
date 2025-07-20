#include "sensor.h"
#include <Arduino.h>

static const int pirPin = 15;

void initSensor() {
    pinMode(pirPin, INPUT);
}

bool readMotion() {
    return digitalRead(pirPin);
}
