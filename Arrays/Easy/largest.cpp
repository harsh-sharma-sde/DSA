// Given an array arr[]. The task is to find the largest element and return it.

// Input: arr[] = [1, 8, 7, 56, 90]
// Output: 90
// Explanation: The largest element of the given array is 90.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> // For max function

using namespace std;

int largest(vector<int> &arr) {
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int main() {
    vector<int> arr = {10, 20, 15, 30, 5}; // Example array
    cout << "The largest element in the array is: " << largest(arr) << endl;
    return 0;
}
