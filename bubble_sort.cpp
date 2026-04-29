#include <iostream>
#include <vector>

using namespace std;

/**
 * Bubble Sort Algorithm
 * 
 * Logic:
 * 1. Repeatedly swap adjacent elements if they are in the wrong order.
 * 2. After each pass, the largest element "bubbles up" to its correct position at the end.
 * 3. We use an 'optimized' version with a 'swapped' flag to stop if the array is already sorted.
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);

    cout << "Sorted array (Bubble Sort): ";
    printArray(arr);

    return 0;
}
