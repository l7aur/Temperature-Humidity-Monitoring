#ifndef LED_HPP
#define LED_HPP

#include "Types.hpp"
#include "Arduino.h"

class LED {
public:
    explicit LED (Color newColor) : color(newColor) {};
    void setupLed();
    int getRedPin() const { return redPin; };
    int getGreenPin() const { return greenPin; };
    int getBluePin() const { return bluePin; };
    Color getColor() const { return color; };
    void setColor(Color newColor) { color = newColor; };
    void displayColor() const;
private:
    const int redPin = 11;
    const int greenPin = 10;
    const int bluePin = 9;
    Color color;
};

#endif