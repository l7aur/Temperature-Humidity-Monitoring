#include "Led.hpp"
#include "DHT22Sensor.hpp"
#include "LedModule.hpp"
#include "LCD.hpp"

LED myLed(RED);
DHT22Sensor myDHT22Sensor;
LedModule ledModule;
LCD display;

void setup()
{
  // Serial.begin(9600);
  myLed.setupLed();
  myLed.displayColor();
  // myDHT22Sensor.setupSensor();
  ledModule.setupLedModule();
  display.getInstance().setupLCD();
}

int index = 6;

void loop()
{
  index = (index + 1) % 8;
  ledModule.turnOnLed(index);
  delay(1000);
  ledModule.turnOffLed(index);
  // myDHT22Sensor.sensorLoop();
}
