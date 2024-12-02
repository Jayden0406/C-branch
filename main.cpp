#include <string>
#include <iostream>
using namespace std;

class ParkedCar {
private:
    string make;
    string model;
    string color;
    string licenseNumber;
    int minutesParked;

public:
    // Default constructor
    ParkedCar(string mk = "MAKE", string ml = "MODEL", string co = "COLOR", 
              string ln = "LICENSE", int mn = 0)
        : make(mk), model(ml), color(co), licenseNumber(ln), minutesParked(mn) {}

    // Getter methods
    string getMake() const { return make; }
    string getModel() const { return model; }
    string getColor() const { return color; }
    string getLicenseNumber() const { return licenseNumber; }
    int getMinutesParked() const { return minutesParked; }
};
class ParkingMeter {
private:
    int minutesPurchased;

public:
    // Default constructor
    ParkingMeter(int mn = 0) : minutesPurchased(mn) {}

    // Getter method
    int getMinutesPurchased() const { return minutesPurchased; }
};
class ParkingTicket {
private:
    ParkedCar car;
    ParkingMeter meter;
    string officerName;
    string badgeNumber;
    double fine;

public:
    // Constructor
    ParkingTicket(ParkedCar c, ParkingMeter m, string officer, string badge)
        : car(c), meter(m), officerName(officer), badgeNumber(badge), fine(0.0) {
        calculateFine();
    }

    // Method to calculate the fine
    void calculateFine() {
        int extraMinutes = car.getMinutesParked() - meter.getMinutesPurchased();
        if (extraMinutes > 0) {
            fine = 25.0; // First hour or part of it
            extraMinutes -= 60;
            if (extraMinutes > 0) {
                fine += (extraMinutes / 60 + 1) * 10; // Additional hours
            }
        }
    }

    // Method to display the ticket
    void displayTicket() const {
        cout << "*** Parking Ticket ***\n";
        cout << "Officer: " << officerName << " Badge Number: " << badgeNumber << "\n";
        cout << "Vehicle License Number: " << car.getLicenseNumber() << "\n";
        cout << "Make: " << car.getMake() << " Model: " << car.getModel() << " Color: " << car.getColor() << "\n";
        cout << "Meter Minutes: " << meter.getMinutesPurchased() << " Minutes Parked: " << car.getMinutesParked() << "\n";
        cout << "Parking Fee: $" << fine << "\n";
    }

    // Getter method for fine
    double getFine() const { return fine; }
};
class PoliceOfficer {
private:
    string name;
    string badgeNumber;

public:
    // Constructor
    PoliceOfficer(string n = "Officer", string bn = "Badge Number")
        : name(n), badgeNumber(bn) {}

    // Method to issue a ticket if needed
    ParkingTicket issueTicket(ParkedCar car, ParkingMeter meter) {
        return ParkingTicket(car, meter, name, badgeNumber);
    }
};
int main() {
    // Create a police officer
    PoliceOfficer officer("Mark Smith", "B123456");

    // Test cases
    ParkedCar car1("Hyundai", "Sonata", "silver", "A12345", 120);
    ParkingMeter meter1(60);
    if (car1.getMinutesParked() > meter1.getMinutesPurchased()) {
        ParkingTicket ticket1 = officer.issueTicket(car1, meter1);
        ticket1.displayTicket();
    } else {
        cout << "No parking violation.\n";
    }

    ParkedCar car2("Toyota", "Corolla", "blue", "B23456", 65);
    ParkingMeter meter2(60);
    if (car2.getMinutesParked() > meter2.getMinutesPurchased()) {
        ParkingTicket ticket2 = officer.issueTicket(car2, meter2);
        ticket2.displayTicket();
    } else {
        cout << "No parking violation.\n";
    }

    ParkedCar car3("Honda", "Civic", "red", "C34567", 150);
    ParkingMeter meter3(60);
    if (car3.getMinutesParked() > meter3.getMinutesPurchased()) {
        ParkingTicket ticket3 = officer.issueTicket(car3, meter3);
        ticket3.displayTicket();
    } else {
        cout << "No parking violation.\n";
    }

    // Additional test cases can be added here similarly

    return 0;
}
