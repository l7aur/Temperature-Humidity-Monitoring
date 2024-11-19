#include "Led.hpp"
#include "DHT22Sensor.hpp"

LED myLed(RED);
DHT22Sensor myDHT22Sensor;


//test
void setup() {
  Serial.begin(9600);
  myLed.setupLed();
  myLed.displayColor();
  myDHT22Sensor.setupSensor();
}

void loop() {
  myDHT22Sensor.sensorLoop();
}
