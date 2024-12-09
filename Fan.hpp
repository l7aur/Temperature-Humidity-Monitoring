#pragma once

#include <stdint.h>
#include "Arduino.h"

class Fan {
public:
	void setupFan() const;
	void powerOn(uint8_t howMuch);
private:
	const int powerPin{ 5 };
};