#include <iostream>
#include <vector>
#include <algorithm>
#include <random> // For random number generation

using namespace std;

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
    // Size of the vector
    const int SIZE = 10; // Modify the size of the vector here if needed

    // Random number generator setup
    random_device rd; // Random device to seed the generator
    mt19937 gen(rd()); // Mersenne Twister random number generator
    uniform_int_distribution<> dis(1, 100); // Distribution to generate numbers between 1 and 100

    // Fill vector with random numbers between 1 and 100
    vector<int> data(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        data[i] = dis(gen);
    }

    // Randomly generate a target between 1 and 100
    int target = dis(gen);

    // Sorting the vector
    sort(data.begin(), data.end());

    // Output the sorted vector
    cout << "Sorted vector: ";
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "\nRandom target: " << target << endl;

    // Recursive Binary Search
    cout << "\nRecursive Binary Search:" << endl;
    int index = recursiveBinarySearch(data, target, 0, data.size() - 1);
    if (index != -1) {
        cout << target << " found at location " << index << endl;
    } else {
        cout << target << " was not found" << endl;
    }

    // Iterative Binary Search
    cout << "\nIterative Binary Search:" << endl;
    index = iterativeBinarySearch(data, target);
    if (index != -1) {
        cout << target << " found at location " << index << endl;
    } else {
        cout << target << " was not found" << endl;
    }

    // Sequential Search
    cout << "\nSequential Search:" << endl;
    index = sequentialSearch(data, target);
    if (index != -1) {
        cout << target << " found at location " << index << endl;
    } else {
        cout << target << " was not found" << endl;
    }

    return 0;
}

