#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono> // For timing

using namespace std;
using namespace chrono;

// Recursive Binary Search Function
int recursiveBinarySearch(const vector<int>& vec, int target, int low, int high) {
    if (low > high) {
        return -1; // target not found
    }
    int mid = low + (high - low) / 2;
    if (vec[mid] == target) {
        return mid; // target found
    } else if (vec[mid] > target) {
        return recursiveBinarySearch(vec, target, low, mid - 1);
    } else {
        return recursiveBinarySearch(vec, target, mid + 1, high);
    }
}

// Iterative Binary Search Function
int iterativeBinarySearch(const vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] == target) {
            return mid; // target found
        } else if (vec[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; // target not found
}

// Sequential Search Function
int sequentialSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i; // target found
        }
    }
    return -1; // target not found
}

int main() {
    // Sizes of the vector for testing
    vector<int> sizes = {5000, 50000, 100000, 150000, 1000000};

    // Random number generator setup
    random_device rd; // Random device to seed the generator
    mt19937 gen(rd()); // Mersenne Twister random number generator
    uniform_int_distribution<> dis(1, 100); // Distribution to generate numbers between 1 and 100

    // Loop through the different sizes of N
    for (int N : sizes) {
        double SumRBS = 0, SumIBS = 0, SumSeqS = 0;

        // Run the test 10 times for each N
        for (int i = 0; i < 10; ++i) {
            // Fill vector with N random numbers
            vector<int> data(N);
            for (int j = 0; j < N; ++j) {
                data[j] = dis(gen);
            }

            // Generate a random target value
            int target = dis(gen);

            // Sort the vector for binary search to work
            sort(data.begin(), data.end());

            // Timing and running Recursive Binary Search
            auto start = high_resolution_clock::now();
            recursiveBinarySearch(data, target, 0, N - 1);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            SumRBS += duration.count();

            // Timing and running Iterative Binary Search
            start = high_resolution_clock::now();
            iterativeBinarySearch(data, target);
            end = high_resolution_clock::now();
            duration = duration_cast<microseconds>(end - start);
            SumIBS += duration.count();

            // Timing and running Sequential Search
            start = high_resolution_clock::now();
            sequentialSearch(data, target);
            end = high_resolution_clock::now();
            duration = duration_cast<microseconds>(end - start);
            SumSeqS += duration.count();
        }

        // Output average running times for each search algorithm
        cout << "For N = " << N << ":\n";
        cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << endl;
        cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << endl;
        cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << endl;
        cout << "----------------------------------------\n";
    }

    return 0;
}
