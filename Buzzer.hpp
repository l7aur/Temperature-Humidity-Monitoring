#ifndef BUZZER_HPP
#define BUZZER_HPP

#include "Arduino.h"
#include "Pitches.hpp"
#include "Types.hpp"

class Buzzer
{
public:
    Buzzer() {};
    void setupBuzzer() const;
    void turnOn(int noteFrequency, Notes duration);
    void turnOff();
    void buzzerLoop();
private:
    const int dataPin{3}; // PWM PIN
    float pauseStretch{1.3f};
};

#endif