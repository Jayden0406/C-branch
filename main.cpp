#include <iostream>
using namespace std;

class counterType {
private:
    int counter;  // Private data member to store the counter value

public:
    // Constructor to initialize the counter to 0
    counterType() {
        counter = 0;
    }

    // Function to set the counter to a specified value
    void setCounter(int newValue) {
        if (newValue >= 0) {  // Ensure the counter is non-negative
            counter = newValue;
        } else {
            cout << "Error: Counter value must be non-negative!" << endl;
            counter = 0;  // Reset to 0 if a negative value is given
        }
    }

    // Function to initialize the counter to 0
    void initializeCounter() {
        counter = 0;
    }

    // Function to retrieve the current value of counter
    int getCounter() const {
        return counter;
    }

    // Function to increment the counter by 1
    void incrementCounter() {
        counter++;
    }

    // Function to decrement the counter by 1 (ensure non-negative counter)
    void decrementCounter() {
        if (counter > 0) {
            counter--;
        } else {
            cout << "Error: Counter cannot be negative!" << endl;
        }
    }
};

int main() {
    // Create an object of counterType
    counterType counter;

    // Display the initial counter value
    cout << "Initial counter value: " << counter.getCounter() << endl;

    // Set the counter to a specific value
    counter.setCounter(10);
    cout << "After setting counter to 10: " << counter.getCounter() << endl;

    // Increment the counter
    counter.incrementCounter();
    cout << "After incrementing: " << counter.getCounter() << endl;

    // Decrement the counter
    counter.decrementCounter();
    cout << "After decrementing: " << counter.getCounter() << endl;

    // Try to set a negative counter value (error case)
    counter.setCounter(-5);  // This will set the counter to 0 due to validation
    cout << "After trying to set counter to -5: " << counter.getCounter() << endl;

    // Reset the counter to 0
    counter.initializeCounter();
    cout << "After initializing the counter: " << counter.getCounter() << endl;

    return 0;
}
