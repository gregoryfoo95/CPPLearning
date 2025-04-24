#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(std::string id) : Sensor(std::move(id)) {}
double TemperatureSensor::read() {
    double reading = distribution_(engine_); // Generate a random temperature reading
    setLastReading(reading); // Store the last reading
    return reading; // Return the generated reading
}