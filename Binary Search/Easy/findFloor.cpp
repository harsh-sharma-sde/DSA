// Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.

// Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.

// Examples

// Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
// Output: 1
// Explanation: Largest number less than or equal to 5 is 2, whose index is 1.
// Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 11
// Output: 4
// Explanation: Largest Number less than or equal to 11 is 10, whose indices are 3 and 4. The index of last occurrence is 4.
// Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
// Output: -1
// Explanation: No element less than or equal to 0 is found. So, output is -1.

#include <iostream>
#include <vector>

using namespace std;

int findFloor(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, floor = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            floor = mid;  // Update floor index
            low = mid + 1; // Move right to find a larger value that is still ≤ x
        } else {
            high = mid - 1; // Move left
        }
    }

    return floor;
}

int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19}; // Sorted array
    int x;

    cout << "Enter the number: ";
    cin >> x;

    int floorIndex = findFloor(arr, x);
    
    if (floorIndex != -1)
        cout << "Floor of " << x << " is " << arr[floorIndex] << " at index " << floorIndex << endl;
    else
        cout << "No floor found for " << x << " in the array." << endl;

    return 0;
}
