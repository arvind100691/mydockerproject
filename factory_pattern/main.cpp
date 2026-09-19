#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

enum class SensorType
{
    Temperature,
    Pressure,
    Humidity,
    Light,
    Motion
};

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual void read() const = 0;
};

class TemperatureSensor : public Sensor
{
public:
    void read() const override
    {
        std::cout << "Reading temperature from sensor" << std::endl;
    }
};

class PressureSensor : public Sensor
{
public:
    void read() const override
    {
        std::cout << "Reading pressure from sensor" << std::endl;
    }
};

class HumiditySensor : public Sensor
{
public:
    void read() const override
    {
        std::cout << "Reading humidity from sensor" << std::endl;
    }
};

class LightSensor : public Sensor
{
public:
    void read() const override
    {
        std::cout << "Reading light level from sensor" << std::endl;
    }
};

class MotionSensor : public Sensor
{
public:
    void read() const override
    {
        std::cout << "Reading motion from sensor" << std::endl;
    }
};

class SensorFactory
{
public:
    static std::unique_ptr<Sensor> create(SensorType type)
    {
        switch (type)
        {
            case SensorType::Temperature:
                return std::make_unique<TemperatureSensor>();
            case SensorType::Pressure:
                return std::make_unique<PressureSensor>();
            case SensorType::Humidity:
                return std::make_unique<HumiditySensor>();
            case SensorType::Light:
                return std::make_unique<LightSensor>();
            case SensorType::Motion:
                return std::make_unique<MotionSensor>();
            default:
                throw std::invalid_argument("Unsupported sensor type");
        }
    }
};

int main()
{
    std::cout << "Factory Pattern Example" << std::endl;

    auto temperatureSensor = SensorFactory::create(SensorType::Temperature);
    auto pressureSensor = SensorFactory::create(SensorType::Pressure);
    auto motionSensor = SensorFactory::create(SensorType::Motion);

    temperatureSensor->read();
    pressureSensor->read();
    motionSensor->read();
}   

