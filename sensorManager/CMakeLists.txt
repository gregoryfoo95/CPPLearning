cmake_minimum_required(VERSION 3.10)
project(SensorManager LANGUAGES CXX)


add_executable(sensorManager
    src/SensorManager.cpp
    src/sensor_manager_test.cpp
    ../sensor/src/Sensor.cpp
    ../sensor/src/TemperatureSensor.cpp
    ../sensor/src/DistanceSensor.cpp
)

target_include_directories(sensorManager
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include  # Local include directory for sensorManager
    ${CMAKE_CURRENT_SOURCE_DIR}/../sensor/include  # Include directory from the sensor project
)

target_compile_features(sensorManager PRIVATE cxx_std_17)

# Optional: Add warnings for better code quality
target_compile_options(sensorManager PRIVATE
    -Wall -Wextra -Wpedantic
)