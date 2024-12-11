#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

    // Helper functions
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    int daysInMonth(int m, int y) const {
        switch (m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(y) ? 29 : 28;
            default: return 0; // Invalid month
        }
    }

    bool isValidDate(int m, int d, int y) const {
        return m >= 1 && m <= 12 && d >= 1 && d <= daysInMonth(m, y);
    }

public:
    // Default constructor
    Date(int m = 1, int d = 1, int y = 1930) : month(m), day(d), year(y) {
        if (!isValidDate(m, d, y)) {
            throw invalid_argument("Invalid date.");
        }
    }

    // Print Date in different formats
    void print1() const {
        cout << month << "/" << day << "/" << year << endl;
    }

    void print2() const {
        static const string months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cout << months[month] << " " << day << ", " << year << endl;
    }

    void print3() const {
        static const string months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cout << day << " " << months[month] << " " << year << endl;
    }

    // Setter function
    void setDate(int m, int d, int y) {
        if (!isValidDate(m, d, y)) {
            throw invalid_argument("Invalid date.");
        }
        month = m;
        day = d;
        year = y;
    }

    // Getter functions
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Overloaded operators
    // Prefix increment operator (++)
    Date& operator++() {
        if (day < daysInMonth(month, year)) {
            ++day;
        } else if (month == 12) {
            day = 1;
            month = 1;
            ++year;
        } else {
            day = 1;
            ++month;
        }
        return *this;
    }

    // Postfix increment operator (++)
    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix decrement operator (--)
    Date& operator--() {
        if (day > 1) {
            --day;
        } else if (month == 1) {
            day = 31;
            month = 12;
            --year;
        } else {
            --month;
            day = daysInMonth(month, year);
        }
        return *this;
    }

    // Postfix decrement operator (--)
    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    // Subtraction operator (-) to calculate the number of days between two dates
    int operator-(const Date& other) const {
        int totalDays = 0;
        Date temp = other;
        while (temp.getYear() != year || temp.getMonth() != month || temp.getDay() != day) {
            ++totalDays;
            ++temp;
        }
        return totalDays;
    }

    // Stream insertion operator (<<) for output
    friend ostream& operator<<(ostream& out, const Date& date) {
        static const string months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        out << months[date.month] << " " << date.day << ", " << date.year;
        return out;
    }

    // Stream extraction operator (>>) for input
    friend istream& operator>>(istream& in, Date& date) {
        int m, d, y;
        cout << "Enter date (month/day/year): ";
        char slash1, slash2;
        in >> m >> slash1 >> d >> slash2 >> y;
        if (!date.isValidDate(m, d, y)) {
            throw invalid_argument("Invalid date.");
        }
        date.setDate(m, d, y);
        return in;
    }
};

int main() {
    try {
        Date d1(12, 25, 2021);  // Valid date
        Date d2;                 // Default date (1/1/1930)

        cout << "Date 1 in format 1: ";
        d1.print1();
        cout << "Date 1 in format 2: ";
        d1.print2();
        cout << "Date 1 in format 3: ";
        d1.print3();

        cout << "\nDate 2 in format 2: ";
        d2.print2();

        // Test operator overloading
        Date d3 = d1;
        d3++;  // Increment date
        cout << "\nDate 3 after postfix increment: ";
        d3.print2();

        --d3;  // Decrement date
        cout << "Date 3 after prefix decrement: ";
        d3.print2();

        cout << "\nDays between d1 and d3: " << d1 - d3 << " days\n";

        // Test user input
        Date d4;
        cin >> d4;  // User input for date
        cout << "User input date: " << d4 << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
