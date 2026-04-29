#include <iostream>
#include <vector>

using namespace std;

/**
 * Quicksort Algorithm (Divide and Conquer)
 * 
 * Logic:
 * 1. Pick an element (pivot) from the array.
 * 2. Partition: Reorder the array so that all elements with values less than the pivot come before the pivot, 
 *    and all elements with values greater than the pivot come after it.
 * 3. Recursively apply the above steps to the sub-arrays.
 * 
 * Time Complexity: O(n log n) average, O(n^2) worst case.
 * Space Complexity: O(log n) for recursion stack.
 */

// Partition function using Lomuto partition scheme
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Main Quicksort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array (Quicksort): ";
    printArray(arr);

    return 0;
}
