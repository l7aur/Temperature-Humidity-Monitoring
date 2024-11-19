#ifndef DHT22_SENSOR
#define DHT22_SENSOR

#include <stdint.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class DHT22Sensor {
public:
    DHT22Sensor() : dht(12, DHT22) {};
    void setupSensor();
    void sensorLoop();
private:
    const int dataPin = 12;
    DHT_Unified dht;
    uint32_t delayMS;
};

#endif