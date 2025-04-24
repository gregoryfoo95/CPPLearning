#pragma once
#include "Sensor.hpp"
#include <random>

class DistanceSensor : public Sensor {
    public:
        explicit DistanceSensor(std::string id);
        double read() override;

    private:
        std::mt19937 engine_{std::random_device{}()}; // Random number generator
        std::uniform_real_distribution<double> distribution_{0.0, 100.0}; // Simulate distance between 0 and 100 meters
};