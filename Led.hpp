#ifndef LED_HPP
#define LED_HPP

#include "Types.hpp"
#include "Arduino.h"

class LED
{
public:
    explicit LED(Color newColor) : color(newColor) {};
    void setupLed() const;
    int getRedPin() const { return redPin; };
    int getGreenPin() const { return greenPin; };
    int getBluePin() const { return bluePin; };
    Color getColor() const { return color; };
    void setColor(Color newColor) { color = newColor; };
    void displayColor() const;

private:
    const int redPin{11};   // PWM pin
    const int greenPin{10}; // PWM pin
    const int bluePin{9};   // PWM pin
    Color color;
};

#endif