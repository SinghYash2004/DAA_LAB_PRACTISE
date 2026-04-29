#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Binary Search Algorithm (Divide and Conquer)
 * 
 * Logic:
 * 1. Search a sorted array by repeatedly dividing the search interval in half.
 * 2. Begin with an interval covering the whole array.
 * 3. If the value of the search key is less than the item in the middle of the interval, 
 *    narrow the interval to the lower half. Otherwise, narrow it to the upper half.
 * 4. Repeatedly check until the value is found or the interval is empty.
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive.
 */

// Iterative Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (arr[mid] < target)
            low = mid + 1;
        // If target is smaller, ignore right half
        else
            high = mid - 1;
    }

    // Target not present in array
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget to find: " << target << endl;

    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
