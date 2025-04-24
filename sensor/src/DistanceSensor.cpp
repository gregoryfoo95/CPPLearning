#include "DistanceSensor.hpp"

DistanceSensor::DistanceSensor(std::string id) : Sensor(std::move(id)) {} // Constructor that initializes the sensor with an ID
double DistanceSensor::read() {
    double reading = distribution_(engine_); // Generate a random distance reading
    setLastReading(reading); // Store the last reading
    return reading; // Return the generated reading
}