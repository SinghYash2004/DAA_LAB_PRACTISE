#include <iostream>
#include <vector>

using namespace std;

/**
 * Insertion Sort Algorithm
 * 
 * Logic:
 * 1. Start from the second element (index 1).
 * 2. Compare the current element (key) with its predecessor.
 * 3. If the key is smaller than its predecessor, compare it to the elements before.
 * 4. Move the greater elements one position up to make space for the swapped element.
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original array: ";
    printArray(arr);

    insertionSort(arr);

    cout << "Sorted array (Insertion Sort): ";
    printArray(arr);

    return 0;
}
