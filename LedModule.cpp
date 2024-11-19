#include "LedModule.hpp"

void LedModule::setupLedModule() const
{
    for(int i = 0; i < numberOfLeds; i++) {
        pinMode(leds[i], OUTPUT);
        turnOffLed(i);
    }
}

int LedModule::getLedPin(int index) const
{
    return (index < 0) ? leds[0] : (index >= numberOfLeds) ? leds[numberOfLeds - 1]
                                                           : leds[index];
}

void LedModule::turnOffLed(int index) const
{
    int i = (index < 0) ? leds[0] : (index >= numberOfLeds) ? leds[numberOfLeds - 1]
                                                           : leds[index];
    digitalWrite(i, HIGH);
}

void LedModule::turnOnLed(int index) const
{
    int i = (index < 0) ? leds[0] : (index >= numberOfLeds) ? leds[numberOfLeds - 1]
                                                           : leds[index];
    digitalWrite(i, LOW);
}
