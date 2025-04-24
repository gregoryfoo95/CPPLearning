#pragma once
#include <string>

class Sensor {
    public:
        explicit Sensor(std::string id);
        virtual ~Sensor() = default;

        virtual double read() = 0;

        const std::string& getId() const noexcept;
        double getLastReading() const noexcept;
    
    protected:
        void setLastReading(double reading) noexcept;
    
    private:
        std::string id_;
        double lastReading_{0.0};
};