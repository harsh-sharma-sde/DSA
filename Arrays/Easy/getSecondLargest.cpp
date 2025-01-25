// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

// Note: The second largest element should not be equal to the largest element.

// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.

#include <iostream>
#include <vector>

using namespace std;

int getSecondLargest(vector<int> &arr) {
    int maxi = -1, smax = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxi) {
            smax = maxi;
            maxi = arr[i];
        } else if (arr[i] > smax && arr[i] < maxi) {
            smax = arr[i];
        }
    }

    return smax;
}

int main() {
    vector<int> arr = {10, 20, 20, 15, 30, 5}; // Example array
    int secondLargest = getSecondLargest(arr);
    
    if (secondLargest == -1) {
        cout << "There is no second largest element in the array." << endl;
    } else {
        cout << "The second largest element in the array is: " << secondLargest << endl;
    }

    return 0;
}


// getSecondLargest Logic:

// maxi keeps track of the largest element.
// smax keeps track of the second largest element.
// If a new maximum is found, the current maximum (maxi) becomes the second largest (smax).
// If the current element is less than the maximum but greater than the second largest, update smax.