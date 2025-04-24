#include "PressureSensor.hpp"

PressureSensor::PressureSensor(std::string id) : Sensor(std::move(id)) {} // Constructor that initializes the sensor with an ID
double PressureSensor::read() {
    double reading = distribution_(engine_); // Generate a random pressure reading
    setLastReading(reading); // Store the last reading
    return reading; // Return the generated reading
}