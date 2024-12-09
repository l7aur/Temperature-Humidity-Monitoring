#include "Fan.hpp"

void Fan::setupFan() const
{
	pinMode(powerPin, OUTPUT);
}

void Fan::powerOn(uint8_t howMuch)
{
	analogWrite(powerPin, howMuch);
}
