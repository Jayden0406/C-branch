#include <iostream>
#include <vector>
#include <algorithm> // for sort

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
    // Test Data
    vector<int> data = {12, 7, 5, 8, 19, 2, 17};
    int target1 = 8;  // target that is in the list
    int target2 = 100; // target that is not in the list

    // Sorting the vector
    sort(data.begin(), data.end());

    // Output the sorted vector
    cout << "Sorted vector: ";
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Recursive Binary Search
    cout << "\nRecursive Binary Search:" << endl;
    int index = recursiveBinarySearch(data, target1, 0, data.size() - 1);
    if (index != -1) {
        cout << target1 << " found at location " << index << endl;
    } else {
        cout << target1 << " was not found, return value is " << index << endl;
    }

    index = recursiveBinarySearch(data, target2, 0, data.size() - 1);
    if (index != -1) {
        cout << target2 << " found at location " << index << endl;
    } else {
        cout << target2 << " was not found, return value is " << index << endl;
    }

    // Iterative Binary Search
    cout << "\nIterative Binary Search:" << endl;
    index = iterativeBinarySearch(data, target1);
    if (index != -1) {
        cout << target1 << " found at location " << index << endl;
    } else {
        cout << target1 << " was not found, return value is " << index << endl;
    }

    index = iterativeBinarySearch(data, target2);
    if (index != -1) {
        cout << target2 << " found at location " << index << endl;
    } else {
        cout << target2 << " was not found, return value is " << index << endl;
    }

    // Sequential Search
    cout << "\nSequential Search:" << endl;
    index = sequentialSearch(data, target1);
    if (index != -1) {
        cout << target1 << " found at location " << index << endl;
    } else {
        cout << target1 << " was not found, return value is " << index << endl;
    }

    index = sequentialSearch(data, target2);
    if (index != -1) {
        cout << target2 << " found at location " << index << endl;
    } else {
        cout << target2 << " was not found, return value is " << index << endl;
    }

    return 0;
}
