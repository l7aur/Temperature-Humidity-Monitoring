#include "Buzzer.hpp"

void Buzzer::setupBuzzer() const
{
    pinMode(dataPin, OUTPUT);
    turnOff();
}

void Buzzer::turnOn(int noteFrequency, Notes duration)
{
    int stall = duration * this->pauseStretch;
    tone(dataPin, noteFrequency, duration);
    delay(stall);
    noTone(dataPin);
}

void Buzzer::turnOff()
{
    analogWrite(dataPin, 255);
}

void Buzzer::buzzerLoop()
{
}
