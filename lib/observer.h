#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H

#include <vector>
#include <memory>
#include <algorithm>

namespace observer_pattern {

/**
 * @brief Observer interface for the observer pattern
 * 
 * Classes that want to observe state changes should inherit from this class
 * and implement the update() method.
 */
class Observer {
public:
    virtual ~Observer() = default;
    
    /**
     * @brief Called when the subject's state changes
     * @param data Optional data about the update
     */
    virtual void update(const std::string& data = "") = 0;
};

/**
 * @brief Subject class that manages observers
 * 
 * Classes that need to notify observers should inherit from this class
 * and call notify_observers() when their state changes.
 */
class Subject {
public:
    virtual ~Subject() = default;
    
    /**
     * @brief Attach an observer to this subject
     * @param observer Shared pointer to the observer to attach
     */
    void attach(std::shared_ptr<Observer> observer) {
        if (observer && std::find(observers.begin(), observers.end(), observer) == observers.end()) {
            observers.push_back(observer);
        }
    }
    
    /**
     * @brief Detach an observer from this subject
     * @param observer Shared pointer to the observer to detach
     */
    void detach(std::shared_ptr<Observer> observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
    
    /**
     * @brief Detach all observers from this subject
     */
    void detach_all() {
        observers.clear();
    }
    
    /**
     * @brief Get the number of observers
     * @return Number of attached observers
     */
    size_t observer_count() const {
        return observers.size();
    }
    
protected:
    /**
     * @brief Notify all observers of a state change
     * @param data Optional data to pass to observers
     */
    void notify_observers(const std::string& data = "") {
        for (auto& observer : observers) {
            if (observer) {
                observer->update(data);
            }
        }
    }
    
private:
    std::vector<std::shared_ptr<Observer>> observers;
};

} // namespace observer_pattern

#endif // OBSERVER_PATTERN_H
