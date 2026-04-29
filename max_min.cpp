#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Find Maximum and Minimum in an array using Divide and Conquer
 * 
 * Logic:
 * 1. Divide the array into two halves.
 * 2. Find the max and min in the left half and right half recursively.
 * 3. Compare the max of both halves to get the global max.
 * 4. Compare the min of both halves to get the global min.
 * 
 * Time Complexity: O(n) - uses approximately 3n/2 - 2 comparisons.
 * Space Complexity: O(log n) for recursion stack.
 */

struct Pair {
    int min;
    int max;
};

Pair getMinMax(const vector<int>& arr, int low, int high) {
    Pair minmax, left, right;
    int mid;

    // If there is only one element
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // If there are more than 2 elements
    mid = (low + high) / 2;
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    // Compare minimums of two parts
    if (left.min < right.min)
        minmax.min = left.min;
    else
        minmax.min = right.min;

    // Compare maximums of two parts
    if (left.max > right.max)
        minmax.max = left.max;
    else
        minmax.max = right.max;

    return minmax;
}

int main() {
    vector<int> arr = {1000, 11, 445, 1, 330, 3000};
    int n = arr.size();

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    Pair result = getMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << result.min << endl;
    cout << "Maximum element: " << result.max << endl;

    return 0;
}
