#include <iostream>
#include <vector>

using namespace std;

/**
 * Linear Search Algorithm
 * 
 * Logic:
 * 1. Start from the leftmost element of the array and one by one compare 'x' with each element.
 * 2. If 'x' matches with an element, return the index.
 * 3. If 'x' doesn’t match with any of the elements, return -1.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int target = 110;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget to find: " << target << endl;

    int result = linearSearch(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
