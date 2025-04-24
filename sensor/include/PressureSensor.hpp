#pragma once
#include "Sensor.hpp"
#include <random>

class PressureSensor : public Sensor {
    public:
        explicit PressureSensor(std::string id);
        double read() override;

    private:
        std::mt19937 engine_{std::random_device{}()}; // Random number generator
        std::uniform_real_distribution<double> distribution_{950.0, 1050.0}; // Simulate pressure between 950 and 1050 hPa
};