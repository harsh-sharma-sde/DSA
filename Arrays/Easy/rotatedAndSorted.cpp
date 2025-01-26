// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

// edge case [1,2,1,2,3,4] false

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

bool check(vector<int>& nums) {
    int cnt = 0, edge = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if (i < nums.size() - 1 && nums[i + 1] < nums[i]) {
            if (cnt == 0) edge = nums[0];
            cnt++;
        }
    }

    if (cnt > 1 || edge < nums[nums.size() - 1]) return false;

    return true;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2}; // Example input
    if (check(nums)) {
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is not sorted and rotated." << endl;
    }
    return 0;
}

// Explanation:
// Logic of check Function:

// The function verifies if the array is sorted and rotated.
// cnt keeps track of the number of times an element violates the sorted order.
// If cnt > 1, it means the array is not sorted and rotated correctly.
// edge stores the first element of the array when the first order violation is found.
// If the last element of the array is greater than edge when cnt > 0, it means the rotation is invalid.
// Edge Cases:

// The array is already sorted but not rotated (valid).
// The array is rotated at one point and sorted otherwise (valid).
// The array has multiple rotation points or fails sorted order (invalid).
// int main():

// An example array is passed to the check function.
// The output specifies whether the array is sorted and rotated.
// Test Cases:
// Input: {3, 4, 5, 1, 2} → Output: "The array is sorted and rotated."
// Input: {1, 2, 3, 4, 5} → Output: "The array is sorted and rotated."
// Input: {2, 1, 5, 4, 3} → Output: "The array is not sorted and rotated."
