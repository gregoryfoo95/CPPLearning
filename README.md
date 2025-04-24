# C++ Learning Journey for Beginner Robotics Engineer

Welcome to your personalized C++ learning program tailored for robotics! This roadmap is structured into **3 progressive phases**, each designed to build up your skills from foundational programming to robotics-oriented systems.

---

## 📅 **Phase 1: Core Modern C++ (Weeks 1–4)**

### **Week 1 – C++ Basics**
**Topics**: Data types, control flow, functions, references/pointers, vectors  
**Project**: `CLI Calculator`
- Input: Expression as a string (e.g. `5 * (3 + 2)`)
- Output: Result of expression
- Features:
  - Basic expression parser
  - Operator precedence
  - Error handling (e.g. divide by zero)

---

### **Week 2 – OOP and Class Design**
**Topics**: Classes, constructors/destructors, encapsulation, inheritance  
**Project**: `Sensor Simulator`
- Implement a base class `Sensor` with method `read()`
- Inherit `TemperatureSensor`, `DistanceSensor`, `PressureSensor`
- Features:
  - Virtual methods
  - Constructor logging
  - Destructor cleanup

🚩 Week 2 – OOP & Class Design
Goal
Get comfortable defining C++ classes, constructors/destructors, encapsulation, inheritance, and virtual methods by modeling a family of “Sensor” objects.

🛠 Tasks & Features
Define a polymorphic base class Sensor

File: include/Sensor.hpp

Members (protected/private):

std::string id;

double lastReading;

API (public):

class Sensor {
public:
  explicit Sensor(const std::string &sensorId);
  virtual ~Sensor();
  virtual double read() = 0;        // pure virtual
  std::string getId() const;
  double getLastReading() const;
protected:
  void setLastReading(double v);
};
Concepts: constructors & destructors, access specifiers, virtual methods, =0 abstract base class, encapsulation via protected setter.

Implement concrete sensor subclasses

Files:

src/TemperatureSensor.cpp & .hpp

src/DistanceSensor.cpp & .hpp

src/PressureSensor.cpp & .hpp

Behavior:

Each overrides double read() to simulate a value (e.g., random in a range).

Calls setLastReading(...) internally.

Concepts: inheritance, override keyword, std::mt19937 or std::random_device, including <random>.

Test your classes with a simple driver

File: src/test_sensors.cpp

In main():

Instantiate one of each sensor:


std::unique_ptr<Sensor> t = std::make_unique<TemperatureSensor>("T1");
std::unique_ptr<Sensor> d = std::make_unique<DistanceSensor>("D1");
Call read() three times on each, printing getId() and getLastReading().

Concepts: smart pointers, dynamic polymorphism, loops.

Ensure clean memory management

Confirm destructors are virtual.

Use std::unique_ptr<Sensor> to hold polymorphic objects.

Encapsulation & const-correctness

Mark getters const.

Keep lastReading and id private or protected.

Avoid exposing internal state via non-const methods.

🧠 Concepts You’ll Master

Concept	Details
Constructors/Destructors	explicit single-arg, default dtor, virtual dtor
Inheritance	class Derived : public Sensor
Polymorphism	virtual double read() override
Encapsulation	private vs protected vs public
Smart Pointers	std::unique_ptr<Sensor> for ownership
Const-Correctness	getId() const, getLastReading() const
Random Number Generation	<random> engines and distributions
✅ Deliverable
By the end of Week 2 you should have:

Header files (include/Sensor.hpp, include/TemperatureSensor.hpp, etc.) with well-documented class definitions.

Source files implementing each class.

A test driver (test_sensors.cpp) that instantiates each sensor, calls read(), and prints results.

A CMakeLists.txt entry to build a sensor_test executable alongside your calculator.


---

### **Week 3 – STL, Smart Pointers, RAII**
**Topics**: `std::vector`, `std::map`, `unique_ptr`, RAII, `optional`  
**Project**: `Sensor Manager`
- Class `SensorManager` manages list of sensors
- Add/remove/list sensors
- Features:
  - Use `unique_ptr<Sensor>`
  - Access by ID (via map)
  - Optional return on missing sensor

---

### **Week 4 – File I/O & JSON**
**Topics**: File streams, JSON, serialization  
**Project**: `Sensor Config Loader`
- Load sensor definitions from JSON file
- Save readings to file
- Features:
  - Use `nlohmann::json`
  - Serialize/deserialize sensors
  - Error-tolerant file reading

---

## 🤖 **Phase 2: Embedded & Robotics Foundations (Weeks 5–8)**

### **Week 5 – Threads and Timing**
**Topics**: `std::thread`, `chrono`, mutexes  
**Project**: `Sensor Poller`
- Launch a thread per sensor
- Poll every N ms
- Features:
  - Thread-safe read
  - Graceful shutdown with `atomic<bool>`

---

### **Week 6 – Finite State Machines**
**Topics**: Enums, switch-case FSM, object-oriented FSM  
**Project**: `Robot State Controller`
- States: `IDLE`, `MOVING`, `OBSTACLE_DETECTED`, `STOPPED`
- Inputs: Sensor changes
- Features:
  - Transition logic
  - Logging state changes

---

### **Week 7 – Command/Observer Pattern**
**Topics**: Design patterns in C++  
**Project**: `Command Queue for Actuators`
- Commands: `MoveForward`, `TurnLeft`, `Stop`
- Queue and execute commands
- Features:
  - Observer for event notification
  - Strategy pattern for execution

---

### **Week 8 – Serial Communication (Mocked)**
**Topics**: Byte parsing, protocol simulation  
**Project**: `Serial Decoder`
- Decode command streams (e.g., `0xAA 0x01 0x05 0xBB`)
- Map to actuator actions
- Features:
  - Byte-level parsing
  - Checksum validation
  - Error response on bad frame

---

## ⚙️ **Phase 3: Real Robotics (Weeks 9–12)**

### **Week 9 – ROS2 Integration**
**Topics**: ROS2, `rclcpp`, messages  
**Project**: `ROS2 Distance Publisher`
- Publish fake distance data at 10Hz
- Features:
  - ROS2 timer
  - Custom `DistanceSensor` class

---

### **Week 10 – Motion Control with PID**
**Topics**: PID controller, control loop timing  
**Project**: `PID Motor Controller`
- Simulate target speed following
- Features:
  - Class with tunable P, I, D
  - Plot output over time

---

### **Week 11 – Computer Vision with OpenCV**
**Topics**: Image loading, processing, line detection  
**Project**: `Line Follower`
- Load or stream camera input
- Detect central line
- Features:
  - Binary threshold
  - Draw ROI
  - Print line direction offset

---

### **Week 12 – Final Integration**
**Topics**: Combine all learned components  
**Project**: `Robot Brain Simulator`
- Simulated sensor input → FSM → Commands → PID
- Features:
  - Configurable via JSON
  - ROS2-compatible
  - Log all inputs/actions/states to file

---

## 🧰 Tools You Will Use

- **Compiler**: `clang++` / `g++` with C++17
- **Build System**: `CMake`
- **Libraries**: STL, `nlohmann::json`, `OpenCV`, `rclcpp`, `fmt`
- **IDE**: VS Code + C++ Extension
- **Debugging**: `valgrind`, AddressSanitizer

---

## ✅ Tips for Success

- Write clean, modular, testable code
- Use CMake from day one
- Comment WHY, not just WHAT
- Try to avoid raw pointers
- Ask "How would I unit test this?" after each week

---

