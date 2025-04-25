#pragma once
#include "Sensor.hpp"
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <optional>
#include <functional>

class SensorManager {
    public:
        SensorManager() = default; //SensorManager() = default; is used to explicitly declare the default constructor, ensuring clarity, proper initialization of members, and adherence to modern C++ best practices. It also avoids potential issues where the default constructor might be suppressed by other constructors or member declarations.

        // Add a sensor to the manager
        // 1. Ownership Semantics
        // A std::unique_ptr enforces exclusive ownership of the Sensor object. When you pass a std::unique_ptr<Sensor> to addSensor, ownership of the Sensor is transferred to the SensorManager class.
        // This ensures that the SensorManager is responsible for managing the lifetime of the Sensor object, and no other part of the code can accidentally modify or delete it.
        // 2. Automatic Resource Management
        // Since std::unique_ptr automatically deletes the object it owns when it goes out of scope, you don't need to manually manage the memory of the Sensor objects.
        // This prevents memory leaks, as the SensorManager will clean up all Sensor objects when it is destroyed.
       bool addSensor(std::unique_ptr<Sensor> sensor);

        // Remove a sensor by ID
        bool removeSensor(const std::string& id);

        //std::optional<Sensor*> does not directly indicate that the return value can be nullptr. Instead:
        // An empty std::optional means no sensor was found.
        // A non-empty std::optional containing a nullptr means a sensor was found, but its pointer is null.
        // Get a sensor by ID
        std::optional<std::reference_wrapper<Sensor>> getSensorById(const std::string& id) const;

        // Get all sensors
        std::vector<std::reference_wrapper<Sensor>> getSensors() const;

        // Read all sensors and return their readings
        std::map<std::string, double> readSensors();

    private:
        std::map<std::string, std::unique_ptr<Sensor>> sensors_; // Map to store sensors with their IDs
};