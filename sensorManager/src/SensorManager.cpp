#include "SensorManager.hpp"
#include "Sensor.hpp"
#include <utility>

bool SensorManager::addSensor(std::unique_ptr<Sensor> sensor)
{
    // if (!sensor) {
    //     return false; // Return false if the sensor is null
    // }
    // const std::string& id = sensor->getId();

    // // This searches the std::map for the key id.
    // // If the key exists, it returns an iterator pointing to the element with that key.
    // // If the key does not exist, it returns sensors_.end(), which is an iterator representing "one past the last element" in the map.
    // if (sensors_.find(id) != sensors_.end()) {
    //     return false; // Return false if a sensor with the same ID already exists
    // }
    // sensors_[id] = std::move(sensor); // Add the sensor to the map
    // return true; // Return true on successful addition

    // The sensors_.emplace method in C++ returns a std::pair containing the following:
    //  it (iterator):
    //  An iterator pointing to the element in the map with the given key.
    //  If the insertion was successful, this iterator points to the newly inserted element.
    //  If the insertion failed (because the key already exists), this iterator points to the existing element with the same key.
    //  inserted (bool):

    // A boolean value indicating whether the insertion was successful.
    // true if the element was successfully inserted.
    // false if the key already exists in the map, and no insertion occurred.
    auto id = sensor->getId();
    auto [it, inserted] = sensors_.emplace(id, std::move(sensor));
    return inserted;
}

bool SensorManager::removeSensor(const std::string &id)
{
    // erase(id) returns the number of elements removed from the map
    return sensors_.erase(id) > 0; // Remove the sensor by ID and return true if successful
}

// Benefits of std::reference_wrapper:
// The caller gets a vector of references to the Sensor objects, ensuring they cannot accidentally take ownership or delete the objects.
// It avoids the risks of dangling pointers while maintaining efficient access to the Sensor objects.
std::vector<std::reference_wrapper<Sensor>> SensorManager::getSensors() const
{
    std::vector<std::reference_wrapper<Sensor>> sensorList;
    for (const auto &pair : sensors_)
    {
        sensorList.push_back(*pair.second); // Dereference the unique_ptr and wrap the Sensor in a reference_wrapper
    }
    return sensorList; // Return the vector of sensor references
}

// Smart Pointer:

// std::unique_ptr<Sensor> is a smart pointer that owns the Sensor object. It manages the lifetime of the object and ensures proper cleanup when the unique_ptr goes out of scope.
// Raw Pointer:

// When you call .get() on a std::unique_ptr, it returns the raw pointer (Sensor*) to the managed object. This raw pointer does not transfer ownership; it simply provides access to the underlying object.

// Why is this a concern?
// Raw pointers (Sensor*) do not convey ownership semantics, which can lead to misuse (e.g., accidental deletion or dangling pointers).
// By returning raw pointers, the caller might assume they own the object, which is not the case.
// Using std::reference_wrapper or returning std::shared_ptr<Sensor> instead of raw pointers can help avoid these issues.

// Summary:
// std::reference_wrapper helps by providing safe, non-owning references to the Sensor objects, avoiding the risks of raw pointers.
// The term "raw pointer" refers to the unmanaged pointer (Sensor*) returned by .get() from a smart pointer like std::unique_ptr. It is not a smart pointer itself but simply a way to access the underlying object.

std::optional<std::reference_wrapper<Sensor>> SensorManager::getSensorById(const std::string &id) const
{
    auto it = sensors_.find(id); // Find the sensor by ID
    if (it == sensors_.end())
    {
        return std::nullopt; // Return nullopt if the sensor is not found
    }
    return std::ref(*(it->second)); // Return a reference to the found sensor
}

std::map<std::string, double> SensorManager::readSensors()
{
    std::map<std::string, double> readings;
    for (const auto &pair : sensors_)
    {
        const auto &sensor = pair.second; // Get the unique_ptr to the sensor
        if (sensor)
        {
            readings[pair.first] = sensor->read(); // Read the sensor and store the reading in the map
        }
    }
    return readings; // Return the map of sensor readings
}