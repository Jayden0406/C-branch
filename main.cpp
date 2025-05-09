#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& arr, int target, int low, int high) {
    if (low > high) return -1; // target not found

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return recursiveBinarySearch(arr, target, low, mid - 1);
    } else {
        return recursiveBinarySearch(arr, target, mid + 1, high);
    }
}

// Iterative Binary Search
int iterativeBinarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Sequential Search
int sequentialSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Part 1: Static Data
    std::vector<int> data = {12, 5, 1, 19, 7, 3}; // Test data
    std::sort(data.begin(), data.end());  // Sort the vector

    int target1 = 7;  // An item that is in the list
    int target2 = 10; // An item that is not in the list

    // Recursive Binary Search
    int index = recursiveBinarySearch(data, target1, 0, data.size() - 1);
    std::cout << "Target " << target1 << " found at location " << index << std::endl;

    index = recursiveBinarySearch(data, target2, 0, data.size() - 1);
    std::cout << "Target " << target2 << " was not found, return value is " << index << std::endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(data, target1);
    std::cout << "Target " << target1 << " found at location " << index << std::endl;

    index = iterativeBinarySearch(data, target2);
    std::cout << "Target " << target2 << " was not found, return value is " << index << std::endl;

    // Sequential Search
    index = sequentialSearch(data, target1);
    std::cout << "Target " << target1 << " found at location " << index << std::endl;

    index = sequentialSearch(data, target2);
    std::cout << "Target " << target2 << " was not found, return value is " << index << std::endl;

    return 0;
}
