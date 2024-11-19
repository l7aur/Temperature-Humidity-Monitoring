#ifndef LCD_HPP
#define LCD_HPP

#include <LiquidCrystal_I2C.h>

class LCD
{
public:
    static LCD& getInstance();
    void setupLCD();
private:
    LCD();
    LCD(const LCD&) = delete;
    LCD& operator=(const LCD&) = delete;
    static LCD singletonInstance;
    const int address{0x27};
    const int numberOfRows{2};
    const int numberOfColumns{16};
    LiquidCrystal_I2C lcdInstance;
};

#endif