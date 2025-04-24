#pragma once
#include "Sensor.hpp"
#include <random>

class TemperatureSensor : public Sensor {
    public:
        explicit TemperatureSensor(std::string id);
        double read() override;

    private:
        std::mt19937 engine_{std::random_device{}()}; // Random number generator
        std::uniform_real_distribution<double> distribution_{20.0, 40.0}; // Simulate temperature between -10 and 40 degrees Celsius
};

