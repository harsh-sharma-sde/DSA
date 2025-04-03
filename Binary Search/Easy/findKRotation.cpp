// Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
// Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
// After 1st Rotation : [9, 2, 4, 6]
// After 2nd Rotation : [6, 9, 2, 4]

// Examples:

// Input: arr = [5, 1, 2, 3, 4]
// Output: 1
// Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.
// Input: arr = [1, 2, 3, 4, 5]
// Output: 0
// Explanation: The given array is not rotated.
// Expected Time Complexity: O(log(n))
// Expected Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1, mini = INT_MAX, pivot = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid]) {
            if (mini > arr[low]) {
                mini = arr[low];
                pivot = low;
            }
            low = mid + 1;
        } else {
            if (mini > arr[mid]) {
                mini = arr[mid];
                pivot = mid;
            }
            high = mid - 1;
        }
    }

    return pivot;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int rotations = findKRotation(arr);
    cout << "The array is rotated " << rotations << " times." << endl;
    
    return 0;
}
