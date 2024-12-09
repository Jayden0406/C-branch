#include <iostream>
#include <string>

class Employee {
private:
    std::string name;            // Employee's name
    int employeeNumber;          // Employee's ID number
    std::string hireDate;        // Hire date in "MM/DD/YYYY" format

public:
    // Default constructor
    Employee() : name(""), employeeNumber(0), hireDate("") {}

    // Parameterized constructor
    Employee(std::string empName, int empNumber, std::string empHireDate)
        : name(empName), employeeNumber(empNumber), hireDate(empHireDate) {}

    // Accessor functions (Getters)
    // Precondition: None
    // Postcondition: Returns the name of the employee
    std::string getName() const {
        return name;
    }

    // Precondition: None
    // Postcondition: Returns the employee number (ID)
    int getEmployeeNumber() const {
        return employeeNumber;
    }

    // Precondition: None
    // Postcondition: Returns the hire date of the employee
    std::string getHireDate() const {
        return hireDate;
    }

    // Mutator functions (Setters)
    // Precondition: newName is a valid string
    // Postcondition: The employee's name is updated
    void setName(const std::string& newName) {
        name = newName;
    }

    // Precondition: newNumber is a valid integer
    // Postcondition: The employee number is updated
    void setEmployeeNumber(int newNumber) {
        employeeNumber = newNumber;
    }

    // Precondition: newHireDate is a valid string (e.g., "MM/DD/YYYY")
    // Postcondition: The hire date is updated
    void setHireDate(const std::string& newHireDate) {
        hireDate = newHireDate;
    }

    // Print function to display the employee's information
    // Precondition: None
    // Postcondition: Displays the employee's details in a readable format
    void print() const {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee ID: " << employeeNumber << std::endl;
        std::cout << "Hire Date: " << hireDate << std::endl;
    }
};
int main() {
    // Create an employee using the parameterized constructor
    Employee emp1("Lukas Knight", 23482, "04/06/2023");

    // Print the employee details
    emp1.print();

    // Modify the employee details using mutators
    emp1.setName("Hanif soul");
    emp1.setEmployeeNumber(67890);
    emp1.setHireDate("03/22/2022");

    // Print the updated details
    emp1.print();

    return 0;
}
