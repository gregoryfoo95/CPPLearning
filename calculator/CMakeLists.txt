
# ✅ **What it does**:  
# Sets the **minimum required CMake version** that your project will support.

# 🧠 **Why it matters**:
# - CMake adds new features over time.
# - Specifying `3.10` ensures your code won't silently break with older CMake versions.
# - Version 3.10 is a good baseline for C++17 projects.

# ---

cmake_minimum_required(VERSION 3.10) 
project(CLI_Calculator)


# ✅ **What it does**:  
# Instructs the compiler to use the **C++17 standard** when building the project.

# 🧠 **Why it matters**:
# - Enables use of modern features like `std::optional`, `std::variant`, `if constexpr`, structured bindings, etc.
# - Keeps your code forward-compatible with newer compilers

# 📌 You can also add:
# ```cmake
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)  # Forces strict ISO C++17

set(CMAKE_CXX_STANDARD 17)

# ✅ **What it does**:  
# Creates a **variable `SRC_FILES`** that holds all the source files you want to compile.

# 🧠 **Why it matters**:
# - Makes your file list modular and easy to expand.
# - Useful for larger projects with many files.

# ---
# Source files
set(SRC_FILES
    src/main.cpp
    src/Tokenizer.cpp
    src/Parser.cpp
    src/Evaluator.cpp
)

✅ What it does:
# Tells the compiler to search the include/ directory when resolving #include headers.

# 🧠 Why it matters:

# Without this, #include "utils.hpp" would fail unless it was in the same directory as the .cpp file.

# This is how you expose header-only libraries or shared interfaces to multiple translation units.
# Include headers
include_directories(include)

# ✅ **What it does**:  
# Tells CMake to **compile all source files** in `${SRC_FILES}` and link them into an **executable** called `calculator`.

# 🧠 **Why it matters**:
# - This is the build target that will result in your compiled app.
# - You can now run `./calculator` after building.
# Build executable
add_executable(calculator ${SRC_FILES})