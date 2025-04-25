cmake_minimum_required(VERSION 3.10)
project(CPPLearning)

# Global C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the calculator subproject
add_subdirectory(calculator)
add_subdirectory(sensor)
add_subdirectory(sensorManager)