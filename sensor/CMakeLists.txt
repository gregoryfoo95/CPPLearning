cmake_minimum_required(VERSION 3.10)
project(SensorSimulator LANGUAGES CXX)


add_executable(sensor
    src/Sensor.cpp
    src/TemperatureSensor.cpp
    src/test_sensor.cpp
    src/DistanceSensor.cpp
    src/PressureSensor.cpp
)
target_include_directories(sensor
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(sensor PRIVATE cxx_std_17)

# Optional: Add warnings for better code quality
target_compile_options(sensor PRIVATE
    -Wall -Wextra -Wpedantic
)