#include "DHT22Sensor.hpp"

float DHT22Sensor::readTempearture()
{
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature))
        return -1;
    return event.temperature;
}

float DHT22Sensor::readHumidity()
{
    sensors_event_t event;
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity))
        return -1;
    return event.relative_humidity;
}
