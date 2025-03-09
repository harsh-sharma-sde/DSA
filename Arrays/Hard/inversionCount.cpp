// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

#include <bits/stdc++.h>
using namespace std;

int merge(int left, int mid, int right, vector<int> &arr) {
    vector<int> temp;
    int inv = 0;
    
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {  // No inversion
            temp.push_back(arr[i]);
            i++;
        } else {
            inv += (mid - i + 1); // Count inversions
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return inv;
}

int mergeSort(int left, int right, vector<int> &arr) {
    int inv = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        inv += mergeSort(left, mid, arr);
        inv += mergeSort(mid + 1, right, arr);
        inv += merge(left, mid, right, arr);
    }

    return inv;
}

// Function to count inversions in the array.
int inversionCount(vector<int> &arr) {
    int n = arr.size();
    return mergeSort(0, n - 1, arr);
}

// Driver Code
int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Inversion Count: " << inversionCount(arr) << endl;
    return 0;
}
