cmake_minimum_required(VERSION 3.10)
project(CLI_Calculator LANGUAGES CXX)

# 1) Define the executable and list your .cpp files:
add_executable(calculator
    src/main.cpp
    src/Tokenizer.cpp
    src/Parser.cpp
    src/Evaluator.cpp
)

# 2) Require C++17 (inherited from your top-level if you set it there):
target_compile_features(calculator PRIVATE cxx_std_17)
set(CMAKE_CXX_EXTENSIONS OFF)

# 3) Tell this target to look in calculator/include for headers:
#    CMAKE_CURRENT_SOURCE_DIR is the path to the folder containing this CMakeLists.txt
target_include_directories(calculator
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# (Optional) Warnings as errors
# target_compile_options(calculator PRIVATE -Wall -Wextra -Werror)
