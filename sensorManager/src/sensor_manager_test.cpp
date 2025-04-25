#include <iostream>
#include "SensorManager.hpp"
#include "Sensor.hpp"
#include "TemperatureSensor.hpp"
#include "DistanceSensor.hpp"

int main () {

    SensorManager sensorManager;
    sensorManager.addSensor(std::make_unique<TemperatureSensor>("TempSensor1"));
    sensorManager.addSensor(std::make_unique<DistanceSensor>("DistSensor1"));
    std::cout << sensorManager.getSensorById("TempSensor1")->get().read() << std::endl;
    
    for (const auto& [id, reading] : sensorManager.readSensors()) {
        std::cout << "Sensor ID: " << id << ", Reading: " << reading << std::endl;
    }

    std::cout << sensorManager.getSensorById("TempSensor1")->get().read() << std::endl;

    if (auto sensorOpt = sensorManager.getSensorById("XSensor")) {
        // If the sensor exists, safely access it
        std::cout << sensorOpt->get().read() << std::endl;
    } else {
        // Handle the case where the sensor is not found
        std::cout << "Sensor with ID 'XSensor' not found!" << std::endl;
    }
    
    sensorManager.removeSensor("TempSensor1");

    for (const auto& [id, reading] : sensorManager.readSensors()) {
        std::cout << "Sensor ID: " << id << ", Reading: " << reading << std::endl;
    }

    return 0;
}