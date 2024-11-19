#include "Led.hpp"
#include "DHT22Sensor.hpp"
#include "Buzzer.hpp"

LED myLed(RED);
DHT22Sensor myDHT22Sensor;
Buzzer buzzer;

int notes[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
Notes durations[] = {QUARTER, EIGTH, EIGTH, QUARTER, QUARTER, QUARTER, QUARTER, QUARTER};

void setup()
{
  Serial.begin(9600);
  myLed.setupLed();
  myLed.displayColor();
  myDHT22Sensor.setupSensor();
  buzzer.setupBuzzer();

  for (int i = 0; i < 8; i++)
    buzzer.turnOn(notes[i], 1000 / durations[i]);
  buzzer.turnOff();
}

void loop()
{
  myDHT22Sensor.sensorLoop();
}
