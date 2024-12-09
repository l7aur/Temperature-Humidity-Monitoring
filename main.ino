#include "Led.hpp"
#include "DHT22Sensor.hpp"
#include "LedModule.hpp"
#include "LCD.hpp"
#include "Fan.hpp"

LED myLed(MAGENTA);
DHT22Sensor myDHT22Sensor;
LedModule ledModule;
Fan myFan;

float currentTime{0.0f};    // in MILISECONDS
float previousTime{0.0f};   // in MILISECONDS
float deltaTime{0.0f};      // in MILISECONDS
const float MAX_DELTA_TIME{500.0f}; // in MILISECONDS

void setup()
{
  Serial.begin(9600);
  myLed.setupLed();
  myDHT22Sensor.setupSensor();
  ledModule.setupLedModule();
  LCD::getInstance().setupLCD();
  myFan.setupFan();
}

void loop()
{
  currentTime = millis();
  deltaTime += currentTime - previousTime;
  if(deltaTime > MAX_DELTA_TIME) {
    float newT = myDHT22Sensor.readTempearture();
    float newH = myDHT22Sensor.readHumidity();
    temperatureEventManager(newT);
    humidityEventManager(newH);
    deltaTime = 0.0f;
  }
  previousTime = currentTime;
}

void temperatureEventManager(float temperature)
{
  uint8_t fanPowerFactor = 0;
  if (temperature <= 5.0f)
  {
    myLed.setColor(BLUE);
    LCD::getInstance().displayMessage("Brrr!");
  }
  else if (temperature <= 20.0f)
  {
    myLed.setColor(GREEN);
    LCD::getInstance().displayMessage("Spring-like!");
  }
  else if (temperature <= 28.0f)
  {
    fanPowerFactor = 100;
    myLed.setColor(YELLOW);
    LCD::getInstance().displayMessage("Just right!");
  }
  else if (temperature <= 32.0f)
  {
    fanPowerFactor = 175;
    myLed.setColor(RED);
    LCD::getInstance().displayMessage("It's too hot!");
  }
  else {
    fanPowerFactor = 255;
    myLed.setColor(MAGENTA);
    LCD::getInstance().displayMessage("Overheat!");
  }
  myLed.displayColor();
  myFan.powerOn(fanPowerFactor);
}

void humidityEventManager(float humidity)
{
  const int LED_MODULE_SIZE = ledModule.getNumberOfLeds();
  if(humidity > 100.0f)
    for(unsigned i = 0; i < LED_MODULE_SIZE; i++)
      ledModule.turnOffLed(i);

  bool whatToTurnOn[LED_MODULE_SIZE]{false};
  float relativeHumidityThresholds[LED_MODULE_SIZE] = {5.0f, 14.3f, 28.6f, 42.9f, 57.2f, 71.5f, 85.8f, 100.0f};
  for(unsigned i = 0; i < LED_MODULE_SIZE; i++)
    if(humidity > relativeHumidityThresholds[i])
      whatToTurnOn[i] = true;
  for(unsigned i = 0; i < LED_MODULE_SIZE; i++)
      (whatToTurnOn[i]) ? ledModule.turnOnLed(i) : ledModule.turnOffLed(i);
}