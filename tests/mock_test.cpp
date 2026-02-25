#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "observer.h"

using namespace observer_pattern;
using ::testing::AtLeast;
using ::testing::Eq;

/**
 * @brief Mock observer for testing
 * 
 * This demonstrates how to create a mock class to verify
 * that the subject-observer interaction works correctly
 */
class MockObserver : public Observer {
public:
    MOCK_METHOD(void, update, (const std::string& data), (override));
};

/**
 * @brief Test subject to expose protected notify_observers for testing
 * 
 * Inherits from Subject and provides a public interface to test
 * the notification mechanism
 */
class TestSubject : public Subject {
public:
    // Expose protected notify_observers as public for testing
    void test_notify(const std::string& data = "") {
        notify_observers(data);
    }
};

/**
 * @brief Test suite for the observer pattern using mocks
 */
class ObserverPatternTest : public ::testing::Test {
protected:
    std::shared_ptr<TestSubject> subject;
    std::shared_ptr<MockObserver> mock_observer1;
    std::shared_ptr<MockObserver> mock_observer2;

    void SetUp() override {
        subject = std::make_shared<TestSubject>();
        mock_observer1 = std::make_shared<MockObserver>();
        mock_observer2 = std::make_shared<MockObserver>();
    }
};

/**
 * @brief Test that notify_observers calls update on all attached observers
 */
TEST_F(ObserverPatternTest, NotifyCallsUpdateOnAllObservers) {
    // Expectations: Both observers should receive the update call
    EXPECT_CALL(*mock_observer1, update(Eq("test message")))
        .Times(1);
    EXPECT_CALL(*mock_observer2, update(Eq("test message")))
        .Times(1);

    // Attach both observers
    subject->attach(mock_observer1);
    subject->attach(mock_observer2);

    // Trigger notification
    subject->test_notify("test message");
}

/**
 * @brief Test that detached observers are not notified
 */
TEST_F(ObserverPatternTest, DetachedObserverNotNotified) {
    // Expectation: mock_observer1 should NOT be called
    EXPECT_CALL(*mock_observer1, update(testing::_))
        .Times(0);
    EXPECT_CALL(*mock_observer2, update(Eq("message")))
        .Times(1);

    subject->attach(mock_observer1);
    subject->attach(mock_observer2);

    // Detach first observer
    subject->detach(mock_observer1);

    // Trigger notification
    subject->test_notify("message");
}

/**
 * @brief Test that observer count is accurate
 */
TEST_F(ObserverPatternTest, ObserverCountAccurate) {
    EXPECT_EQ(subject->observer_count(), 0);

    subject->attach(mock_observer1);
    EXPECT_EQ(subject->observer_count(), 1);

    subject->attach(mock_observer2);
    EXPECT_EQ(subject->observer_count(), 2);

    subject->detach(mock_observer1);
    EXPECT_EQ(subject->observer_count(), 1);

    subject->detach_all();
    EXPECT_EQ(subject->observer_count(), 0);
}

/**
 * @brief Test that duplicate observers are not added
 */
TEST_F(ObserverPatternTest, DuplicateObserversNotAdded) {
    EXPECT_CALL(*mock_observer1, update(testing::_))
        .Times(1); // Should be called exactly once

    subject->attach(mock_observer1);
    subject->attach(mock_observer1); // Try to attach the same observer again

    EXPECT_EQ(subject->observer_count(), 1); // Should still be 1

    subject->test_notify("test");
}

/**
 * @brief Test with multiple notifications
 */
TEST_F(ObserverPatternTest, MultipleNotifications) {
    // Expect three calls with different messages
    EXPECT_CALL(*mock_observer1, update(Eq("first")))
        .Times(1);
    EXPECT_CALL(*mock_observer1, update(Eq("second")))
        .Times(1);
    EXPECT_CALL(*mock_observer1, update(Eq("third")))
        .Times(1);

    subject->attach(mock_observer1);

    subject->test_notify("first");
    subject->test_notify("second");
    subject->test_notify("third");
}

/**
 * @brief Test that empty notification message works
 */
TEST_F(ObserverPatternTest, EmptyNotificationMessage) {
    EXPECT_CALL(*mock_observer1, update(Eq("")))
        .Times(1);

    subject->attach(mock_observer1);
    subject->test_notify(); // No argument = empty string
}
