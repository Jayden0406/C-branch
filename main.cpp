#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Define a struct to represent a runner's data
struct Runner {
    string name;
    int miles[7]; // Array to store miles run each day
    int totalMiles;
    double averageMiles;
};

// Function to read runner data from a file
void readRunnerData(Runner runners[], int numRunners) {
    ifstream inputFile("marathon_data.txt"); // Replace with your input file name
    if (inputFile.is_open()) {
        for (int i = 0; i < numRunners; i++) {
            inputFile >> runners[i].name;
            for (int j = 0; j < 7; j++) {
                inputFile >> runners[i].miles[j];
            }
        }
        inputFile.close();
    } else {
        cout << "Error opening input file." << endl;
    }
}

// Function to calculate total and average miles for each runner
void calculateMiles(Runner runners[], int numRunners) {
    for (int i = 0; i < numRunners; i++) {
        runners[i].totalMiles = 0;
        for (int j = 0; j < 7; j++) {
            runners[i].totalMiles += runners[i].miles[j];
        }
        runners[i].averageMiles = static_cast<double>(runners[i].totalMiles) / 7;
    }
}

// Function to display results in a formatted table
void displayResults(Runner runners[], int numRunners) {
    cout << setw(15) << "Runner" << setw(10) << "Day 1" << setw(10) << "Day 2" << setw(10) << "Day 3" << setw(10) << "Day 4" << setw(10) << "Day 5" << setw(10) << "Day 6" << setw(10) << "Day 7" << setw(15) << "Total" << setw(15) << "Average" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < numRunners; i++) {
        cout << setw(15) << runners[i].name;
        for (int j = 0; j < 7; j++) {
            cout << setw(10) << runners[i].miles[j];
        }
        cout << setw(15) << runners[i].totalMiles << setw(15) << fixed << setprecision(2) << runners[i].averageMiles << endl;
    }
}

int main() {
    const int NUM_RUNNERS = 5;
    Runner runners[NUM_RUNNERS]; 

    // Read runner data from the file
    readRunnerData(runners, NUM_RUNNERS);

    // Calculate total and average miles
    calculateMiles(runners, NUM_RUNNERS);

    // Display the results in a formatted table
    displayResults(runners, NUM_RUNNERS);

    return 0;
}
