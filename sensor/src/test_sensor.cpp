#include <iostream>
#include "TemperatureSensor.hpp"
#include "DistanceSensor.hpp"
#include "PressureSensor.hpp"

int main() {
    std::unique_ptr<Sensor> tempSensor = std::make_unique<TemperatureSensor>("TempSensor1"); // Create a TemperatureSensor object with ID "TempSensor1"
    std::unique_ptr<Sensor>  distSensor = std::make_unique<DistanceSensor>("DistSensor1");
    std::unique_ptr<Sensor> presSensor = std::make_unique<PressureSensor>("PressureSensor1");
    std::cout << "Sensor Readings: \n";
    for (int i = 0; i < 5; ++i) { // Loop to generate and display 5 readings
        double reading = tempSensor->read(); // Read the temperature
        std::cout << "Temp Reading " << i + 1 << ": " << reading << "°C\n"; // Output the reading
        double distanceReading = distSensor->read(); // Read the distance
        std::cout << "Distance Reading " << i + 1 << ": " << distanceReading << " meters\n"; // Output the reading
        double pressureReading = presSensor->read(); // Read the pressure
        std::cout << "Pressure Reading " << i + 1 << ": " << pressureReading << " hPa\n"; // Output the reading
    }
    return 0;
}