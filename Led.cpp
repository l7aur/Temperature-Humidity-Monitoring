#include "Led.hpp"

void LED::setupLed() const {
    pinMode(getRedPin(), OUTPUT);
    pinMode(getGreenPin(), OUTPUT);
    pinMode(getBluePin(), OUTPUT);
}

void LED::displayColor() const {
    analogWrite(getRedPin(), getColor().red);
    analogWrite(getGreenPin(), getColor().green);
    analogWrite(getBluePin(), getColor().blue);
}