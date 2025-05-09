#include <iostream>
#include <vector>
#include <algorithm>

int sequentialSearch(const std::vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) return i;
    }
    return -1;
}

int iterativeBinarySearch(const std::vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) return mid;
        else if (vec[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(const std::vector<int>& vec, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (vec[mid] == target) return mid;
    if (vec[mid] < target)
        return recursiveBinarySearch(vec, mid + 1, right, target);
    return recursiveBinarySearch(vec, left, mid - 1, target);
}

void testSearchAlgorithms() {
    std::vector<int> vec = {34, 7, 23, 32, 5, 62};
    std::sort(vec.begin(), vec.end());

    int target1 = 23; // in the list
    int target2 = 99; // not in the list

    std::cout << "Vector: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << "\n";

    int index;

    // Recursive
    index = recursiveBinarySearch(vec, 0, vec.size() - 1, target1);
    std::cout << "Recursive Binary Search: " << target1 << " found at location " << index << "\n";
    index = recursiveBinarySearch(vec, 0, vec.size() - 1, target2);
    std::cout << "Recursive Binary Search: " << target2 << " was not found, return value is " << index << "\n";

    // Iterative
    index = iterativeBinarySearch(vec, target1);
    std::cout << "Iterative Binary Search: " << target1 << " found at location " << index << "\n";
    index = iterativeBinarySearch(vec, target2);
    std::cout << "Iterative Binary Search: " << target2 << " was not found, return value is " << index << "\n";

    // Sequential
    index = sequentialSearch(vec, target1);
    std::cout << "Sequential Search: " << target1 << " found at location " << index << "\n";
    index = sequentialSearch(vec, target2);
    std::cout << "Sequential Search: " << target2 << " was not found, return value is " << index << "\n";
}

int main() {
    testSearchAlgorithms();
    return 0;
}
