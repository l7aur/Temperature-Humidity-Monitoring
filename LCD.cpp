#include "LCD.hpp"

LCD LCD::singletonInstance;

LCD::LCD() : lcdInstance(address, numberOfColumns, numberOfRows) {}

LCD& LCD::getInstance()
{
    return singletonInstance;
}

void LCD::setupLCD()
{
    lcdInstance.init();
    lcdInstance.backlight();
}