#ifndef LED_MODULE_HPP
#define LED_MODULE_HPP

#include "Arduino.h"

class LedModule
{
public:
    LedModule() {};
    void setupLedModule() const;
    int getLedPin(int index) const;
    int getNumberOfLeds() const { return numberOfLeds; };
    void turnOnLed(int index) const;
    void turnOffLed(int index) const;
private:
    const int leds[7]{13, 2, 3, 4, 6, 7, 8};
    const int numberOfLeds{7};
};

#endif