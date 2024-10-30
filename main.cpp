#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Global Constants for Array Dimensions
const int NUM_RUNNERS = 5;
const int DAYS_IN_WEEK = 7;

// Function Prototypes
void readRunnerData(string runners[], int miles[][DAYS_IN_WEEK]);
void calculateMiles(int miles[][DAYS_IN_WEEK], int totalMiles[], double averageMiles[]);
void displayResults(string runners[], int miles[][DAYS_IN_WEEK], int totalMiles[], double averageMiles[]);

int main() {
    // Declare Arrays
    string runners[NUM_RUNNERS];
    int miles[NUM_RUNNERS][DAYS_IN_WEEK];
    int totalMiles[NUM_RUNNERS];
    double averageMiles[NUM_RUNNERS];

    // Read Runner Data
    readRunnerData(runners, miles);

    // Calculate Total and Average Miles
    calculateMiles(miles, totalMiles, averageMiles);

    // Display Results
    displayResults(runners, miles, totalMiles, averageMiles);

    return 0;
}

// Function to Read Runner Data
void readRunnerData(string runners[], int miles[][DAYS_IN_WEEK]) {
    ifstream inputFile("marathon_data.txt"); // Replace with your input file name
    if (inputFile.is_open()) {
        for (int i = 0; i < NUM_RUNNERS; i++) {
            inputFile >> runners[i];
            for (int j = 0; j < DAYS_IN_WEEK; j++) {
                inputFile >> miles[i][j];
            }
        }
        inputFile.close();
    } else {
        cout << "Error opening input file." << endl;
    }
}

// Function to Calculate Total and Average Miles
void calculateMiles(int miles[][DAYS_IN_WEEK], int totalMiles[], double averageMiles[]) {
    for (int i = 0; i < NUM_RUNNERS; i++) {
        totalMiles[i] = 0;
        for (int j = 0; j < DAYS_IN_WEEK; j++) {
            totalMiles[i] += miles[i][j];
        }
        averageMiles[i] = static_cast<double>(totalMiles[i]) / DAYS_IN_WEEK;
    }
}

// Function to Display Results
void displayResults(string runners[], int miles[][DAYS_IN_WEEK], int totalMiles[], double averageMiles[]) {
    cout << setw(15) << "Runner" << setw(10) << "Day 1" << setw(10) << "Day 2" << setw(10) << "Day 3" << setw(10) << "Day 4" << setw(10) << "Day 5" << setw(10) << "Day 6" << setw(10) << "Day 7" << setw(15) << "Total" << setw(15) << "Average" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < NUM_RUNNERS; i++) {
        cout << setw(15) << runners[i];
        for (int j = 0; j < DAYS_IN_WEEK; j++) {
            cout << setw(10) << miles[i][j];
        }
        cout << setw(15) << totalMiles[i] << setw(15) << fixed << setprecision(2) << averageMiles[i] << endl;
    }
}
