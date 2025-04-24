#include "Sensor.hpp"

Sensor::Sensor(std::string id) : id_(std::move(id)) {}

const std::string& Sensor::getId() const noexcept {
    return id_;
}

double Sensor::getLastReading() const noexcept {
    return lastReading_;
}

void Sensor::setLastReading(double value) noexcept {
    lastReading_ = value;
}

