#include <iostream>
#include <iomanip>
#include <sstream>
#include "observer.h"

using namespace observer_pattern;

/**
 * @brief Display class that observes a sensor
 * 
 * Implements the Observer interface to receive updates from a Sensor
 */
class Display : public Observer {
private:
    std::string name;

public:
    Display(const std::string& displayName) : name(displayName) {}

    /**
     * @brief Called when sensor data changes
     * @param data Sensor data as string
     */
    void update(const std::string& data = "") override {
        std::cout << "[" << name << "] Received update: " << data << std::endl;
    }
};

/**
 * @brief Sensor class that measures temperature
 * 
 * Inherits from Subject to notify all observers when temperature changes
 */
class TemperatureSensor : public Subject {
private:
    double temperature;
    std::string sensorName;

public:
    TemperatureSensor(const std::string& name) 
        : temperature(0.0), sensorName(name) {}

    /**
     * @brief Set the temperature and notify all observers
     * @param temp The new temperature value
     */
    void set_temperature(double temp) {
        temperature = temp;
        
        // Create the update message
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        oss << sensorName << " temperature: " << temperature << "°C";
        
        // Notify all observers
        notify_observers(oss.str());
    }

    /**
     * @brief Get the current temperature
     * @return Current temperature value
     */
    double get_temperature() const {
        return temperature;
    }
};

int main() {
    std::cout << "=== Observer Pattern Example: Sensor and Display ===" << std::endl << std::endl;

    // Create a temperature sensor
    auto sensor = std::make_shared<TemperatureSensor>("Room Sensor");

    // Create multiple display observers
    auto display1 = std::make_shared<Display>("LCD Display 1");
    auto display2 = std::make_shared<Display>("Digital Display 2");
    auto display3 = std::make_shared<Display>("Console Display 3");

    // Attach observers to the sensor
    sensor->attach(display1);
    sensor->attach(display2);
    sensor->attach(display3);

    std::cout << "Number of observers: " << sensor->observer_count() << std::endl << std::endl;

    // Update sensor temperature - all displays will be notified
    std::cout << "--- Updating sensor to 22.5°C ---" << std::endl;
    sensor->set_temperature(22.5);
    std::cout << std::endl;

    std::cout << "--- Updating sensor to 25.0°C ---" << std::endl;
    sensor->set_temperature(25.0);
    std::cout << std::endl;

    // Detach one observer
    std::cout << "--- Detaching Display 2 ---" << std::endl;
    sensor->detach(display2);
    std::cout << "Number of observers: " << sensor->observer_count() << std::endl << std::endl;

    std::cout << "--- Updating sensor to 20.3°C ---" << std::endl;
    sensor->set_temperature(20.3);
    std::cout << std::endl;

    std::cout << "=== End of Example ===" << std::endl;
    return 0;
}