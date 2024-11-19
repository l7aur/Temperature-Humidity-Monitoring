#ifndef LED_MODULE_HPP
#define LED_MODULE_HPP

#include "Arduino.h"

class LedModule
{
public:
    LedModule() {};
    void setupLedModule() const;
    int getLedPin(int index) const;
    void turnOnLed(int index) const;
    void turnOffLed(int index) const;
private:
    const int leds[8]{1, 2, 3, 4, 5, 6, 7, 8};
    const int numberOfLeds{8};
};

#endif