#include <iostream>
#include <stdexcept>
#include <string>
#include <array>

class DayType {
private:
    // List of days in the week for indexing
    static const std::array<std::string, 7> days_of_week;

    std::string day;  // The current day of the week

public:
    // Constructor to initialize the day
    DayType(const std::string& initial_day = "Sun") {
        if (isValidDay(initial_day)) {
            day = initial_day;
        } else {
            throw std::invalid_argument("Invalid day: " + initial_day);
        }
    }

    // Function to set the day
    void setDay(const std::string& new_day) {
        if (isValidDay(new_day)) {
            day = new_day;
        } else {
            throw std::invalid_argument("Invalid day: " + new_day);
        }
    }

    // Function to get the current day
    std::string getDay() const {
        return day;
    }

    // Function to print the current day
    void printDay() const {
        std::cout << day << std::endl;
    }

    // Function to return the next day
    std::string nextDay() const {
        int current_index = getDayIndex();
        int next_index = (current_index + 1) % 7;
        return days_of_week[next_index];
    }

    // Function to return the previous day
    std::string previousDay() const {
        int current_index = getDayIndex();
        int prev_index = (current_index - 1 + 7) % 7; // Wrap around to previous day
        return days_of_week[prev_index];
    }

    // Function to add n days to the current day
    std::string addDays(int n) const {
        int current_index = getDayIndex();
        int new_index = (current_index + n) % 7;
        return days_of_week[new_index];
    }

private:
    // Helper function to check if a day is valid
    bool isValidDay(const std::string& day) const {
        for (const auto& valid_day : days_of_week) {
            if (day == valid_day) {
                return true;
            }
        }
        return false;
    }

    // Helper function to get the index of the current day
    int getDayIndex() const {
        for (int i = 0; i < 7; ++i) {
            if (day == days_of_week[i]) {
                return i;
            }
        }
        return -1;  // This should never happen if the day is valid
    }
};

// Initialize the static array of days in the week
const std::array<std::string, 7> DayType::days_of_week = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int main() {
    try {
        // Create a DayType object with initial day "Mon"
        DayType today("Mon");

        // Print the current day
        std::cout << "Current day: ";
        today.printDay();

        // Set a new day and print it
        today.setDay("Wed");
        std::cout << "After setting new day: ";
        today.printDay();

        // Print next and previous day
        std::cout << "Next day: " << today.nextDay() << std::endl;
        std::cout << "Previous day: " << today.previousDay() << std::endl;

        // Add days and print the resulting day
        std::cout << "Adding 4 days: " << today.addDays(4) << std::endl;  // Expected: Sun
        std::cout << "Adding 13 days: " << today.addDays(13) << std::endl;  // Expected: Wed

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
